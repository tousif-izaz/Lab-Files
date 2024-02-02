#include "video.h"
#include <iostream>

Video::Video(string title, string url, string comment, float length, int rating)
{
    this->m_title = title;
    this->m_url = url;
    this->m_comment = comment;
    this->m_length = length;
    this->m_rating = rating;
}

void Video::print()
{
    string ratingPrint = "";
    for (int i = 0; i < this->m_rating; i++)
    {
        ratingPrint = ratingPrint + "*";
    }
    cout << m_title << ", " << m_url << ", " << m_comment << ", " << m_length << ", " << ratingPrint << endl;
}
bool Video::compareRatings(Video *otherVideo) {
    return this->m_rating < otherVideo->m_rating;
}
bool Video::compareLengths(Video *otherVideo) {
    return this->m_length > otherVideo->m_length;
}
bool Video::compareTitles(Video *otherVideo) {
    return this->m_title > otherVideo->m_title;
}
bool Video::compare(Video *otherVideo, string sort){
    if(sort == "rating") {
        return compareRatings(otherVideo);
    } else if (sort == "length") {
        return compareLengths(otherVideo);
    } else {
        return compareTitles(otherVideo);
    }
}
