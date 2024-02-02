#include "bst.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
Bst::~Bst() {
    deleteHelper(m_root);

}
void Bst::deleteHelper(Node* &node) {
    if(node) {
        deleteHelper(node->m_left);
        deleteHelper(node->m_right);
        delete node;
        node = nullptr;
    }

    
}

Bst::Bst() {
    m_root = nullptr;
    m_count = 0;
}

bool Bst::insert(string value) {
    Node* toAdd = new Node(value);
    Node* curr = m_root;
    if(!m_root) {
        m_root = toAdd;
        m_count++;
        return true;
    }
    else 
    return insertHelper(&curr, value);
}
bool Bst::insertHelper(Node** node, string value) {
    if(!*node){
        m_count++;
        *node = new Node(value);
        return true;
    } 
    if((*node)->m_value == value) return false;
    if(value < (*node)->m_value) {
        return insertHelper(&((*node)->m_left), value);
    }
        
    else{
        return insertHelper(&((*node)->m_right), value);
    } 
}
bool Bst::find(string value) {
    Node* curr = m_root;
    return findHelper(curr, value);
}
bool Bst::findHelper(Node* node, string value) {
    if(!node) return false;
    if(node->m_value == value) return true;
    if(value < node->m_value) return findHelper(node->m_left, value);
    else return findHelper(node->m_right, value);
}
int Bst::getCount() {
    return m_count;
}

void Bst::dft(vector<string> &values) {
    Node* curr = m_root;
    dftHelper(curr, values);
}

void Bst::dftHelper(Node* node, vector<string> &values) {
    if(!node) return;
    dftHelper(node->m_left, values);
    values.push_back(node->m_value);
    dftHelper(node->m_right, values);
}
void Bst::bft(vector<string> &values) {
    queue<Node*> que;
    que.push(m_root);
    while(!que.empty()) {
        Node* curr = que.front();
        que.pop();
        values.push_back(curr->m_value);
        if(curr->m_left) {
            que.push(curr->m_left);
        }
        if (curr->m_right) {
            que.push(curr->m_right);
        }
    }
}
int Bst::getHeight() {
    Node* curr = m_root;
    return getHeightHelper(curr);
}
int Bst::getHeightHelper(Node* node) {
    if(!node) return 0;
    return 1 + max(getHeightHelper(node->m_left), getHeightHelper(node->m_right)) ;
}

bool Bst::isBalanced() {
    Node* curr = m_root;
    return isBalancedHelper(curr);

}
bool Bst::isBalancedHelper(Node* node) {
    if(!node) {
        return true;
    }
    return isBalancedHelper(node->m_left) && isBalancedHelper(node->m_right) && (abs(getHeightHelper(node->m_left) - getHeightHelper(node->m_right)) <= 1);
}
void Bst::rebalance() {
    vector<string> values;
    dft(values);
    deleteHelper(m_root);
    insertFromVector(values);
}
void Bst::insertFromVector(vector<string> &values) {
    int start = 0;
    int end = values.size()-1;
    insertFromVectorHelper(values, start, end);

}
void Bst::insertFromVectorHelper(vector<string> &values, int start, int end) {
    if(start<= end) {
        if(start == end) insert(values[start]);
        else {
                int mid = (start+end)/2;
                insert(values[mid]);
                insertFromVectorHelper(values, start, mid-1);
                insertFromVectorHelper(values, mid+1, end);
        }
    }
}
