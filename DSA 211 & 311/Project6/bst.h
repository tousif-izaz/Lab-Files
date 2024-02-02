#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
using namespace std;

class Bst {
public:
  Bst();
  ~Bst();
  
  class Node {
  public:
    Node(string value) {
      m_value = value;
      m_left = nullptr;
      m_right = nullptr;
    }
    ~Node(){
      delete m_left;
      delete m_right;
    }
    string m_value;
    Node *m_left;
    Node *m_right;
  };
  void deleteHelper(Node* &node);
  // Insert value if it doesn't already exist in the tree.  Return true on success.
  bool insert(string value);
  bool insertHelper(Node** node, string value);
  // Return true if the given value exists in this Bst, otherwise false.
  bool find(string value);
  bool findHelper(Node* node, string value);
  // Depth-first, in-order traversal, returning values via a vector.
  void dft(vector<string> &values);
  void dftHelper(Node* node, vector<string> &values);
  // Breadth-first traversal, returning values via a vector.
  void bft(vector<string> &values);

  // Returns true if this tree is balanced (complete), otherwise, false.
  bool isBalanced();
  bool isBalancedHelper(Node* node);

  // Returns the height of this Bst.  Returns 0 if empty.
  int getHeight();
  int getHeightHelper(Node* node);

  // Rebalance this Bst.
  void rebalance();

  // Returns the number of values currently stored in this Bst.
  int getCount();
  void insertFromVector(vector<string> &values);
  void insertFromVectorHelper(vector<string> &values, int start, int end);
private:
  
  Node *m_root;
  int m_count;
};
#endif
