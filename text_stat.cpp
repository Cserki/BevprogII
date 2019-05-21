#include "text_stat.hpp"
#include "graphics.hpp"
#include <iostream>
#include <vector>

using namespace genv;

text_stat::text_stat(int x, int y, int sx, int sy,std::vector<std::string> vec) : widget(x,y,sx,sy,vec){
    _focus=false;
    stat_str=options[0];
}

void text_stat::draw(){
    gout << color(180,180,180) << move_to(_x,_y) << box(_size_x,_size_y);
    gout << color(0,0,0) << move_to(_x+2,_y+2) << box(_size_x-4,_size_y-4);
    gout << color(255,255,255) << move_to(_x+5,_y+_size_y/2) << text(stat_str);
}

void text_stat::handle(event ev){}


bool text_stat::in_focus(){
    return _focus;
}

std::string text_stat::return_choosen(){
    return choosen;
}

