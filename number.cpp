#include "number.hpp"
#include "graphics.hpp"
#include "iostream"
#include <vector>
using namespace genv;

number::number(int x, int y, int sx, int sy,std::vector<std::string> vec) : widget(x,y,sx,sy,vec)
{
    _focus=false;
    _interv_min=stoi(options[0]);    ///min
    _interv_max=stoi(options[1]);    ///max
    _num=(_interv_max-_interv_min)/2;  ///start
    choosen=std::to_string(_num);  ///string of number
}

void number::draw(){
    ///box
    gout << color(180,180,180) << move_to(_x,_y) << box(_size_x,_size_y);
    gout << color(0,0,0) << move_to(_x+2,_y+2) << box(_size_x-4,_size_y-4);
    gout << color(180,180,180) << move_to(_x+_size_x-_size_x/5,_y) << box(_size_x/5,_size_y/2);
    gout << color(0,0,0) << move_to(_x+_size_x-_size_x/5+2,_y+2) << box(_size_x/5-4,_size_y/2-4);
    gout << color(180,180,180) << move_to(_x+_size_x-_size_x/5,_y+_size_y/2) << box(_size_x/5,_size_y/2);
    gout << color(0,0,0) << move_to(_x+_size_x-_size_x/5+2,_y+_size_y/2+2) << box(_size_x/5-4,_size_y/2-4);
    ///up
    gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y/8) << line_to(_x+_size_x-_size_x/20,_y+_size_y*3/8);
    gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y/8+1) << line_to(_x+_size_x-_size_x/20,_y+_size_y*3/8+1);
    gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y/8) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*3/8);
    gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y/8+1) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*3/8+1);
    ///down
    gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*7/8) << line_to(_x+_size_x-_size_x/20,_y+_size_y*5/8);
    gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*7/8+1) << line_to(_x+_size_x-_size_x/20,_y+_size_y*5/8+1);
    gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*7/8) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*5/8);
    gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*7/8+1) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*3/5+1);
    ///text
    gout << color(255,255,255) << move_to(_x+5,_y+_size_y/2+5) << text(choosen);
    if (_focus) {
        ///box
        gout << color(110,130,130) << move_to(_x,_y) << box(_size_x,_size_y);
        gout << color(0,0,0) << move_to(_x+2,_y+2) << box(_size_x-4,_size_y-4);
        gout << color(110,130,130) << move_to(_x+_size_x-_size_x/5,_y) << box(_size_x/5,_size_y/2);
        gout << color(0,0,0) << move_to(_x+_size_x-_size_x/5+2,_y+2) << box(_size_x/5-4,_size_y/2-4);
        gout << color(1110,130,130) << move_to(_x+_size_x-_size_x/5,_y+_size_y/2) << box(_size_x/5,_size_y/2);
        gout << color(0,0,0) << move_to(_x+_size_x-_size_x/5+2,_y+_size_y/2+2) << box(_size_x/5-4,_size_y/2-4);
        ///up
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y/8) << line_to(_x+_size_x-_size_x/20,_y+_size_y*3/8);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y/8+1) << line_to(_x+_size_x-_size_x/20,_y+_size_y*3/8+1);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y/8) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*3/8);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y/8+1) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*3/8+1);
        ///down
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*7/8) << line_to(_x+_size_x-_size_x/20,_y+_size_y*5/8);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*7/8+1) << line_to(_x+_size_x-_size_x/20,_y+_size_y*5/8+1);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*7/8) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*5/8);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*7/8+1) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*3/5+1);
        ///text
        gout << color(255,255,255) << move_to(_x+5,_y+_size_y/2+5) << text(choosen);
    }
}

void number::handle(event ev)
{
    if (ev.type == ev_key && ev.keycode==' ') {
        _focus = !_focus;
        if (_num>_interv_max){
            _num=_interv_max;
        }
        if (_num<_interv_min){
            _num=_interv_min;
        }
    }
    if (ev.type == ev_mouse && selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _focus = true;
    }
    if (ev.type == ev_mouse && !selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _focus = false;
        if (_num>_interv_max){
            _num=_interv_max;
            choosen=std::to_string(_num);
        }
        if (_num<_interv_min){
            _num=_interv_min;
            choosen=std::to_string(_num);
        }
    }
    if (_focus) {
        choosen=std::to_string(_num);
        /*
        if (ev.type == ev_key && ev.keycode >=48 && ev.keycode <=57){
            actual_char=ev.keycode;
            _num_str+=actual_char;
            _num=stoi(_num_str);
        }
        if (ev.type == ev_key && ev.keycode ==key_backspace){
            _num_str=_num_str.substr(0,_num_str.size()-1);
            _num=stoi(_num_str);
        }
        */
        if (ev.type == ev_key && ev.keycode ==key_up){
            _num++;

        }
        if (ev.type == ev_key && ev.keycode ==key_down){
            _num--;
        }
        if (ev.type == ev_key && ev.keycode ==key_pgup){
            _num+=10;
        }
         if (ev.type == ev_key && ev.keycode ==key_pgdn){
            _num-=10;
        }
        if (ev.type == ev_mouse && ev.pos_x>_x+_size_x-_size_x/5+2 && ev.pos_x<_x+_size_x-2 && ev.pos_y>_y+2 && ev.pos_y<_y+_size_y/2-2 && ev.button==btn_left){
            _num++;
        }
        if (ev.type == ev_mouse && ev.pos_x>_x+_size_x-_size_x/5+2 && ev.pos_x<_x+_size_x-2 && ev.pos_y>_y+_size_y/2+2 && ev.pos_y<_y+_size_y-2 && ev.button==btn_left){
            _num--;
        }

    }

}

bool number::in_focus(){
    return _focus;
}

std::string number::return_choosen(){
    return choosen;
}





