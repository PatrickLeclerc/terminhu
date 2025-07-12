#include "term.hpp"
#include <cassert>

Term::Term() : title("HUHU") {
    std::string time = __DATE__;
    time += " - " ;
    time += __TIME__;
    info.push_back(time);
};

void Term::interpret(){
    KeyEvt evt = in.process();
    if(ERR==evt)return;

    std::string command = "";
    switch (evt){
        case ENTER: {
            command = in.buf;
            in.buf = "";
            if(command.size() !=0) title = command;
            if(command == "quit") assert(0);
            if(command == "exit") assert(0);
            break;
        }
        case LEFT: {
            if(nav.tab_ptr != &nav.content.front()){
                nav.tab_ptr--;
                nav.content_ptr = &(*nav.tab_ptr)[1];
            }
            break;
        }
        case RIGHT: {
            if(nav.tab_ptr != &nav.content.back()){
                nav.tab_ptr++;
                nav.content_ptr = &(*nav.tab_ptr)[1];
            }
            break;
        }
        case DOWN: {
            if(nav.content_ptr != &nav.tab_ptr->back())
                nav.content_ptr++;
            break;
        }      
        case UP: {
            if(nav.content_ptr != &(*nav.tab_ptr)[1]) // element 0 is the tab name
                nav.content_ptr--;
            break;
        }
        default: break;
    }
}

void Term::loop(){
    while (1)
    {
        interpret();
        TermOut out(title,info,nav,in.buf);
        out.process();
    }
}
