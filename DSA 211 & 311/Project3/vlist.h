// <vlist.h>
// <Izaz> , <Tousif>
// <tizaz>

#ifndef VLIST_H
#define VLIST_H

#include "video.h"

class Vlist
{
public:
  Vlist() { m_head = NULL; }
  bool insert(string title, string url, string comment, float length, int rating);
  void print();
  void length();
  bool lookup(string title);
  bool remove(string title);
  ~Vlist();

private:
  class Node
  {
  public:
    Node(Video *video, Node *next)
    {
      m_video = video;
      m_next = next;
    }
    Video *m_video;
    Node *m_next;
  };
  Node *m_head;
};
#endif
