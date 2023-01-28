
#ifndef MATH_UTIL_H
#define MATH_UTIL_H

namespace mathutil
{
    auto map = [](int val, int in_min, int in_max, int out_min, int out_max)
    {
        return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    };
}

#endif