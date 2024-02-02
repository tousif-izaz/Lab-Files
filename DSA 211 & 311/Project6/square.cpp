#include "shape.h"
#include "square.h"
#include <iostream>

Square::Square(int x, int y, int size): Shape(y,x) {
    sz = size;
}

void Square::draw(Grid &grid) {
    for(int i=0; i<sz; i++) {
        grid.set(m_x, m_y + i, '*');
    }
    for(int i=1; i<sz; i++) {
            grid.set(m_x+i, m_y, '*');
            grid.set(m_x+i, m_y+sz-1, '*');
    }

    for(int i=0; i<sz; i++) {
        grid.set(m_x+sz-1, m_y + i, '*');
    }
    
}