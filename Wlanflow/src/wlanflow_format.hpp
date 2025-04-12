#ifndef _H_WLANFLOW_FORMAT_
#define _H_WLANFLOW_FORMAT_


/* wlan frame types */
#define MGMT_FRAME "management"
#define CTRL_FRAME "control"
#define DATA_FRAME "data"

namespace wlanflow {
class WlanflowFormat {
    public:
        void set_timestamp(long long tt);
        void set_frame_type(std::string frame_type);
        void set_frame_subtype(std::string frame_subtype);
        void set_src_address(std::string src_address);
        void set_dst_address(std::string dst_address);
        void set_dbm_signal(int32_t dbm_signal);
        void set_signal_quality(int32_t signal_quality);
        void set_dbm_antenna(int32_t antenna);
        void set_db_signal(int32_t db_signal);
        void set_dbm_noise(int32_t dbm_noise);
        std::string serialize_to_json_string();
    
    private:
        long long m_timestamp = 0;
        std::string m_frame_type;
        std::string m_frame_subtype;
        std::string m_src_address;
        std::string m_dst_address;
        
        int32_t m_dbm_signal = 0;
        int32_t m_signal_quality = 0;
        int32_t m_antenna = 0;
        int32_t m_db_signal = 0;
        int32_t m_dbm_noise = 0;

        bool m_is_wps = false;
        std::string m_ssid;
        std::string m_encryption;
        std::string m_cipher;
        std::string m_auth;
};
}

#endif  /* _H_WLANFLOW_FORMAT_ */