#include "termout.hpp"
#include "frame.hpp"
#include "aart.hpp"

TermOut::TermOut(const std::string& title, const std::vector<std::string>& info, const Navigator& nav, const std::string& ibuf) : title(title), info(info), nav(nav), ibuf(ibuf), W(80){}
std::vector<std::string> TermOut::box(std::vector<std::string> vs, int boxSz){
    std::vector<std::string> ret;
    std::string first = "";
    std::string last = "";
    std::string vs_str = "";
    txtutils::align(vs,txtutils::left,boxSz);
    for (std::string &s :vs){
        if(s == vs.front())
            vs_str += "│";
        else
            vs_str += "─┤";

        vs_str += s + "";
        if(s == vs.back())
            vs_str += "│";
        else
            vs_str += "├─";
        
        if(s == vs.back()){
            first += frame::h(frame::thin,frame::top,boxSz);
            last += frame::h(frame::thin,frame::bottom,boxSz);
        }
        else{
            first += frame::h(frame::thin,frame::top,boxSz) + "  ";
            last += frame::h(frame::thin,frame::bottom,boxSz) + "  ";
        }
    }
    ret.push_back(first);
    ret.push_back(vs_str);
    ret.push_back(last);
    return ret;
}
void TermOut::process(){
    // Prepare title
    AART aa(title);
    txtutils::align(aa.vs,txtutils::center,W);
    for (int i = 0; i < 6 ; i++) 
        txtutils::coltxt(aa.vs[i],palette[i]);
    frame::border(frame::fat,aa.vs);
    
    // Prepare info
    txtutils::align(info,txtutils::center,W);
    txtutils::coltxt(info, palette[palette.size() - 1]);
    frame::border(frame::fat,info);
    
    // Prepare tabs
    std::vector<std::string> tabs;
    for(std::vector<std::string> &t : nav.content){
        tabs.push_back(t.front());
        if(t.front() == nav.tab_ptr->front())
            txtutils::coltxt(tabs.back(),palette[0]);
    }

    std::vector<std::string> tab_boxes = box(tabs,10);
    txtutils::align(tab_boxes,txtutils::center,W);
    frame::border(frame::fat,tab_boxes);

    // Prepare content
    std::vector<std::string> content;
    for(std::string &c : *nav.tab_ptr)
        if(c != nav.tab_ptr->front()){
            content.push_back(c);
            if(&c == nav.content_ptr)
                txtutils::coltxt(content.back(),palette[0]);
        }
    txtutils::align(content,txtutils::left,W);
    //txtutils::coltxt(content, palette[palette.size() - 2]);
    frame::border(frame::fat,content);

    // output
    clear();
    std::cout << frame::h(frame::fat,frame::top,W) + "\r\n";
    std::cout << txtutils::str(aa.vs);
    std::cout << txtutils::str(info);
    std::cout << frame::h(frame::fat,frame::separator,W) + "\r\n";
    std::cout << txtutils::str(tab_boxes);
    std::cout << txtutils::str(content);
    std::cout << frame::h(frame::fat,frame::bottom,W) + "\r\n";
    std::cout << ibuf + "\r\n";
}
