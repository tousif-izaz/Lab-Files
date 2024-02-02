#ifndef CUST_H
#define CUST_H
#include <iostream>
using namespace std;

class Cust
{
public:
    Cust(string name, bool robber, int arrival, int items);
    void print(ostream &out);
    string getName() {return name;}
    bool getRobber(){return robber;}
    int getArrival(){return arrival;}
    int getItems() {return items;} 

private:
    string name;
    bool robber;
    int arrival;
    int items;
};

#endif