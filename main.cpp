#include "BST.h"
#include "Student.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  BST<Student*>* myBST = new BST<Student*>();
  Student* newStu = new Student(0,"Ricky","Sophomore","Data Analytics",4.0,1);
  Student* newStu1 = new Student(1,"Cait","Sophomore","Comp Sci",4.0,3);
  Student* newStu2 = new Student(2,"Sanya","Sophomore","Comp Sci",4.0,5);
  Student* newStu3 = new Student(5,"Rene","Sophomore","Comp Sci",4.0,5);
  myBST->insert(newStu);
  myBST->insert(newStu1);
  myBST->insert(newStu2);
  myBST->insert(newStu3);
  cout << "inserted students" << endl;
  cout << myBST->search(newStu3) << endl;
  //changed
  cout << "Boats n hoes" << endl;
}
