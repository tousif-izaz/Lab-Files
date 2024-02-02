#include "pqueue.h"
#include <iostream>

void PQueue::enqueue(Cust *cust, int priority)
{
    Node *newCust = new Node(cust, priority, nullptr);
    if (!head || priority < head->priority)
    {
        newCust->nextCustomer = head;
        head = newCust;
    }
    else
    {
        Node *curr = head;
        while (curr->nextCustomer && priority >= curr->nextCustomer->priority)
        {
            curr = curr->nextCustomer;
        }
        newCust->nextCustomer = curr->nextCustomer;
        curr->nextCustomer = newCust;
    }
}
bool PQueue::dequeue(Cust *&cust)
{
    if (!head)
    {
        return false;
    }
    Node *temp = head;
    cust = temp->customer;
    head = head->nextCustomer;
    delete temp;
    return true;
}
bool PQueue::isEmpty()
{
    return head == nullptr;
}
int PQueue::getSize()
{
    int size = 0;
    Node *curr = head;
    while (curr != nullptr)
    {
        curr = curr->nextCustomer;
        size++;
    }
    return size;
}
bool PQueue::getFirstPriority(int &priority)
{
    if (!head)
    {
        return false;
    }
    priority = head->priority;
    return true;
}