#include <iostream>
#include <string>


double string_to_double(std::string str) {
    return std::stod(str);
}

int main() {
    std::cout << "Fraction Stitcher" << std::endl;

    std::string whole_part;
    std::cout << "Enter whole part:";
    std::cin >> whole_part;

    std::string fractional_part;
    std::cout << "Enter fractional part:";
    std::cin >> fractional_part;

    std::string result = whole_part + "." + fractional_part;

    double num = string_to_double(result);

    std::cout << "Composed number:" << num << std::endl;

}