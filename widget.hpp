#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>

class widget{
protected:
    int _x, _y, _size_x, _size_y;
    std::vector<std::string> options;
public:
    widget(int x, int y, int sx, int sy,std::vector<std::string> vec);
    virtual bool selected(int pos_x, int pos_y);
    virtual void draw()=0;
    virtual void handle(genv::event ev)=0;
    virtual std::string return_choosen()=0;
};

#endif // WIDGET_HPP_INCLUDED


