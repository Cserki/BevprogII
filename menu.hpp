#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include <vector>

class menu : public widget {
protected:
    bool _focus;
    bool show_menu;
    bool mov;
    int from,bars,act;
    std::vector<std::string> vec;
    std::string choosen;
public:
    menu(int x, int y, int sx, int sy,std::vector<std::string> vec);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool in_focus();
    std::string return_choosen();
};


#endif // MENU_HPP_INCLUDED


