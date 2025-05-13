#include <vsomeip/vsomeip.hpp>
#include <iostream>
#include "common.hpp"

std::shared_ptr<vsomeip::application> app;

void on_sensor_data(vsomeip::message::ptr_t message) {
    auto payload = message->get_payload();
    std::vector<uint8_t> data(payload->get_data(), payload->get_data() + payload->get_length());

    std::cout << "Speed: " << (int)data[0] << " km/h, ";
    std::cout << "Temperature: " << (int)data[1] << "°C, ";
    std::cout << "Fuel Level: " << (int)data[2] << "%\n";
}

int main() {
    app = vsomeip::runtime::get()->create_application("DashboardClient");
    app->init();

    app->register_message_handler(SENSOR_SERVICE_ID, SENSOR_INSTANCE_ID, SENSOR_EVENT_ID, on_sensor_data);
    app->request_service(SENSOR_SERVICE_ID, SENSOR_INSTANCE_ID);
    app->subscribe(SENSOR_SERVICE_ID, SENSOR_INSTANCE_ID, SENSOR_EVENT_ID);

    app->start();
    return 0;
}
