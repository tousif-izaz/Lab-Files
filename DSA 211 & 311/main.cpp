#include <iostream>
#include "video.h"

using namespace std;


int main()
{
    const int MAX = 100;
    string sort;
    string title;
    string url;
    string comment;
    float length;
    int rating;
    int video_count = 0;
    Video *videos[MAX] = {NULL};
    getline(cin, sort);
    if (!(sort == "rating" || sort == "title" || sort == "length"))
    {
        cerr << sort << " is not a legal sorting method, giving up." << endl;
        return 1;
    }
    while (getline(cin, title))
    {
        getline(cin, url);
        getline(cin, comment);
        cin >> length;
        cin >> rating;
        cin.ignore();
        videos[video_count++] = new Video(title, url, comment, length, rating);
        if(video_count > MAX) {
            cerr << "Too many videos, giving up." << endl;
            return 1;
        }
    }
    for (int last = video_count -1; last>0 ; last--) {
        for (int cur = 0; cur<last ; cur++) {
            if(videos[cur]-> compare(videos[cur+1], sort)) {
                swap(videos[cur], videos[cur+1]);
            }
        }
    }
    for(int i = 0; i< video_count; i++) {
        videos[i]->print();
    }
    return 0;
}