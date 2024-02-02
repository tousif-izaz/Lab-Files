#include "cust.h"
#include <iostream>

Cust::Cust(string name, bool robber, int arrival, int items)
{
    this->name = name;
    this->robber = robber;
    this->arrival = arrival;
    this->items = items;
}

void Cust::print(ostream &out)
{
    out << name << " " << (robber ? "robber" : "shopper")
        << " " << arrival << " " << items << endl;
}