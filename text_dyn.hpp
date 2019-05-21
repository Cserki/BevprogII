#ifndef TEXT_DYN_HPP_INCLUDED
#define TEXT_DYN_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

class text_dyn : public widget {
protected:
    bool _focus;
    std::string dyn_str;
    std::string actual_char;
    std::vector<std::string> vec;
    std::string choosen;
public:
    text_dyn(int x, int y, int sx, int sy, std::vector<std::string> vec);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool in_focus();
    std::string return_choosen();
};


#endif // TEXT_DYN_HPP_INCLUDED


