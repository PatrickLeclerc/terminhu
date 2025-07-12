#include "utf.hpp"
#include <utf8.h>
#include <regex>
namespace utf
{
    std::string strip_ansi(const std::string& s) {
        static const std::regex ansi_regex("\x1B\\[[0-9;]*[mK]");
        return std::regex_replace(s, ansi_regex, "");
    }

    std::u32string to_u32string(const std::string& utf8_str) {
        std::u32string result;
        utf8::utf8to32(utf8_str.begin(), utf8_str.end(), std::back_inserter(result));
        return result;
    }
    
    size_t u32string_size(const std::string& utf8_str) {
        std::string clean = strip_ansi(utf8_str);
        std::u32string u32 = to_u32string(clean);
        return u32.size();
    }
}