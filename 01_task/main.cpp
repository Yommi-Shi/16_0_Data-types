#include <iostream>


int main() {
    std::cout << "Speedometer" << std::endl;

    float speed_value = 0.0;
    char speed_str[7];
    float speed_delta;

    do {
        std::cout << "Speed delta:";
        std::cin >> speed_delta;
        speed_value += speed_delta;
        if (speed_value < 0.0) {
            speed_value = 0.0;
        }
        if (speed_value > 150.0) {
            speed_value = 150.0;
        }

        std::sprintf(speed_str, " %.1f", speed_value);
        std::cout << "Speed:" << speed_str << std::endl;

    } while (speed_value > 0);

}