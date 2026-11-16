#include "analytics.h"
#include "my_random.h"

#include <iostream>
#include <cassert>

void check(double value) {
    int expected = static_cast<int>(std::round(value));
    int actual = analytics::round(value);
    std::cout << "round " << value << " -> expected " << expected << " actual " << actual << std::endl;
    assert(actual == expected);
    std::cout << "[OK]" << std::endl;
}

void test_edge_cases() {
    std::cout << "test_edge_cases:" << std::endl;
    check(0.0);
    check(0.1);
    check(0.49);
    check(0.5);
    check(1.0);
    check(-0.0);
    check(-0.1);
    check(-0.49);
    check(-0.5);
    check(-1.0);
    std::cout << "[OK]" << std::endl;
}

void test_random_numbers() {
    std::cout << "test_random_numbers:" << std::endl;
    MyRandom positive{1.0, 100.0};
    MyRandom negative{-100.0, -1.0};
    for (int i=0; i<10; ++i) {
        check(positive.get());
        check(negative.get());
    }
    std::cout << "[OK]" << std::endl;
}

int main(int argc, const char* argv[]) {
    std::cout << "libanalytics tests:" << std::endl;
    test_edge_cases();
    test_random_numbers();
    return 0;
}