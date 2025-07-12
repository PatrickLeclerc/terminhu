#pragma once
#include <string>
#include <iostream>

namespace utf
{
    std::u32string to_u32string(const std::string& utf8_str);
    size_t u32string_size(const std::string& utf8_str);
}
