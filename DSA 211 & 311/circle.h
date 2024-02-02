#ifndef CIRCLE_H
#define CIRCLE_H


class Circle : public Shape
{
    public:
    	Circle(int x, int y);
    private:
        void draw(Grid &grid);
};

#endif