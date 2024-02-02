#ifndef SQUARE_H
#define SQUARE_H


class Square : public Shape
{
    public:
    	Square(int x, int y, int size);
    private:
        void draw(Grid &grid) override;
        int sz;
};

#endif