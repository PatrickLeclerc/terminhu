#include "navigator.hpp"

Navigator::Navigator()
{
    std::vector<std::string> vs = {
        "tab0",
        "tab1",
        "tab2",
        "tab3",
        "tab4"
    };
    for(std::string s : vs){
        std::vector<std::string> c;
        c.push_back(s);
        for (int i = 0; i < 4; i++)
        {
            c.push_back(s + " " +std::to_string(i));
        }
        content.push_back(c);
    }
    tab_ptr = &content.front();
    content_ptr = &content.front().front();
}

Navigator::~Navigator()
{
}