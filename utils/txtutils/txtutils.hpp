#pragma once
#include "aart.hpp"
#include "ansi.hpp"
#include <vector>
#include <string>

namespace txtutils
{
    typedef struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;  
    } Color;

    typedef enum{
        center = 0,
        left,
        right
    } Alignment;

    void coltxt(std::string& s, const Color c);
    void coltxt(std::vector<std::string>& vs, const Color c);
    void colbck(std::string& s, const Color c);
    void colbck(std::vector<std::string>& vs, const Color c);
    void align(std::string& s,Alignment alig, int W);
    void align(AART& aa, Alignment alig, int W);
    void align(std::vector<std::string>& vs, Alignment alig, int W);
    std::string str(std::vector<std::string>& vs);
    
} // namespace txtutils
