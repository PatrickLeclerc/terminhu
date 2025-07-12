#include "termin.hpp"
#include <unistd.h>
#include <iostream>
#include <cctype>

class RawTermGuard {
    termios original{};
public:
    RawTermGuard() {
        tcgetattr(STDIN_FILENO, &original);
        termios raw = original;
        raw.c_lflag &= ~(ICANON | ECHO);
        raw.c_cc[VMIN] = 1;
        raw.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    }
    ~RawTermGuard() {
        tcsetattr(STDIN_FILENO, TCSANOW, &original);
    }
};

KeyEvt TermIn::process() {
    RawTermGuard guard;
    KeyEvt ret = ERR;
    while (true) {
        char c;
        if (read(STDIN_FILENO, &c, 1) < 1) continue;

        if (c == 27) { // ESC or start of escape sequence
            char seq[2];
            // Peek ahead to check for arrow keys or ESC
            if (read(STDIN_FILENO, &seq[0], 1) == 0) {
                ret = ESC;
                break; // ESC pressed alone
            }
            if (read(STDIN_FILENO, &seq[1], 1) == 0) continue;

            if (seq[0] == '[') {
                switch (seq[1]) {
                    case 'A': ret = UP; break;
                    case 'B': ret = DOWN; break;
                    case 'C': ret = RIGHT; break;
                    case 'D': ret = LEFT; break;
                    default: ret = ERR; break;
                }
            } else {
                ret = ERR;
            }
        } else if (c == 127) {
            ret = DEL;
        //}
        //else if (c == '\b') {
            buf.pop_back();
            ret = BS;
        }
        else if (c == '\r' || c == '\n') {
            ret = ENTER;
        } else if (iscntrl(c)) {
            ret = CTRL;
            ctrl = c;
        } else {
            buf += c;
            ret = ALPHA;
        }
        if(ret != ERR) return ret;
    }
    return ret;
}
