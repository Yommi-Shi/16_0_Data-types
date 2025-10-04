#include <iostream>
#include <string>
#include <sstream>

enum switches
{
    LIGHTS_INSIDE = 1 << 0,
    LIGHTS_OUTSIDE = 1 << 1,
    HEATERS = 1 << 2,
    WATER_PIPE_HEATING = 1 << 3,
    CONDITIONER = 1 << 4
};


int main() {
    std::cout << "Smart home" << std::endl;

    int switches_state = 0;
    int indoorLightColorTemp = 5000;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 24; j++) {
            if (j < 10) {
                std::cout << "Time: " << "0" << j << ":00" << std::endl;
            } else {
                std::cout << "Time: " << j << ":00" << std::endl;
            }
            std::cout << "Temperature inside, temperature outside, movement, lights:" << std::endl;
            std::string buffer;
            std::stringstream buffer_stream(buffer);
            int temp_in, temp_out;
            std::string movement, lights;

            std::cin >> temp_in >> temp_out >> movement >> lights;
            buffer_stream << temp_in << temp_out << movement << lights;

            if (temp_out < 0) {
                if (!(switches_state & WATER_PIPE_HEATING)) {
                    std::cout << "WATER PIPE HEATING ON!" << std::endl;
                }
                switches_state |= WATER_PIPE_HEATING;
            } else if (temp_out > 5) {
                if (switches_state & WATER_PIPE_HEATING) {
                    std::cout << "WATER PIPE HEATING OFF!" << std::endl;
                }
                switches_state &= ~WATER_PIPE_HEATING;
            }

            bool movement_outside = (movement == "yes");

            if ((j > 16 || j < 5) && movement_outside) {
                if (!(switches_state & LIGHTS_OUTSIDE)) {
                    std::cout << "LIGHTS OUTSIDE ON!" << std::endl;
                }
                switches_state |= LIGHTS_OUTSIDE;
            } else {
                if (switches_state & LIGHTS_OUTSIDE) {
                    std::cout << "LIGHTS OUTSIDE OFF!" << std::endl;
                }
                switches_state &= ~LIGHTS_OUTSIDE;
            }

            if (temp_in < 22) {
                if (!(switches_state & HEATERS)) {
                    std::cout << "HEATERS ON!" << std::endl;
                }
                switches_state |= HEATERS;
            } else if (temp_in >= 25) {
                if (switches_state & HEATERS) {
                    std::cout << "HEATERS OFF!" << std::endl;
                }
                switches_state &= ~HEATERS;
            }

            if (temp_in >= 30) {
                if (!(switches_state & CONDITIONER)) {
                    std::cout << "CONDITIONER ON!" << std::endl;
                }
                switches_state |= CONDITIONER;
            } else if (temp_in <= 25) {
                if (switches_state & CONDITIONER) {
                    std::cout << "CONDITIONER OFF!" << std::endl;
                }
                switches_state &= ~CONDITIONER;
            }

            bool light_input = (lights == "on");

            if (light_input) {
                switches_state |= LIGHTS_INSIDE;
                if (j == 0) {
                    indoorLightColorTemp = 5000;
                    std::cout << "Color temperature:" << indoorLightColorTemp << "K" << std::endl;
                } else if (j >= 16 && j < 20) {
                    indoorLightColorTemp = indoorLightColorTemp - 575;
                    if (indoorLightColorTemp < 2700) {
                        indoorLightColorTemp = 2700;
                    }
                    std::cout << "Color temperature:" << indoorLightColorTemp << "K" << std::endl;
                } else {
                    std::cout << "Color temperature:" << indoorLightColorTemp << "K" << std::endl;
                }
            } else {
                switches_state &= ~LIGHTS_INSIDE;
            }
        }
    }

}