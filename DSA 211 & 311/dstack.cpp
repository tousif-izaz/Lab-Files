#include "dstack.h"
#include<iostream>


Dstack::Dstack() {
    head = nullptr;
}


void Dstack::push(double value) {
    Node* temp = new Node(value);
    temp->next = head;
    head = temp;
}
bool Dstack::pop(double &value) {
    if(head!=nullptr) {
        Node* temp = head;
        value = head->data;
        head = head->next;
        delete temp;
        return true;
    } else {
        return false;
    }

}
int Dstack::size() {
    int count = 0;
    Node* temp = head;
    while(temp!=nullptr) {
        temp= temp->next;
        count++;
    }
    return count;
}
bool Dstack::empty() {
    if(head==nullptr) {
    return true;
    }else return false;

}
Dstack::~Dstack() {   
    while(head != nullptr) {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}

