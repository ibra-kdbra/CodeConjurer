#include <iostream>
#include <sys/time.h>
#include <time.h>
#include "wlanflow_capture.hpp"
#include "wlanflow_format.hpp"
using namespace Tins;
using namespace wlanflow;


void WlanflowCapture::run() {
    Sniffer sniffer(m_wlanflow_config.get_interface(), Sniffer::PROMISC);
    sniffer.set_filter(m_wlanflow_config.get_pcap_filter());
    sniffer.sniff_loop(process_packets);
}

bool WlanflowCapture::process_packets(const PDU& pdu) {
    //  check if packet is not wlan exit
    if (invalid_wlan_packet(pdu))
        return true;

    WlanflowFormat pkt;
    pkt.set_timestamp(get_current_timestamp());

    // get frame type and subtype
    auto frame_type = get_frame_type(pdu);
    pkt.set_frame_type(frame_type);
    
    auto frame_subtype = get_frame_subtype(pdu);
    pkt.set_frame_subtype(frame_subtype);

    // get packet src addr
    pkt.set_src_address(get_src_addr(frame_type, pdu));
    
    // get packet dst addr
    pkt.set_dst_address(get_dst_addr(frame_type, pdu));

    // get signals
    pkt.set_dbm_signal(get_dbm_signal(pdu));
    pkt.set_dbm_antenna(get_antenna(pdu));
    // pkt.set_signal_quality(get_signal_quality(pdu));
    // pkt.set_db_signal(get_db_signal(pdu));
    // pkt.set_dbm_noise(get_dbm_noise(pdu));

    // export data
    auto data = pkt.serialize_to_json_string();
    auto response = WlanflowExporter::export_capture(data);
    
    if(response)
        printf("%s\n", data.c_str());
    else
        printf("error exporting data ..\n");
    
    return true;
}

bool WlanflowCapture::invalid_wlan_packet(const PDU& pdu) {
  if (pdu.pdu_type() != PDU::PDUType::RADIOTAP)
    return true;
  return false;
}

std::string WlanflowCapture::get_frame_type(const PDU& pdu) {
  std::string frame_type("unknown");
  const Dot11 &frame = pdu.rfind_pdu<Dot11>();

  switch(int(frame.type())) {
    case Dot11::Types::MANAGEMENT:
      frame_type = MGMT_FRAME;
      break;

    case Dot11::Types::CONTROL:
      frame_type = CTRL_FRAME;
      break;

    case Dot11::Types::DATA:
      frame_type = DATA_FRAME;
      break;

    default:
      break;
  }
  return frame_type;
}

std::string WlanflowCapture::get_frame_subtype(const PDU& pdu) {
  std::string frame_sub_type("unknown");
  const Dot11 &frame = pdu.rfind_pdu<Dot11>();

  switch(int(frame.type())) {
    case Dot11::Types::MANAGEMENT:
      frame_sub_type = _get_mgmt_subtype(int(frame.subtype()));
      break;

    case Dot11::Types::CONTROL:
      frame_sub_type = _get_ctrl_subtype(int(frame.subtype()));
      break;

    case Dot11::Types::DATA:
      frame_sub_type = _get_data_subtype(int(frame.subtype()));
      break;

    default:
      break;
  }
  return frame_sub_type;
}

std::string WlanflowCapture::get_src_addr(std::string frame_type, const PDU& pdu) {
  std::string src_addr("unknown");

  if(frame_type == std::string(MGMT_FRAME)) {
    const Dot11ManagementFrame &data = pdu.rfind_pdu<Dot11ManagementFrame>();
    src_addr = data.addr2().to_string();
  }

  if(frame_type == std::string(CTRL_FRAME)) {
    const Dot11 &data = pdu.rfind_pdu<Dot11>();
    src_addr = _get_control_src_addr(int(data.subtype()), pdu);
  }

  if(frame_type == std::string(DATA_FRAME)) {
    const Dot11Data &data = pdu.rfind_pdu<Dot11Data>();
    src_addr = data.src_addr().to_string();
  }
  return src_addr;
}

std::string WlanflowCapture::get_dst_addr(std::string frame_type, const PDU& pdu) {
  std::string dst_addr("unknown");
  
  if(frame_type == std::string(MGMT_FRAME)) {
    const Dot11ManagementFrame &data = pdu.rfind_pdu<Dot11ManagementFrame>();
    dst_addr = data.addr1().to_string();
  }

  if(frame_type == std::string(CTRL_FRAME)) {
    const Dot11Control &data = pdu.rfind_pdu<Dot11Control>();
    dst_addr = data.addr1().to_string();
  }

  if(frame_type == std::string(DATA_FRAME)) {
    const Dot11Data &data = pdu.rfind_pdu<Dot11Data>();
    dst_addr = data.dst_addr().to_string();
  }
  return dst_addr;
}

int32_t WlanflowCapture::get_dbm_signal(const PDU& pdu) {
    int32_t dbm_signal = 0; 
  
    try {
        const RadioTap &radio_tap = pdu.rfind_pdu<RadioTap>();
        dbm_signal = (int32_t)radio_tap.dbm_signal();
    }
    catch(...) { 
        printf("error @ get_dbm_signal\n");
    }
    return dbm_signal;
}

int32_t WlanflowCapture::get_signal_quality(const PDU& pdu) {
    int32_t signal_quality = 0; 
  
    try {
        const RadioTap &radio_tap = pdu.rfind_pdu<RadioTap>();
        signal_quality = (int32_t)radio_tap.signal_quality();
    }
    catch(...) { 
        printf("error @ get_signal_quality\n");
    }
    return signal_quality;
}

int32_t WlanflowCapture::get_antenna(const PDU& pdu) {
    int32_t antenna = 0; 
  
    try {
        const RadioTap &radio_tap = pdu.rfind_pdu<RadioTap>();
        antenna = (int32_t)radio_tap.antenna();
    }
    catch(...) { 
        printf("error @ get_antenna\n");
    }
    return antenna;
}

int32_t WlanflowCapture::get_db_signal(const PDU& pdu) {
    int32_t db_signal = 0; 
  
    try {
        const RadioTap &radio_tap = pdu.rfind_pdu<RadioTap>();
        db_signal = (int32_t)radio_tap.db_signal();
    }
    catch(...) { 
        printf("error @ get_db_signal\n");
    }
    return db_signal;
}

int32_t WlanflowCapture::get_dbm_noise(const PDU& pdu) {
    int32_t dbm_noise = 0; 
  
    try {
        const RadioTap &radio_tap = pdu.rfind_pdu<RadioTap>();
        dbm_noise = (int32_t)radio_tap.dbm_noise();
    }
    catch(...) { 
        printf("error @ get_dbm_noise\n");
    }
    return dbm_noise;
}

long long WlanflowCapture::get_current_timestamp() {
  struct timeval tv;
  gettimeofday(&tv,NULL);
  long long aa = tv.tv_sec; 
  return tv.tv_sec;
}

std::string WlanflowCapture::_get_mgmt_subtype(int frame_byte) {
  std::string st("unknown");
  switch (frame_byte) {
  case Dot11::ManagementSubtypes::ASSOC_REQ:    st = "association_request"; break;
  case Dot11::ManagementSubtypes::ASSOC_RESP:   st = "association_reponse"; break;
  case Dot11::ManagementSubtypes::REASSOC_REQ:  st = "reassociation_request"; break;
  case Dot11::ManagementSubtypes::REASSOC_RESP: st = "reassociation_reponse"; break;
  case Dot11::ManagementSubtypes::PROBE_REQ:    st = "probe_request"; break;
  case Dot11::ManagementSubtypes::PROBE_RESP:   st = "probe_response"; break;
  case Dot11::ManagementSubtypes::BEACON:       st = "beacon"; break;
  case Dot11::ManagementSubtypes::ATIM:         st = "atim"; break;
  case Dot11::ManagementSubtypes::DISASSOC:     st = "disassociation"; break;
  case Dot11::ManagementSubtypes::AUTH:         st = "authentication"; break;
  case Dot11::ManagementSubtypes::DEAUTH:       st = "deauthentication"; break;
  default: break;
  }
  return st;
}

std::string WlanflowCapture::_get_ctrl_subtype(int frame_byte) {
  std::string st("unknown");
  switch (frame_byte) {
  case Dot11::ControlSubtypes::BLOCK_ACK_REQ:   st = "block_acknowlegde_request"; break;
  case Dot11::ControlSubtypes::BLOCK_ACK:       st = "block_acknowlegde"; break;
  case Dot11::ControlSubtypes::PS:              st = "ps"; break;
  case Dot11::ControlSubtypes::RTS:             st = "rts"; break;
  case Dot11::ControlSubtypes::CTS:             st = "cts"; break;
  case Dot11::ControlSubtypes::ACK:             st = "acknowlegde"; break;
  case Dot11::ControlSubtypes::CF_END:          st = "cf_end"; break;
  case Dot11::ControlSubtypes::CF_END_ACK:      st = "cf_end_acknowlegde"; break;
  default: break;
  }
  return st;
}

std::string WlanflowCapture::_get_data_subtype(int frame_byte) {
  std::string st("unknown");
  switch (frame_byte) {
  case Dot11::DataSubtypes::DATA_DATA:        st = "data_data"; break;
  case Dot11::DataSubtypes::DATA_CF_ACK:      st = "data_cf_ack"; break;
  case Dot11::DataSubtypes::DATA_CF_POLL:     st = "data_cf_poll"; break;
  case Dot11::DataSubtypes::DATA_CF_ACK_POLL: st = "data_cf_ack_poll"; break;
  case Dot11::DataSubtypes::DATA_NULL:        st = "data_null"; break;
  case Dot11::DataSubtypes::CF_ACK:           st = "cf_ack"; break;
  case Dot11::DataSubtypes::CF_POLL:          st = "cf_poll"; break;
  case Dot11::DataSubtypes::CF_ACK_POLL:      st = "cf_ack_poll"; break;
  case Dot11::DataSubtypes::QOS_DATA_DATA:    st = "qos_data_data"; break;
  case Dot11::DataSubtypes::QOS_DATA_CF_ACK:  st = "qos_data_cf_ack"; break;
  case Dot11::DataSubtypes::QOS_DATA_CF_POLL: st = "qos_data_cf_poll"; break;
  case Dot11::DataSubtypes::QOS_DATA_CF_ACK_POLL: st = "qos_data_cf_ack_poll"; break;
  case Dot11::DataSubtypes::QOS_DATA_NULL:    st = "qos_data_null"; break;
  default: break;
  }
  return st;
}

std::string WlanflowCapture::_get_control_src_addr(int frame_byte, const PDU& pdu) {
    std::string src_addr("unknown");

    if (frame_byte == Dot11::ControlSubtypes::BLOCK_ACK_REQ) {
        const Dot11BlockAckRequest &ctrl = pdu.rfind_pdu<Dot11BlockAckRequest>();
        src_addr = ctrl.target_addr().to_string();

    } else if (frame_byte == Dot11::ControlSubtypes::BLOCK_ACK) {
        const Dot11BlockAck &ctrl = pdu.rfind_pdu<Dot11BlockAck>();
        src_addr = ctrl.target_addr().to_string();

    } else if (frame_byte == Dot11::ControlSubtypes::PS) {
        const Dot11PSPoll &ctrl = pdu.rfind_pdu<Dot11PSPoll>();
        src_addr = ctrl.target_addr().to_string();

    } else if (frame_byte == Dot11::ControlSubtypes::RTS) {
        const Dot11RTS &ctrl = pdu.rfind_pdu<Dot11RTS>();
        src_addr = ctrl.target_addr().to_string();

    } else if (frame_byte == Dot11::ControlSubtypes::CTS) {
        src_addr = "ff:ff:ff:ff:ff:ff";

    } else if (frame_byte == Dot11::ControlSubtypes::ACK) {
        src_addr = "ff:ff:ff:ff:ff:ff";

    } else if (frame_byte == Dot11::ControlSubtypes::CF_END_ACK) {
        const Dot11EndCFAck &ctrl = pdu.rfind_pdu<Dot11EndCFAck>();
        src_addr = ctrl.target_addr().to_string();

    } else if (frame_byte == Dot11::ControlSubtypes::CF_END) {
        const Dot11CFEnd &ctrl = pdu.rfind_pdu<Dot11CFEnd>();
        src_addr = ctrl.target_addr().to_string();
    }
    return src_addr;
}