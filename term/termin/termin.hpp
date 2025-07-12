#pragma once
#include <termios.h>
#include <string>

typedef enum{
    ERR = -1,
    ESC = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    DEL,
    BS,
    ALPHA,
    CTRL,
    ENTER,
    QUIT
} KeyEvt;

class TermIn
{
public:
    std::string buf = ""; 
    char ctrl = 0; 
    TermIn(){};
    ~TermIn(){};
    KeyEvt process();
};

