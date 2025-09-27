#include <iostream>
#include <string>

enum Note
{
    DO = 1 << 0,
    RE = 1 << 1,
    MI = 1 << 2,
    FA = 1 << 3,
    SOL = 1 << 4,
    LA = 1 << 5,
    SI = 1 << 6
};

int main() {
    std::cout << "Mechanical piano" << std::endl;

    std::cout << "enter chord:";
    std::string chord;
    std::cin >> chord;

    int mask = 0;

    for (int i = 0; i < chord.length(); i++) {
        if (chord[i] >= '1' && chord[i] <= '7') {
            int idx = chord[i] - '1';
            int bit = 1 << idx;
            mask |= bit;
        } else {
            std::cerr << "Invalid character: " << chord[i] << std::endl;
        }
    }

    if (mask & DO) {
        std::cout << "DO" << std::endl;
    }
    if (mask & RE) {
        std::cout << "RE" << std::endl;
    }
    if (mask & MI) {
        std::cout << "MI" << std::endl;
    }
    if (mask & FA) {
        std::cout << "FA" << std::endl;
    }
    if (mask & SOL) {
        std::cout << "SOL" << std::endl;
    }
    if (mask & LA) {
        std::cout << "LA" << std::endl;
    }
    if (mask & SI) {
        std::cout << "SI" << std::endl;
    }

}


