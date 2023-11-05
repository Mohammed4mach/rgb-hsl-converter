#include "../headers/angle.h"

inline double radians2degrees(double radians)
{
    return radians * (180.0 / M_PI);
}

inline double degrees2radians(double degrees)
{
    return degrees * (M_PI / 180.0);
}

