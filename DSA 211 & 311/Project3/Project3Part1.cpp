#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Trie {
private:
    class Node {
    public:
        Node* children[26];
        set<int> lines;

        Node() {
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
        ~Node() {
            for (int i = 0; i < 26; ++i) {
                delete children[i];
            }
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }
    ~Trie() {
        delete root;
        root = nullptr;
    }

    void insert(const string& word, int line) {
        Node* current = root;

        for (char ch : word) {
            ch = tolower(ch); 
            if (!current->children[ch - 'a']) {
                current->children[ch - 'a'] = new Node();
            }
            current = current->children[ch - 'a'];
        }

        current->lines.insert(line);
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
    void printIndexHelper(Node* node, string wordSoFar, map<string, set<int>>& wordFrequencies) {
        if (!node) {
            return;
        }

        for (int line : node->lines) {
            wordFrequencies[wordSoFar].insert(line);
        }

        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                printIndexHelper(node->children[i], wordSoFar + char('a' + i), wordFrequencies);
            }
        }
    }
};

int main() {
    Trie trie;

    string line;
    int lineNumber = 1;

    while (getline(cin, line)) {
        stringstream InputStream(line);
        string word;
        while (InputStream >> word) {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            trie.insert(word, lineNumber);
        }

        lineNumber++;
    }

    trie.printIndex();

    return 0;
}
