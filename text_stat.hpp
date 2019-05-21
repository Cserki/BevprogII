#ifndef TEXT_STAT_HPP_INCLUDED
#define TEXT_STAT_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

class text_stat : public widget {
protected:
    bool _focus;
    std::string stat_str;
    std::vector<std::string> vec;
    std::string choosen;
public:
    text_stat(int x, int y, int sx, int sy, std::vector<std::string> vec);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool in_focus();
    std::string return_choosen();
};


#endif // TEXT_STAT_HPP_INCLUDED



