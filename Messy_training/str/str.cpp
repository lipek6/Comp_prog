#include <iostream>

int main() {
    std::string age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << age << "\n"; // does not flush the buffer
    return 0;
}