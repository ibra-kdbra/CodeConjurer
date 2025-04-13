
#include <string>
#include "wlanflow_config.hpp"
using namespace wlanflow;

void WlanflowConfig::set_interface(std::string interface) {
    m_interface = interface;
}

std::string WlanflowConfig::get_interface() {
    return m_interface;
}

void WlanflowConfig::set_debug(bool debug) {
    m_debug = debug;
}

bool WlanflowConfig::get_debug() {
    return m_debug;
}

void WlanflowConfig::set_name(std::string name) {
    m_name = name;
}

std::string WlanflowConfig::get_name() {
    return m_name;
}
    
void WlanflowConfig::set_zmq_conn_string(std::string zmq_conn_string) {
    m_zmq_conn_string = zmq_conn_string;
}

std::string WlanflowConfig::get_zmq_conn_string() {
    return m_zmq_conn_string;
}

void WlanflowConfig::set_pcap_filter(std::string pcap_filter) {
    m_pcap_filter = pcap_filter;
}

std::string WlanflowConfig::get_pcap_filter() {
    return m_pcap_filter;
}