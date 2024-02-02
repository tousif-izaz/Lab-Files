#include "bst.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    Bst bst;
    string command;
    while(cin>> command) {
        if(command == "echo") {
            string printline;
            cin.ignore();
            getline(cin, printline);
            cout << printline << endl;
        }
        else if(command == "insert") {
            string input;
            cin.ignore();
            getline(cin, input);
            if(!bst.insert(input)) {
                cerr << "insert <"<< input << "> failed. String already in tree." << endl;
            }
        }
        else if(command == "find") {
            string input;
            cin.ignore();
            getline(cin, input);
            if(bst.find(input)) {
                cout << "<"<< input << "> is in tree." << endl;
            } else {
                cout << "<"<< input << "> is not in tree." << endl;
            }
        }
        else if(command == "count") {
            cout << bst.getCount() << endl;
        }
        else if(command == "print") {
            vector<string> values;
            cout << "{" ;
            bst.dft(values);
            for(size_t i=0; i < values.size() - 1; i++) {
                cout << values[i] << ", ";
            }
            cout << values[values.size()-1];
            cout << "}" << endl;
        }
        else if(command == "breadth") {
            vector<string> values;
            cout << "{" ;
            bst.bft(values);
            for(size_t i=0; i < values.size() - 1; i++) {
                cout << values[i] << ", ";
            }
            cout << values[values.size()-1];
            cout << "}" << endl;
        }
        else if(command == "height") {
            cout << bst.getHeight() << endl;;
        }
        else if(command == "balanced") {
            if(bst.isBalanced()) {
                cout << "Tree is balanced." << endl;
            } else {
                cout << "Tree is not balanced." << endl;
            }
        }
        else if(command == "rebalance") {
            bst.rebalance();
        }
        else {
            cerr << "Illegal command <"<< command <<">." << endl;
            getline(cin, command);
            continue;
        }

    }
    return 0;
    
}
