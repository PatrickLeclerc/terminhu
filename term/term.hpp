#pragma once

#include "txtutils.hpp"
#include "termout.hpp"
#include "termin.hpp"
#include "navigator.hpp"

class Term
{
private:
    TermIn in;
    void interpret();
    void feed();
public:
    std::string title;
    std::vector<std::string> info;
    Navigator nav; 
    Term();
    void loop();
};
