// Replace MY_CLASS and My_class with the actual class name

// Ensure this header file is only included once.
// Use all caps for these
#ifndef COURSE_H
#define COURSE_H

// Add any includes here (such as #include <iostream>)
#include<iostream>
using namespace std;


class Course
{
 public:
  Course(string courseName, int courseCode, int roomNo);
  // public member functions go here
  void print();
 private:
  string courseName;
  int courseCode;
  int roomNo;

}; // don't forget this ;

#endif
