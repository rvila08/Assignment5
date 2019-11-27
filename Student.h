#ifndef Student_H
#define Student_H

#include <iostream>

using namespace std;

class Student{
public:
  Student(int stuID, string n, string lvl, string maj, double gpaa, int adID);
  Student(int stuID);
  Student();
  ~Student();
  bool operator==(Student* s);
  bool operator>(Student* s);
  bool operator<(Student* s);
  bool operator!=(Student* s);
  int studentID;
  string name;
  string level;
  string major;
  double gpa;
  int advisorID;
  int rollbackCommand;
};
#endif
