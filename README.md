# vSomeIP Vehicle Sensor Streaming

This project simulates vehicle sensors (speed, temperature, fuel level) and streams data using vSomeIP.

## Features
✅ Simulated vehicle sensor data  
✅ Real-time event-based communication  
✅ vSomeIP-based interprocess communication  

## Setup
### Install Dependencies
```bash
sudo apt update
sudo apt install git cmake g++ libboost-all-dev

# Clone and Build

```bash
git clone https://github.com/fly-lynx/vsomeIP-1.git
cd vsomeIP-1
mkdir build && cd build
cmake ..
make

# Run the service
```bash
export VSOMEIP_CONFIGURATION=../config/vsomeip.json
./sensor_service &

#Run dashboard client
export VSOMEIP_CONFIGURATION=../config/vsomeip.json
./dashboard_client

