#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class TernarySearchTree {
private:
    class Node {
    public:
        char data;
        Node* left;
        Node* middle;
        Node* right;
        set<int> lines;

        Node(char ch) : data(ch), left(nullptr), middle(nullptr), right(nullptr) {};
        ~Node() {
            delete left;
            delete middle;
            delete right;
        }
    };

    Node* root;

public:
    TernarySearchTree() {
        root = nullptr;
    }
    ~TernarySearchTree() {
        delete root;
        root = nullptr;
    }
    void insert(const string& word, int line) {
        root = insertHelper(root, word, 0, line);
    }

    void printIndex() {
        map<string, set<int>> wordFrequencies; 

        printIndexHelper(root, "", wordFrequencies);

        for (const auto& entry : wordFrequencies) {
            cout << entry.first << ": ";
            for (auto it = entry.second.begin(); it != entry.second.end(); ++it) {
                cout << *it;
                if (next(it) != entry.second.end()) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }

private:
    Node* insertHelper(Node* node, const string& word, size_t index, int line) {
        char ch = word[index];

        if (!node) {
            node = new Node(ch);
        }

        if (ch < node->data) {
            node->left = insertHelper(node->left, word, index, line);
        } else if (ch > node->data) {
            node->right = insertHelper(node->right, word, index, line);
        } else if (index < word.size() - 1) {
            node->middle = insertHelper(node->middle, word, index + 1, line);
        } else {
            node->lines.insert(line);
        }

        return node;
    }

    void printIndexHelper(Node* node, string wordSoFar, map<string, set<int>>& wordFrequencies) {
        if (!node) {
            return;
        }

        printIndexHelper(node->left, wordSoFar, wordFrequencies);

        for (int line : node->lines) {
            wordFrequencies[wordSoFar + node->data].insert(line);
        }

        printIndexHelper(node->middle, wordSoFar + node->data, wordFrequencies);
        printIndexHelper(node->right, wordSoFar, wordFrequencies);
    }
};

int main(int argc, char* argv[]) {
    TernarySearchTree tst;

    string line;
    int lineNumber = 1;

    while (getline(cin, line)) {
        stringstream InputStream(line);
        string word;
        while (InputStream >> word) {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            tst.insert(word, lineNumber);
        }

        lineNumber++;
    }

    tst.printIndex();

    return 0;
}
