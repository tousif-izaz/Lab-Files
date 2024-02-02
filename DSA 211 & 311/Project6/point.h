#ifndef POINT_H
#define POINT_H
#include "shape.h"
#include<iostream>

class Point : public Shape{
    public:

        Point(int x, int y, char c);
    private:
        char ch;
        
        void draw(Grid &grid) override;  
        
};

#endif