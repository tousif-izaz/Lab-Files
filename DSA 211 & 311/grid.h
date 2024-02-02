// grid.h
// <Izaz, Tousif>
// <tizaz>

#ifndef GRID_H
#define GRID_H

static const int COLS = 24;
static const int ROWS = 60;


class Grid
{
    public:
    	Grid();
	    void set(int x, int y, char c);
	    void print();
    private:
    	char m_grid[COLS][ROWS];
};

#endif
