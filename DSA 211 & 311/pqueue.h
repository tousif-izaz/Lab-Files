#ifndef PQUEUE_H
#define PQUEUE_H
#include "cust.h"
#include <iostream>

class PQueue
{
private:
    class Node
    {

    public:
        Node(Cust *customer, int priority, Node *next) : customer(customer), priority(priority), nextCustomer(next){};
        Cust *customer;
        int priority;
        Node *nextCustomer;
    };
    Node *head;

public:
    PQueue() { head = nullptr; }
    void enqueue(Cust *cust, int priority);
    bool dequeue(Cust *&cust);
    bool isEmpty();
    int getSize();
    bool getFirstPriority(int &priority);
};

#endif