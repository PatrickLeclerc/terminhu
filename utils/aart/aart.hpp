#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#define AART_CHAR_H 6

class AART
{
private:
    int get_char_idx(char c);
    std::string txt = "";
public:
    std::vector<std::string> vs = std::vector<std::string>(AART_CHAR_H);
    AART(){};
    AART(char c);
    AART(std::string s);
    int size();
    AART& operator=(AART rhs) noexcept
    {
        vs = rhs.vs;
        txt = rhs.txt;
        return *this;
    }
    AART& operator+=(const AART& rhs)
    {
        if (vs.size() != AART_CHAR_H || rhs.vs.size() != AART_CHAR_H){
            std::string err = "ERR in AART& operator+= ; rhs.sz:lhs.sz ; " + std::to_string(vs.size()) + ":" + std::to_string(rhs.vs.size());
            throw std::runtime_error(err);
        }
        for (int i = 0; i < AART_CHAR_H; i++)
            vs[i] += rhs.vs[i];
        return *this;
    }
    friend AART operator+(AART lhs, const AART& rhs)
    {
        lhs += rhs;
        return lhs; // use = op
    }
};
