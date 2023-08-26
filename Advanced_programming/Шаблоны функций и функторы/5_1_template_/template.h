#pragma once
#include <vector>
#include <cmath>

template <typename T>
T power (T &n)
{
    return n*n;
}

template<class T>
std::vector<T> Power (std::vector<T>&vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = pow(vec[i],2);
    }

    return vec;
}