#ifndef _H_WLANFLOW_CAPTURE_
#define _H_WLANFLOW_CAPTURE_

#include <tins/tins.h>
#include "wlanflow_config.hpp"
#include "wlanflow_format.hpp"
#include "wlanflow_exporter.hpp"
using namespace Tins;


namespace wlanflow {
class WlanflowCapture {
    public:
        WlanflowCapture (WlanflowConfig &wlanflow_config):  m_wlanflow_config(wlanflow_config) {
            WlanflowExporter::init(
                wlanflow_config.get_zmq_conn_string(), wlanflow_config.get_debug());
        };

        void run();

    private:
        static std::string get_frame_type(const PDU& pdu);
        static std::string get_frame_subtype(const PDU& pdu);
        static std::string get_src_addr(std::string frame_type, const PDU& pdu);
        static std::string get_dst_addr(std::string frame_type, const PDU& pdu);

        static int32_t get_dbm_signal(const PDU& pdu);
        static int32_t get_signal_quality(const PDU& pdu);
        static int32_t get_antenna(const PDU& pdu);
        static int32_t get_db_signal(const PDU& pdu);
        static int32_t get_dbm_noise(const PDU& pdu);

        static std::string _get_mgmt_subtype(int frame_byte);
        static std::string _get_ctrl_subtype(int frame_byte);
        static std::string _get_data_subtype(int frame_byte);
        static std::string _get_control_src_addr(int frame_byte, const PDU& pdu);

        static bool process_packets(const PDU& pdu);
        static bool invalid_wlan_packet(const PDU& pdu);
        static long long get_current_timestamp();
        
        WlanflowConfig m_wlanflow_config;
};
}
#endif