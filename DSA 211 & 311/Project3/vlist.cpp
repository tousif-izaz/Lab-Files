// <vlist.cpp>
// <Izaz> , <Tousif>
// <tizaz>

#include "vlist.h"
#include "video.h"
#include <iostream>
using namespace std;

bool Vlist::insert(string title, string url, string comment, float length, int rating)
{
    // make variable toAdd to store the video object
    Node *toAdd = new Node(new Video(title, url, comment, length, rating), nullptr);
    // add a temp variable to traverse the array
    // if vlist is empty
    if (this->m_head == NULL)
    {
        this->m_head = toAdd;
    }
    // for adding to head
    else if (toAdd->m_video->getTitle() < m_head->m_video->getTitle())
    {
        toAdd->m_next = m_head;
        m_head = toAdd;
    }
    // loop to add to sorted list
    else
    {
        Node *temp = this->m_head;
        while (temp->m_next != nullptr && temp->m_next->m_video->getTitle() <= title)
        {
            if (temp->m_next->m_video->getTitle() == title)
            {
                return false;
            }
            temp = temp->m_next;
        }
        toAdd->m_next = temp->m_next;
        temp->m_next = toAdd;
    }
    return true;
}
void Vlist::print()
{
    Node *temp = this->m_head;
    while (temp != nullptr)
    {
        temp->m_video->print();
        temp = temp->m_next;
    }
}
void Vlist::length()
{
    Node *temp = this->m_head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->m_next;
    }
    cout << count << endl;
}
bool Vlist::lookup(string title)
{
    Node *temp = m_head;
    // traverse the list
    while (temp != nullptr)
    {
        if (temp->m_video->getTitle() == title)
        {
            temp->m_video->print();
            return true;
        }
        temp = temp->m_next;
    }
    return false;
    // cerr << "Title <" << title << "> not in list." << endl;
}
bool Vlist::remove(string title)
{
    Node *temp = m_head;
    if (m_head == nullptr)
    {
        return false;
    }
    if (m_head->m_video->getTitle() == title)
    {
        Node *temp = m_head;
        m_head = m_head->m_next;
        delete temp;
        return true;
    }
    while (temp->m_next != nullptr)
    {

        if (temp->m_next->m_video->getTitle() == title)
        {
            Node *prev = temp->m_next;
            temp->m_next = temp->m_next->m_next;
            delete prev;
            return true;
        }
        temp = temp->m_next;
    }
    return false;
    // cerr << "Title <" << title << "> not in list, could not delete."<< endl;
}
Vlist::~Vlist()
{
    while (m_head != nullptr)
    {
        Node *curr = m_head;
        m_head = m_head->m_next;
        delete curr;
    }
    delete m_head;
}