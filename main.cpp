#include "graphics.hpp"
#include "widget.hpp"
#include "number.hpp"
#include "menu.hpp"
#include "text_dyn.hpp"
#include "text_stat.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
using namespace genv;

const int XX=600;
const int YY=600;

void process(vector<widget*>& widgets) {
    event ev;
    int focus=-1;
    while(gin>>ev) {
        if (ev.type==ev_mouse && ev.button==btn_left){
            for (unsigned int i=0;i<widgets.size();i++){
                if (widgets[i]->selected(ev.pos_x, ev.pos_y)){
                        focus=i;
                }
            }
        }
        if (focus!=-1){
            widgets[focus]->handle(ev);
        }
        for (widget* w : widgets) {
            w->draw();
        }
        if (ev.type==ev_key && ev.keycode==115) {
            ofstream myfile;
            myfile.open ("saved.txt");
            for (unsigned int i=0;i<widgets.size();i++){
                myfile << widgets[i]->return_choosen() << ' ';
            }
            myfile.close();
        }
        if (ev.type==ev_key && ev.keycode==key_f1){
            widgets[4]->return_choosen();
        }
        gout << refresh;
    }
}


int main(){
    event ev;
    gout.open(XX,YY);
    gout << color(244,244,244) << move_to(0,0) << box(XX,YY);
    vector<widget*> w;
    ///
    vector<string> v1;
    v1.push_back("10");    ///min
    v1.push_back("100");    ///max
    ///
    vector<string> v2;
    v2.push_back("-20");    ///min
    v2.push_back("50");    ///max
    ///
    vector<string> v3;
    v3.push_back("3");  ///length of menu
    for (int i=-10;i<=30;i++){
            v3.push_back(std::to_string(i));
    }
    ///
    vector<string> v4;
    v4.push_back("3");  ///length of menu
    v4.push_back("alma");
    v4.push_back("kenyér");
    v4.push_back("asztal");
    v4.push_back("szék");
    v4.push_back("teknõs");
    v4.push_back("falafel");
    v4.push_back("csirke");
    ///
    vector<string> v5;
    v5.push_back("write here");
    ///
    vector<string> v6;
    v6.push_back("static");

    number* b1 = new number(10,10,200,50,v1);
    number* b2 = new number(230,10,150,40,v2);
    menu* b3 = new menu(10,70,200,40,v3);
    menu* b4 = new menu(250,70,150,40,v4); ///230,70
    text_dyn* b5 = new text_dyn(10,200,200,50,v5);
    text_stat* b6 = new text_stat(300,200,200,50,v6);

    w.push_back(b1);
    w.push_back(b2);
    w.push_back(b3);
    w.push_back(b4);
    w.push_back(b5);
    w.push_back(b6);
    //process(w);

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
        if (ev.type==ev_key && ev.keycode==115) {
            ofstream myfile;
            myfile.open ("saved.txt");
            for (unsigned int i=0;i<w.size();i++){
                myfile << w[i]->return_choosen() << ' ';
            }
            myfile.close();
        }
        if (ev.type==ev_key && ev.keycode==key_f1){
            v4.push_back(w[5]->return_choosen());
            for (int i=0;i<v4.size();i++){
                cout << v4[i] << endl;
            }
        }
        gout << refresh;
    }

    return 0;
}
