#include <iostream>

#include "arithmetics.h"
#include "analytics.h"

int main(int argc, const char* argv[]) {
    double value1 = 10.4;
    double value2 = 22.6;
    std::cout << value1 << " + " << value2 << " = " << arithmetics::add(value1, value2) << std::endl;
    std::cout << value1 << " - " << value2 << " = " << arithmetics::sub(value1, value2) << std::endl;
    int rounded1 = analytics::round(value1);
    int rounded2 = analytics::round(value2);
    std::cout << "rounded " << rounded1 << " " << rounded2 << std::endl;
    std::cout << rounded1 << " is " << (analytics::is_even(rounded1) ? "even" : "odd") << std::endl;
    std::cout << rounded2 << " is " << (analytics::is_even(rounded2) ? "even" : "odd") << std::endl;
    return 0;
}
