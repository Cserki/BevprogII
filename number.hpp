#ifndef NUMBER_HPP_INCLUDED
#define NUMBER_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include <vector>

class number : public widget {
protected:
    bool _focus;
    int _num;
    int _interv_max,_interv_min;
    std::string actual_char;
    //std::vector<std::string> vec;
    std::string choosen;
public:
    number(int x, int y, int sx, int sy,std::vector<std::string> vec);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool in_focus() ;
    std::string return_choosen();
};


#endif // NUMBER_HPP_INCLUDED

