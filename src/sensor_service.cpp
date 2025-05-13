#include <vsomeip/vsomeip.hpp>
#include <iostream>
#include <cstdlib>
#include "common.hpp"

std::shared_ptr<vsomeip::application> app;

void send_sensor_data() {
    int speed = rand() % 200;  // Simulate speed (0-200 km/h)
    int temp = rand() % 100;   // Simulate temperature (0-100°C)
    int fuel = rand() % 100;   // Simulate fuel level (0-100%)

    auto message = app->create_message();
    auto payload = vsomeip::runtime::get()->create_payload();

    std::vector<uint8_t> data = {static_cast<uint8_t>(speed), static_cast<uint8_t>(temp), static_cast<uint8_t>(fuel)};
    payload->set_data(data);
    message->set_payload(payload);

    app->notify(SENSOR_SERVICE_ID, SENSOR_INSTANCE_ID, SENSOR_EVENT_ID, payload);
}

int main() {
    app = vsomeip::runtime::get()->create_application("SensorService");
    app->init();
    
    app->offer_service(SENSOR_SERVICE_ID, SENSOR_INSTANCE_ID);
    app->offer_event(SENSOR_SERVICE_ID, SENSOR_INSTANCE_ID, SENSOR_EVENT_ID, {});

    while (true) {
        send_sensor_data();
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Send updates every second
    }

    app->start();
    return 0;
}
