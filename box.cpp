#include "box.hpp"
#include "graphics.hpp"
#include <iostream>
#include <vector>

using namespace genv;

ttt::ttt(int x, int y, int sx, int sy,std::vector<std::string> vec) : widget(x,y,sx,sy,vec){

    _focus=false;
    symbol=options[0];
}

void ttt::draw(){
    ///box
    gout << color(180,180,180) << move_to(_x,_y) << box(_size_x,_size_y);
    gout << color(0,0,0) << move_to(_x+2,_y+2) << box(_size_x-4,_size_y-4);
    if(_focus){
        gout << color(red,green,blue) << move_to(_x+4,_y+4) << box(_size_x-8,_size_y-8);
    }
}

void ttt::handle(event ev){
    if (ev.type == ev_mouse && selected(ev.pos_x, ev.pos_y)){
        gout << color(250,10,155) << move_to(_x+4,_y+4) << box(_size_x-8,_size_y-8);
    }
    if (ev.type == ev_mouse && selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _focus = true;
    }
    if(_focus){
        gout << color(red,green,blue) << move_to(_x+4,_y+4) << box(_size_x-8,_size_y-8);
    }
}


bool ttt::in_focus(){
    return _focus;
}

std::string ttt::return_choosen(){
   return symbol;
}

void ttt::szin(int r, int g, int b){
    red=r;
    green=g;
    blue=b;
}


