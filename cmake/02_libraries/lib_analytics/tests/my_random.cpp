#include "my_random.h"

static std::mt19937& create_gen() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return gen;
}

MyRandom::MyRandom(double from, double to) : dis(from, to) {
    
}

double MyRandom::get() {
    return dis(create_gen());
}
