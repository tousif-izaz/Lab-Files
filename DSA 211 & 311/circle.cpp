#include "shape.h"
#include "circle.h"
#include <iostream>

Circle::Circle(int x, int y): Shape(y,x) {}

void Circle::draw(Grid &grid) {
    grid.set(m_x+0, m_y+1, 'o');
    grid.set(m_x+0, m_y+2, 'o');
    for(int i=1; i<3; i++) {
        grid.set(m_x+i, m_y, 'o');
        grid.set(m_x+i, m_y+3, 'o');
    }
    grid.set(m_x+3, m_y+1, 'o');
    grid.set(m_x+3, m_y+2, 'o');
    
}