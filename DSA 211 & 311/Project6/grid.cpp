#include "grid.h"
#include <iostream>
using namespace std;
Grid::Grid() {
    for(int i=0; i<COLS; i ++) {
        for(int j=0; j< ROWS; j++) {
            m_grid[i][j] = ' ';
        }
    }
}
void Grid::set(int x, int y, char c) {
    if(x >=0 && x < COLS && y>=0 && y<ROWS) {
        m_grid[x][y] = c;
    }
    
}
void Grid::print() {
    for(int i=0; i<COLS; i++) {
        for(int j=0; j< ROWS; j++) {
            cout << m_grid[i][j];
        }
        cout << endl;

    }
}