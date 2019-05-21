#include "text_dyn.hpp"
#include "graphics.hpp"
#include <iostream>
#include <vector>

using namespace genv;

text_dyn::text_dyn(int x, int y, int sx, int sy,std::vector<std::string> vec) : widget(x,y,sx,sy,vec){
    _focus=false;
    dyn_str=options[0];
}

void text_dyn::draw(){
    gout << color(180,180,180) << move_to(_x,_y) << box(_size_x,_size_y);
    gout << color(0,0,0) << move_to(_x+2,_y+2) << box(_size_x-4,_size_y-4);
    gout << color(255,255,255) << move_to(_x+5,_y+_size_y/2) << text(dyn_str);
    if (_focus) {
    gout << color(110,130,130) << move_to(_x,_y) << box(_size_x,_size_y);
    gout << color(0,0,0) << move_to(_x+2,_y+2) << box(_size_x-4,_size_y-4);
    gout << color(255,255,255) << move_to(_x+5,_y+_size_y/2) << text(dyn_str);
    }
}

void text_dyn::handle(event ev){
    /*
    if (ev.type == ev_key && ev.keycode == ' ') {
        _focus = !_focus;
    }
    */
    if (ev.type == ev_mouse && selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        if (_focus==false) dyn_str=dyn_str+'|';
        _focus = true;
    }
    if (ev.type == ev_mouse && !selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        if (_focus==true) dyn_str=dyn_str.substr(0,dyn_str.size()-1);
        _focus = false;
    }
    if (_focus) {
        if (ev.type == ev_key && ev.keycode >=32 && ev.keycode <=126){
            if (_size_y>dyn_str.length()*2){
                actual_char=ev.keycode;
                dyn_str=dyn_str.substr(0,dyn_str.size()-1);
                dyn_str+=actual_char;
                dyn_str=dyn_str+'|';
            }
        }
        if (ev.type == ev_key && ev.keycode ==key_backspace){
            if (dyn_str.length()>=2){
                dyn_str=dyn_str.substr(0,dyn_str.size()-2);
                dyn_str=dyn_str+'|';
            }
        }
        if (ev.type == ev_key && ev.keycode == key_enter){
           choosen=dyn_str;
           dyn_str=dyn_str.substr(0,dyn_str.size()-1);
           _focus=false;
        }
    }
}

bool text_dyn::in_focus(){
    return _focus;
}

std::string text_dyn::return_choosen(){
    return choosen;
}
