#pragma once
#include <string>
namespace ansi
{
    #define ESC(A) "\033[" #A "m"
    const std::string RST       = ESC(0);
    const std::string BOLD      = ESC(1);
    const std::string UDRLINE   = ESC(4);
    const std::string RST_TXT   = ESC(39);
    const std::string RST_BCK   = ESC(49);
    const std::string OVRLINE   = ESC(53);
    const std::string CLR       = "\u001b[2J\u001b[H";
    inline std::string coltxt(uint8_t R, uint8_t G, uint8_t B){
        std::string ret = "\033[38;2;";
        ret+= std::to_string(R) + ";";
        ret+= std::to_string(G) + ";";
        ret+= std::to_string(B) + "m";
        return ret;
    }
    inline std::string colbck(uint8_t R, uint8_t G, uint8_t B){
        std::string ret = "\033[48;2;";
        ret+= std::to_string(R) + ";";
        ret+= std::to_string(G) + ";";
        ret+= std::to_string(B) + "m";
        return ret;
    }
}