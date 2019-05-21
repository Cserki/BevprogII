#include "menu.hpp"
#include "graphics.hpp"
#include "iostream"
#include <vector>
using namespace genv;

menu::menu(int x, int y, int sx, int sy,std::vector<std::string> vec) : widget(x,y,sx,sy,vec)
{
    _focus=false;
    show_menu=false;
    from=0;     ///starting position of the elements
    bars=stoi(options[0]);    ///length of menu
    options.erase(options.begin());
    if (bars>options.size()) bars=options.size();
    choosen=options[0];    ///shown element
    act=-1;
    mov=true;
}

void menu::draw(){
    ///box
    gout << color(180,180,180) << move_to(_x,_y) << box(_size_x,_size_y);
    gout << color(0,0,0) << move_to(_x+2,_y+2) << box(_size_x-4,_size_y-4);
    gout << color(180,180,180) << move_to(_x+_size_x-_size_x/5,_y) << box(_size_x/5,_size_y);
    gout << color(0,0,0) << move_to(_x+_size_x-_size_x/5+2,_y+2) << box(_size_x/5-4,_size_y-4);
    ///down
    gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*2/3) << line_to(_x+_size_x-_size_x/20,_y+_size_y*1/3);
    gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*2/3+1) << line_to(_x+_size_x-_size_x/20,_y+_size_y*1/3+1);
    gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*2/3) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*1/3);
    gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*2/3+1) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*1/3+1);
    ///text
    gout << color(255,255,255) << move_to(_x+5,_y+_size_y/2) << text(choosen);
    if (_focus) {
        ///box
        gout << color(110,130,130) << move_to(_x,_y) << box(_size_x,_size_y);
        gout << color(0,0,0) << move_to(_x+2,_y+2) << box(_size_x-4,_size_y-4);
        gout << color(110,130,130) << move_to(_x+_size_x-_size_x/5,_y) << box(_size_x/5,_size_y);
        gout << color(0,0,0) << move_to(_x+_size_x-_size_x/5+2,_y+2) << box(_size_x/5-4,_size_y-4);
        ///down
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*2/3) << line_to(_x+_size_x-_size_x/20,_y+_size_y*1/3);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*2/3+1) << line_to(_x+_size_x-_size_x/20,_y+_size_y*1/3+1);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*2/3) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*1/3);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*2/3+1) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*1/3+1);
        ///text
        gout << color(255,255,255) << move_to(_x+5,_y+_size_y/2) << text(choosen);
    if (show_menu && _focus){
        ///box
        gout << color(110,130,130) << move_to(_x+_size_x-_size_x/5,_y) << box(_size_x/5,_size_y);
        gout << color(0,0,0) << move_to(_x+_size_x-_size_x/5+2,_y+2) << box(_size_x/5-4,_size_y-4);
        ///up
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*1/3) << line_to(_x+_size_x-_size_x/20,_y+_size_y*2/3);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*1/3+1) << line_to(_x+_size_x-_size_x/20,_y+_size_y*2/3+1);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*1/3) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*2/3);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y*1/3+1) << line_to((_x+_size_x)-_size_x*3/20,_y+_size_y*2/3+1);
    }
    ///text
    gout << color(255,255,255) << move_to(_x+5,_y+_size_y/2) << text(choosen);
    }
}

void menu::handle(event ev){
    if (ev.type == ev_key && ev.keycode == ' ') {
        _focus = !_focus;
        show_menu=false;
    }
    if (ev.type == ev_mouse && selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _focus = true;
    }

    if (ev.type == ev_mouse && ev.pos_x>_x+_size_x-_size_x/5+2 && ev.pos_x<_x+_size_x-2 && ev.pos_y>_y+2 && ev.pos_y<_y+_size_y-2 && ev.button==btn_left){
        show_menu=!show_menu;
    }
    if (_focus) {
        if (ev.type == ev_mouse && !selected(ev.pos_x, ev.pos_y) && ev.button==btn_left && show_menu==false){
        _focus = false;
    }
        }
    if (show_menu==false) gout << color(244,244,244) << move_to(_x,_y+_size_y) << box(_size_x,bars*_size_y);


    if (show_menu){/*
        if (ev.type == ev_mouse && ev.button==btn_left && !(ev.pos_x <_x && ev.pos_x > _x+_size_x-_size_x/5 && ev.pos_y <_y  &&  ev.pos_y > _y+bars*_size_y)){
            show_menu=false;
            _focus=false;
            std::cout << "piff";
        }*/

        //std::cout << options.size();
        gout << color(110,130,130) << move_to(_x,_y+_size_y) << box(_size_x-_size_x/5,bars*_size_y);
        /*///scroll_up
        gout << color(180,180,180) << move_to(_x+_size_x-_size_x/5,_y+_size_y) << box(_size_x/5,_size_x/5);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y+(_size_x/5)*1/3) << line_to(_x+_size_x-_size_x/20,_y+_size_y+(_size_x/5)*2/3);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+_size_y+(_size_x/5)*1/3) << line_to(_x+_size_x-_size_x*3/20,_y+_size_y+(_size_x/5)*2/3);
        ///scroll_down
        gout << color(180,180,180) << move_to(_x+_size_x-_size_x/5,_y+(bars+1)*_size_y-_size_y/2) << box(_size_x/5,_size_x/5);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+(bars+1)*_size_y-_size_y/2+(_size_x/5)*2/3) << line_to(_x+_size_x-_size_x/20,_y+(bars+1)*_size_y-_size_y/2+(_size_x/5)*1/3);
        gout << color(255,255,255) << move_to(_x+_size_x-_size_x/10,_y+(bars+1)*_size_y-_size_y/2+(_size_x/5)*2/3) << line_to(_x+_size_x-_size_x*3/20,_y+(bars+1)*_size_y-_size_y/2+(_size_x/5)*1/3);
        */
        for (int i=0;i<bars;i++){
            gout << color(200,200,200) << move_to(_x+2,_y+_size_y+i*_size_y) << box(_size_x-_size_x/5-4,_size_y);
            gout << color(110,130,130) << move_to(_x+2,_y+_size_y+(i+1)*_size_y-1) << line(_size_x-_size_x/5-4,0);
            gout << color(0,0,0) << move_to(_x+2,_y+_size_y+i*_size_y+_size_y/2+3) << text(options[i+from]);
            if (ev.pos_x > _x && ev.pos_x < _size_x-_size_x/5 && ev.pos_y > _y+_size_y+i*_size_y && ev.pos_y < _y+_size_y+(i+1)*_size_y){
                mov=true;
                act=i;
                if (mov){
                    gout << color(0,200,0) << move_to(_x+2,_y+_size_y+i*_size_y) << box(_size_x-_size_x/5-4,_size_y-1);
                    gout << color(0,0,0) << move_to(_x+2,_y+_size_y+i*_size_y+_size_y/2+3) << text(options[i+from]);
                }
                if ((ev.type == ev_mouse && ev.button==btn_left)){
                    choosen=options[i+from];
                    show_menu=false;
                    _focus=false;
                    if (options.size()-bars>from) from=from+i;
                }
            }
            if (mov==false){
                gout << color(0,200,0) << move_to(_x+2,_y+_size_y+act*_size_y) << box(_size_x-_size_x/5-4,_size_y-1);
                gout << color(0,0,0) << move_to(_x+2,_y+_size_y+act*_size_y+_size_y/2+3) << text(options[act+from]);
            }
        }
        if (ev.type == ev_key && ev.keycode ==key_down){
            mov=false;
            if (options.size()-bars>from){
                if (act>bars-2) from++;
                else act++;
            }
        }
        if (ev.type == ev_key && ev.keycode ==key_up){
            mov=false;
            if (from>0 && act>-1){
                if (act==0) from--;
                else act--;
            }
        }
        if (ev.type == ev_mouse && ev.button==btn_wheelup){
            if (from>0) from--;
        }
         if (ev.type == ev_mouse && ev.button==btn_wheeldown){
            if (options.size()-bars>from) from++;
        }
        if(ev.type == ev_key && ev.keycode == key_enter){
            choosen=options[act+from];
            show_menu=false;
            _focus=false;
            act=-1;
            if (options.size()-bars>from) from=from-act;
        }

    }
    if (ev.type == ev_key && ev.keycode ==key_pgup){
        show_menu=false;
    }
    if (ev.type == ev_key && ev.keycode ==key_pgdn){
        show_menu=true;
    }

}

bool menu::in_focus(){
    return _focus;
}

std::string menu::return_choosen(){
    return choosen;
}
