cmake_minimum_required(VERSION 3.10)
project(vsomeip_vehicle_sensors)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED)
find_package(vsomeip REQUIRED)

include_directories(${Boost_INCLUDE_DIRS} ${VSOMEIP_INCLUDE_DIRS})

add_executable(sensor_service src/sensor_service.cpp src/common.hpp)
target_link_libraries(sensor_service vsomeip)

add_executable(dashboard_client src/dashboard_client.cpp src/common.hpp)
target_link_libraries(dashboard_client vsomeip)
