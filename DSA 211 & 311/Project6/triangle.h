#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle : public Shape
{
    public:
    	Triangle(int x, int y);
    private:
        void draw(Grid &grid) override;
};

#endif