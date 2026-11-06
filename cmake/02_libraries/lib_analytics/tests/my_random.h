#ifndef MY_RANDOM_H
#define MY_RANDOM_H

#include <random>

class MyRandom {
public:
    MyRandom(double from = 0.0, double to = 100.0);
    double get();
private:
    std::uniform_real_distribution<double> dis;
};

#endif // MY_RANDOM_H
