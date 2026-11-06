#include "analytics.h"
#include "my_random.h"

#include <iostream>
#include <cassert>

void test_positive_round() {
    MyRandom rand{1.0, 50.0};
    double value = rand.get();
    std::cout << "test_positive_round with value " << value << std::endl;
    int expected = static_cast<int>(std::round(value));
    int actual = analytics::round(value);
    std::cout << "expected " << expected << " actual " << actual << std::endl;
    assert(actual == expected);
    std::cout << "[OK]" << std::endl;
}

void test_negative_round() {
    MyRandom rand{-50.0, -1.0};
    double value = rand.get();
    std::cout << "test_negative_round with value " << value << std::endl;
    int expected = static_cast<int>(std::round(value));
    int actual = analytics::round(value);
    std::cout << "expected " << expected << " actual " << actual << std::endl;
    assert(actual == expected);
    std::cout << "[OK]" << std::endl;
}

void test_zero_round() {
    double value = 0.0;
    std::cout << "test_zero_round with value " << value << std::endl;
    int expected = value;
    int actual = analytics::round(value);
    std::cout << "expected " << expected << " actual " << actual << std::endl;
    assert(actual == expected);
    std::cout << "[OK]" << std::endl;
}

int main(int argc, const char* argv[]) {
    std::cout << "libanalytics tests:" << std::endl;
    test_positive_round();
    test_negative_round();
    test_zero_round();
    return 0;
}