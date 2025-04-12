#ifndef _H_WLANFLOW_EXPORTER_
#define _H_WLANFLOW_EXPORTER_

#include <string>

namespace wlanflow {
class WlanflowExporter {
    public:
        static void init(std::string zmq_conn_string, bool debug);
        static bool export_capture(std::string capture_data);

    private:
        bool m_connection = false;
        
};
}
#endif