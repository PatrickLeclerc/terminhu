#pragma once
#include <vector>
#include <string>

class Navigator
{
public:
    std::vector<std::string>* tab_ptr;
    std::string* content_ptr;
    std::vector<std::vector<std::string>> content;
    Navigator();
    ~Navigator();
};
