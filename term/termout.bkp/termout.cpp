#include "termout.hpp"
#include "frame.hpp"

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

void TermOut::update(std::string& t, std::vector<std::string>& i, std::vector<std::string>& ta, std::vector<std::string>& c, std::string& ib){
    title = AART(t);
    info = i;
    tabs = ta;
    content = c;
    ibuf = ib;
}

void TermOut::process(){
    // prepare tabs 
    std::vector<std::string> tab_boxes = box(tabs,10);
    std::cout << "start" << std::endl;
    for (std::string &i : tab_boxes)
    {
        std::cout << i << std::endl;
    }
    
    // align -> consider TermOut beeing created at each itteration
    txtutils::align(title,txtutils::center,W);
    txtutils::align(info,txtutils::center,W);
    txtutils::align(content,txtutils::left,W);
    txtutils::align(tab_boxes,txtutils::center,W);

    // color
    for (int i = 0; i < 6 ; i++) 
        txtutils::coltxt(title.vs[i],palette[i]);
    txtutils::coltxt(info, palette[palette.size() - 1]);
    txtutils::coltxt(content, palette[palette.size() - 2]);
    
    //// border
    frame::border(frame::fat,title.vs);
    frame::border(frame::fat,info);
    frame::border(frame::fat,tab_boxes);
    frame::border(frame::fat,content);
    
    // output
    clear();
    std::cout << frame::h(frame::fat,frame::top,W) + "\r\n";
    std::cout << txtutils::str(title.vs);
    std::cout << txtutils::str(info);
    std::cout << frame::h(frame::fat,frame::separator,W) + "\r\n";
    std::cout << txtutils::str(tab_boxes);
    std::cout << txtutils::str(content);
    std::cout << frame::h(frame::fat,frame::bottom,W) + "\r\n";
    std::cout << ibuf + "\r\n";
}
