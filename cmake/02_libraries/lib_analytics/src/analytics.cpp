#include "analytics.h"

namespace analytics {

int round(double value) {
    int integer_part = static_cast<int>(value);
    double frac_part = value - integer_part;
    if (value >= 0) {
        return frac_part >= 0.5 ? integer_part + 1 : integer_part;
    } else {
        return -frac_part >= 0.5 ? integer_part - 1 : integer_part;
    }
}

bool is_even(int value) {
    return value % 2 == 0;
}

}
