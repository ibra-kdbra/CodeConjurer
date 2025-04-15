# Wlanflow
Wireless traffic netflow-like exporter for IEEE 802.11 specifications.

Wlanflow collects and decode wireless packets into json format. 

Data is exported using zeromq pubsub to be consumed by applications that want 
to work with this data.

# Required libraries
libtins,
libpcap-dev

# Installation

## Install Libpcap-dev 
```
$ sudo apt install libcapstone-dev # for most Debian users
$ sudo pacman -S capstone # library bindings for arch. 
```

## Install Libtins
```
$ git clone https://github.com/mfontanini/libtins.git
$ cd libtins
$ mkdir build && cd build
$ cmake ../
$ make 
$ sudo make install
```

## Install Wlanflow
```
$ cd Wlanflow
$ make
```

# Usage

## Enable monitor mode for wireless interface 
```
$ sudo ifconfig wlan0 down
$ sudo iwconfig wlan0 mode monitor
$ sudo ifconfig wlan0 up
```

## Run wlanflow using created monitor mode interface
```
$ sudo ./bin/wlanflow --interface=wlan0 --debug
```

## Help
```
Usage: ./bin/wlanflow [-h|--help] -i|--interface value [-n|--name value] [-f|--pcap-filter value] [-z|--zmq-conn value] [-d|--debug] 
Options:
 -h, --help                       print this help
 -i, --interface value            Specify Interface
 -n, --name value                 Specify export name (optional [default=default])
 -f, --pcap-filter value          Specify pcap wlan filter (optional [default=wlan0])
 -z, --zmq-conn value             Specify zeromq connection (optional [default=tcp://*:70000])
 -d, --debug                      Specify debugging (optional)
```

# Exported Data 
```
{
  "antenna": 1, 
  "dbm_signal": -73, 
  "dst_address": "ff:ff:ff:ff:ff:ff", 
  "frame_subtype": "probe_request", 
  "frame_type": "management", 
  "src_address": "78:3a:ca:af:9a:b3", 
  "timestamp": "1524840861"
}
{
  "antenna": 1, 
  "dbm_signal": -75, 
  "dst_address": "10:3a:00:9c:3a:c5", 
  "frame_subtype": "acknowlegde", 
  "frame_type": "control", 
  "src_address": "ff:ff:ff:ff:ff:ff", 
  "timestamp": "1524841207"
}
{
  "antenna": 1, 
  "dbm_signal": -81, 
  "dst_address": "bc:76:70:66:de:90", 
  "frame_subtype": "acknowlegde", 
  "frame_type": "control", 
  "src_address": "ff:ff:ff:ff:ff:ff", 
  "timestamp": "1524842876"
}
```

# TODO
1. Export data using zeromq pubsub
