all: json wlanflow_format wlanflow_exporter wlanflow_capture wlanflow_config wlanflow

wlanflow: src/wlanflow.cc 
	g++ -o bin/wlanflow src/wlanflow.cc wlanflow_config.o wlanflow_exporter.o wlanflow_format.o \
	    wlanflow_capture.o json11.o -O3 -std=gnu++11 -lpthread -lzmq -ltins

wlanflow_config: src/wlanflow_config.cc 
	g++ -o wlanflow_config.o -c src/wlanflow_config.cc -std=gnu++11 

wlanflow_capture: src/wlanflow_capture.cc 
	g++ -o wlanflow_capture.o -c src/wlanflow_capture.cc -std=gnu++11 

wlanflow_exporter: src/wlanflow_exporter.cc 
	g++ -o wlanflow_exporter.o -c src/wlanflow_exporter.cc -std=gnu++11 

wlanflow_format: src/wlanflow_format.cc 
	g++ -o wlanflow_format.o -c src/wlanflow_format.cc -std=gnu++11 

json: src/json11/json11.cpp
	g++ -o json11.o -c src/json11/json11.cpp -std=gnu++11

clean:
	rm -f bin/wlanflow wlanflow_exporter.o wlanflow_capture.o wlanflow_config.o json11.o \
		wlanflow_format.o

