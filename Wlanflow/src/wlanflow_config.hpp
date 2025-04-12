#ifndef _H_WLANFLOW_CONFIG_
#define _H_WLANFLOW_CONFIG_

namespace wlanflow {
class WlanflowConfig  {
    public:
        void set_interface(std::string interface);
        std::string get_interface();

        void set_debug(bool debug);
        bool get_debug();

        void set_name(std::string name);
        std::string get_name();
        
        void set_zmq_conn_string(std::string zmq_conn_string);
        std::string get_zmq_conn_string();

        void set_pcap_filter(std::string pcap_filter);
        std::string get_pcap_filter();

    private:
        std::string m_interface;
        bool m_debug = false;
        std::string m_name  = "default";
        std::string m_zmq_conn_string = "tcp://*:70000";
        std::string m_pcap_filter = "wlan";

        std::string m_langtype;
};
}
#endif