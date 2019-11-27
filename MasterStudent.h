#ifndef MasterStudent_H
#define MasterStudent_H

#include <iostream>
#include <fstream>
#include "BST.h"
#include "GenLinkedList.h"
#include "Student.h"

using namespace std;


class MasterStudent{
public:
  MasterStudent();
  ~MasterStudent();
  BST<Student*> *stuBST;
  ifstream fileStream;
  TreeNode<Student*>* findStu(int ID);
  void option1(TreeNode<Student*>* node);
  void printStudent(TreeNode<Student*>* node);
  bool option7(Student* newStu);
  bool option8(Student* newStu);
  GenLinkedList<Student*>* stuRollback;
  void insertRollback(Student* stu);
  void rollback();
  void writeToFile(TreeNode<Student*>* node,string fileName);
  void readInTree(string fileName);
  ofstream outputstream;
private:
  Student* newStu;
  int rollbackCommand;
  int count = 0;
  int lineCount;

};
#endif
