#include "shape.h"
#include "triangle.h"
#include <iostream>

Triangle::Triangle(int x, int y): Shape(y,x) {}

void Triangle::draw(Grid &grid) {
    grid.set(m_x+0, m_y+2, '+');
    grid.set(m_x+1, m_y+1, '+');
    grid.set(m_x+1, m_y+3, '+');
    for(int i=0; i<5;i++) {
        grid.set(m_x+2, m_y+i, '+');
    }
}
