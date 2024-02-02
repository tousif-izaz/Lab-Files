using namespace std;

#include "course.h" 

Course::Course(string courseName, int courseCode, int roomNo) {
  this->courseName = courseName;
  this->courseCode = courseCode;
  this->roomNo = roomNo;
}

// example of how class methods are specified
void Course::print()
{
  cout << this->courseName << " " << this->courseCode << " at " << this->roomNo<<endl;
}
