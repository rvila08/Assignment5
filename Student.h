#ifndef Student_H
#define Student_H

#include <iostream>

using namespace std;

class Student{
public:
  Student(int stuID, string n, string lvl, string maj, double gpaa, int adID);
  Student();
  ~Student();
  bool operator=(Student s);
  bool operator>(Student s);
  bool operator<(Student s);
  bool operator!=(Student s);
  int studentID;
  string name;
private:
  string level;
  string major;
  double gpa;
  int advisorID;
};
#endif
