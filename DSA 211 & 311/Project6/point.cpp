#include "shape.h"
#include "point.h"
#include<iostream>

Point:: Point(int x, int y, char c) : Shape(x,y){
    ch = c;
}

void Point::draw(Grid &grid){
    grid.set(m_y,m_x,ch);
} 