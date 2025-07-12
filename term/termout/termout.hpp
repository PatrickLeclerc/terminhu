#pragma once
#include "txtutils.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "navigator.hpp"

class TermOut
{
private:
    std::vector<txtutils::Color> palette = {
        {   0, 153,  76}, // banner  line 0
        {   0, 204, 102}, // banner  line 1
        {   0, 255, 128}, // banner  line 2
        {  51, 255, 153}, // banner  line 3
        { 108, 204, 178}, // banner  line 4
        { 153, 204, 204}, // banner  line 5
        {  51, 204, 178}, // info    lines
        { 153, 204, 153}  // content lines
    };
    std::vector<std::string> box(std::vector<std::string> vs, int boxSz);
    int W = 80;
    std::string title;
    std::vector<std::string> info;
    Navigator nav;
    std::string ibuf;
public:
    TermOut(const std::string& title, const std::vector<std::string>& info, const Navigator& nav, const std::string& ibuf);
    void clear(){std::cout << ansi::CLR << ansi::RST << std::endl;};
    void process();
};
