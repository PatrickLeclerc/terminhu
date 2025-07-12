#include "txtutils.hpp"
#include "utf.hpp"

namespace txtutils{
    void coltxt(std::string& s, const Color c){
        s = ansi::coltxt(c.r,c.g,c.b) + s + ansi::RST_TXT;
    }
    void coltxt(std::vector<std::string>& vs, const Color c){
        for (std::string& s : vs)
            coltxt(s,c);
    }
    void colbck(std::string& s, const Color c){
        s = ansi::colbck(c.r,c.g,c.b) + s + ansi::RST_BCK;
    }
    void colbck(std::vector<std::string>& vs, const Color c){
        for (std::string& s : vs)
            colbck(s,c);
    }

    void align(std::string& s,Alignment alig, int W){
        int ssz = utf::u32string_size(s);
        if(ssz == W) return;
        int L = 0;
        int R = 0;
        switch (alig)
        {
        case center:
            L = (W-ssz)/2;
            R = W-L-ssz;
            break;
        case left:
            R = W-ssz;
            break;
        case right:
            L = W-ssz;
            break;
        default:
            return;
        }
        s = std::string(L,' ') + s + std::string(R,' ');
    }
    void align(AART& aa, Alignment alig, int W){
        int ssz = aa.size();
        if(ssz == W) return;
        int L = 0;
        int R = 0;
        switch (alig)
        {
        case center:
            L = (W-ssz)/2;
            R = W-L-ssz;
            break;
        case left:
            R = W-ssz;
            break;
        case right:
            L = W-ssz;
            break;
        default:
            return;
        }
        std::string padL(L,' ');
        std::string padR(R,' ');
        for (std::string& s : aa.vs)
            s = padL + s + padR;
    }
    void align(std::vector<std::string>& vs, Alignment alig, int W){
        for (std::string& s : vs)
            align(s,alig,W);
    }

    std::string str(std::vector<std::string>& vs){
        std::string ret = "";
        for(std::string& s : vs){
            ret += s + "\r\n";
        }
        return ret;
    }
}