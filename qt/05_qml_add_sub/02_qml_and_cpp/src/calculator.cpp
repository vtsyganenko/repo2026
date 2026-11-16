#include "calculator.h"

Calculator::Calculator(QObject* parent) : QObject(parent) {
}

double Calculator::add(double val1, double val2) {
    return val1 + val2;
}

double Calculator::sub(double val1, double val2) {
    return val1 - val2;
}
