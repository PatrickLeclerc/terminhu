#pragma once
#include <vector>
#include <string>

namespace frame {

    typedef enum {
        LEFT = 0,
        RIGHT,
        MID
    } HPos;

    typedef enum {
        top = 0,
        bottom,
        separator
    } HType;

    struct FrameStyle {
        std::string TOP_L, TOP_R, TOP_T;
        std::string BOT_L, BOT_R, BOT_T;
        std::string H, V;
        std::string L_T, R_T, X;
    };

    // Predefined styles
    const FrameStyle thin = {
        "┌", "┐", "┬",
        "└", "┘", "┴",
        "─", "│",
        "├", "┤", "┼"
    };

    const FrameStyle fat = {
        "╔", "╗", "╦",
        "╚", "╝", "╩",
        "═", "║",
        "╠", "╣", "╬"
    };

    std::string hstr(const FrameStyle& style, HType type, HPos pos);
    std::string h(const FrameStyle& style, HType type, int W);
    void border(const FrameStyle& style, std::string& s);
    void border(const FrameStyle& style, std::vector<std::string>& vs);

} // namespace frame
