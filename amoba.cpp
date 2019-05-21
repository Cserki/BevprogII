#include "graphics.hpp"
#include "widget.hpp"
#include "number.hpp"
#include "menu.hpp"
#include "text_dyn.hpp"
#include "text_stat.hpp"
#include "box.hpp"
#include "amoba.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
using namespace genv;

void amoba::run(){
    event ev;
    bool play=false;
    string p1_name;
    string p2_name;
    int table_x;
    int table_y;
    if (play==false){
        gout.open(600,600);
        vector<widget*> w;

        vector<string> v1;
        v1.push_back("15");    ///min
        v1.push_back("30");    ///max
        ///
        vector<string> v2;
        v2.push_back("15");    ///min
        v2.push_back("30");    ///max
        ///
        vector<string> v3;
        v3.push_back("Player 1");

        vector<string> v4;
        v4.push_back("Player 2");

        vector<string> v5;
        v5.push_back("Press F1 to play");

        number* b1 = new number(10,60,100,50,v1);
        number* b2 = new number(120,60,100,50,v2);
        text_dyn* b3 = new text_dyn(10,120,100,50,v3);
        text_dyn* b4 = new text_dyn(120,120,100,50,v4);
        text_stat* b5 = new text_stat(10,10,200,30,v5);

        w.push_back(b1);
        w.push_back(b2);
        w.push_back(b3);
        w.push_back(b4);
        w.push_back(b5);

        int focus=-1;
        while(gin>>ev) {
            if (ev.type==ev_mouse && ev.button==btn_left){
                for (unsigned int i=0;i<w.size();i++){
                    if (w[i]->selected(ev.pos_x, ev.pos_y)){
                            focus=i;
                    }
                }
            }
            if (focus!=-1){
                w[focus]->handle(ev);
            }
            for (widget* v : w) {
                v->draw();
            }
            if (ev.type==ev_key && ev.keycode==key_f1){
                p1_name=w[2]->return_choosen();
                cout << p1_name;
                p2_name=w[3]->return_choosen();
                table_x=stoi(w[0]->return_choosen());
                table_y=stoi(w[1]->return_choosen());
                play=true;
                break;
            }
            gout << refresh;
        }
    }

    if (play==true){
        int meret=20;
        gout.open(table_x*meret+20,table_y*meret+meret+40);
        vector<widget*> w;
        vector<string> v1;
        v1.push_back(p1_name);
        vector<string> v2;
        v2.push_back(p2_name);
        text_stat* a1=new text_stat(10,10,100,30,v1);
        text_stat* a2=new text_stat(160,10,100,30,v2);
        w.push_back(a1);
        w.push_back(a2);

        vector<widget*> boxes;
        vector<string> v0;
        v0.push_back("");
        for (int i=0;i<table_x;i++){
            for (int j=0;j<table_y;j++){
                boxes.push_back(new ttt(10+i*meret,50+j*meret,meret,meret,v0));
            }
        }

        gout << color(20,200,50) << move_to(120,10) << box(30,30);
        gout << color(240,10,100) << move_to(270,10) << box(30,30);
        vector<int> p1;
        vector<int> p2;
        int act_pl=1;
        while(gin>>ev) {
            for (widget* v : w) {
                v->draw();
            }
            for (unsigned int i=0;i<boxes.size();i++){
                boxes[i]->draw();
                if (boxes[i]->selected(ev.pos_x, ev.pos_y) && ev.type==ev_mouse && ev.button==btn_left){
                    if (boxes[i]->in_focus()==false){
                        if (act_pl%2==0) boxes[i]->szin(240,10,100);
                        else boxes[i]->szin(20,200,50);
                        boxes[i]->handle(ev);
                        act_pl++;
                        if (act_pl%2==0) p1.push_back(i);
                        else p2.push_back(i);
                    }
                }
            }
            if (ev.type==ev_key && ev.keycode==key_f2){
                for (unsigned int i=0;i<p1.size();i++){
                    cout << p1[i] << ' ';
                }
                cout << endl;
                for (unsigned int i=0;i<p2.size();i++){
                    cout << p2[i] << ' ';
                }
                cout << endl;
            }
            gout << refresh;
        }
    }
}
