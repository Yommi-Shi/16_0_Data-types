#include <iostream>
#include <sstream>


int main() {
    std::cout << "Calculator" << std::endl;

    std::cout << "Enter an expression:";
    std::string buffer;
    std::cin >> buffer;

    std::stringstream buffer_stream(buffer);

    double num_one, num_two;
    char op;

    buffer_stream >> num_one >> op >> num_two;

    switch (op) {
        case '+': std::cout << buffer << "=" << num_one + num_two;
            break;
        case '-': std::cout << buffer << "=" << num_one - num_two;
            break;
        case '*': std::cout << buffer << "=" << num_one * num_two;
            break;
        case '/': std::cout << buffer << "=" << num_one / num_two;
            break;
        default: std::cout << "Invalid operator entered";
            break;
    }

}
