#pragma once
#include "txtutils.hpp"
#include "aart.hpp"
#include <vector>
#include <string>
#include <iostream>

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
    public:
    AART title;
    std::vector<std::string> info;
    std::vector<std::string> tabs;
    std::vector<std::string> content;
    std::string ibuf;
    TermOut(int W) : TermOut("TermOut", W){};
    TermOut(std::string title, int w) : title(title), W(w){};
    void clear(){std::cout << ansi::CLR << ansi::RST << std::endl;};
    void update(std::string& t, std::vector<std::string>& i, std::vector<std::string>& ta, std::vector<std::string>& c, std::string& ib);
    void process();
};
