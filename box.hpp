#ifndef TTT_HPP_INCLUDED
#define TTT_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

class ttt : public widget {
protected:
    int red,green,blue;
    bool _focus;
    std::string symbol;
public:
    ttt(int x, int y, int sx, int sy, std::vector<std::string> vec);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool in_focus();
    std::string return_choosen();
    virtual void szin(int r, int g, int b);
};


#endif // TTT_HPP_INCLUDED


