// <main.cpp>
// <Izaz> , <Tousif>
// <tizaz>
#include "vlist.h"
#include "video.h"
#include <iostream>
using namespace std;

void read_input(Vlist &vlist)
{
    string command;
    while (getline(cin, command))
    {
        if (command == "insert")
        {
            string title;
            string url;
            string comment;
            float length;
            int rating;
            getline(cin, title);
            getline(cin, url);
            getline(cin, comment);
            cin >> length;
            cin >> rating;
            cin.ignore();
            if (!vlist.insert(title, url, comment, length, rating))
            {
                cerr << "Could not insert video <" << title << ">, already in list." << endl;
            }
        }
        else if (command == "print")
        {
            vlist.print();
        }
        else if (command == "length")
        {
            vlist.length();
        }
        else if (command == "lookup")
        {
            string lookupTitle;
            getline(cin, lookupTitle);
            if (!vlist.lookup(lookupTitle))
            {
                cerr << "Title <" << lookupTitle << "> not in list." << endl;
            }
        }
        else if (command == "remove")
        {
            string removeTitle;
            getline(cin, removeTitle);
            if (!vlist.remove(removeTitle))
            {
                cerr << "Title <" << removeTitle << "> not in list, could not delete." << endl;
            }
        }
        else
        {
            cerr << "<" << command << "> is not a legal command, giving up." << endl;
            exit(1);
        }
    }
}
int main()
{
    Vlist *videoList = new Vlist();
    read_input(*videoList);
    return 0;
}