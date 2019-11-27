#include "Faculty.h"
#include <iostream>

Faculty::Faculty(int facID, string n, string lvl, string dep){
  adviseeList = new GenLinkedList<int>();
  facultyID = facID;
  name = n;
  level = lvl;
  department = dep;
}

Faculty::Faculty(int facID){
  facultyID = facID;
}

Faculty::~Faculty(){

}


bool Faculty::operator==(Faculty* f){
  if(f->facultyID == this->facultyID){
    return true;
  }
  return false;
}

bool Faculty::operator<(Faculty* f){
  if(this->facultyID < f->facultyID){
    return true;
  }
  return false;
}

bool Faculty::operator>(Faculty* f){
  if(this->facultyID > f->facultyID){
    return true;
  }
  return false;
}

bool Faculty::operator!=(Faculty* f){
  if(f->facultyID == this->facultyID){
    return false;
  }
  return true;
}
