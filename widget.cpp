#include "widget.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;

widget::widget(int x, int y, int sx, int sy,std::vector<std::string> vec) : _x(x), _y(y), _size_x(sx), _size_y(sy),options(vec){}

bool widget::selected(int pos_x, int pos_y){
    return pos_x>_x && pos_x<_x+_size_x && pos_y>_y && pos_y<_y+_size_y;
}
