#include "frame.hpp"

namespace frame{

    std::string hstr(const FrameStyle& style, HType type, HPos pos) {
        switch (pos) {
            case LEFT:
                switch (type) {
                    case top: return style.TOP_L;
                    case bottom: return style.BOT_L;
                    case separator: return style.L_T;
                }
                break;
            case RIGHT:
                switch (type) {
                    case top: return style.TOP_R;
                    case bottom: return style.BOT_R;
                    case separator: return style.R_T;
                }
                break;
            case MID:
                return style.H;
        }
        return "";
    }

    std::string h(const FrameStyle& style, HType type, int W) {
        std::string ret;
        ret += hstr(style, type, LEFT);
        for (int i = 0; i < W; i++)
            ret += style.H;
        ret += hstr(style, type, RIGHT);
        return ret;
    }

    void border(const FrameStyle& style, std::string& s) {
        s = style.V + s + style.V;
    }

    void border(const FrameStyle& style, std::vector<std::string>& vs) {
        for (std::string& s : vs)
            border(style, s);
    }

}