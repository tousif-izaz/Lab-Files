// <video.h>
// <Izaz> , <Tousif>
// <tizaz>
#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
using namespace std;

class Video
{
private:
    string m_title;
    string m_url;
    string m_comment;
    float m_length;
    int m_rating;

public:
    void print();
    Video(string title, string url, string comment, float length, int rating);
    bool compareRatings(Video *otherVideo);
    bool compareLengths(Video *otherVideo);
    bool compareTitles(Video *otherVideo);
    bool compare(Video *otherVideo, string sort);
    string getTitle();
};
#endif