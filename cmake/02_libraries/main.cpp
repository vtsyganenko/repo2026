#include <iostream>

#include "arithmetics.h"

int main(int argc, const char* argv[]) {
    double value1 = 10.5;
    double value2 = 22.0;
    std::cout << value1 << " + " << value2 << " = " << arithmetics::add(value1, value2) << std::endl;
    std::cout << value1 << " - " << value2 << " = " << arithmetics::sub(value1, value2) << std::endl;
    return 0;
}
