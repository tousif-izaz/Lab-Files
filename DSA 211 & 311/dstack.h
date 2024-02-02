#ifndef DSTACK_H
#define DSTACK_H

#include <iostream>


class Dstack {
        private:
                class Node {
                    public:      
                        double data;
                        Node* next;
                        Node(double value) {
                            data = value;
                            next = nullptr;
                        }
                };
                Node* head;
        public:
                Dstack();
                void push(double value);
                bool pop(double &value);
                int size();
                bool empty();
                ~Dstack();


};
#endif
