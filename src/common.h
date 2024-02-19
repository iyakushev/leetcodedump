#pragma once
// io and formatting
#include <iostream>
#include <fmt/core.h>

// testing
#include <gtest/gtest.h>

// containers
#include <vector>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <queue>

// utils
#include <algorithm>
#include <functional>

template <typename It>
inline void display_it(It begin, It end)
{
    std::cout << "( ";
    while( begin != end )
        std::cout << *(begin++) << ", ";
    std::cout << " )";
}
