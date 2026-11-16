#ifndef ARITHMETICS_H
#define ARITHMETICS_H

// in windows, we need to export functions
#if defined(_WIN32)
    #if defined(ARITHMETICS_EXPORTS)
        #define ARITHMETICS_API __declspec(dllexport)
    #else
        #define ARITHMETICS_API __declspec(dllimport)
    #endif
#else
    #define ARITHMETICS_API
#endif

namespace arithmetics {
    ARITHMETICS_API double add(double a, double b);
    ARITHMETICS_API double sub(double a, double b);
}

#endif // ARITHMETICS_H