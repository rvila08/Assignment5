#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(){

}

Student::Student(int stuID, string n, string lvl, string maj, double gpaa, int adID){
  studentID = stuID;
  name = n;
  level = lvl;
  major = maj;
  gpa = gpaa;
  advisorID = adID;
}

Student::Student(int stuID){
  studentID = stuID;
}

Student::~Student(){

}

bool Student::operator==(Student* s){
  if(s->studentID == this->studentID){
    return true;
  }
  return false;
}

bool Student::operator<(Student* s){
  if(this->studentID < s->studentID){
    return true;
  }
  return false;
}

bool Student::operator>(Student* s){
  if(this->studentID > s->studentID){
    return true;
  }
  return false;
}

bool Student::operator!=(Student* s){
  if(s->studentID == this->studentID){
    return false;
  }
  return true;
}
