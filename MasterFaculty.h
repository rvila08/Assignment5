#ifndef MasterFaculty_H
#define MasterFaculty_H
#include <iostream>
#include <fstream>
#include "Faculty.h"
#include "BST.h"
#include "GenLinkedList.h"

using namespace std;

class MasterFaculty{

public:
  MasterFaculty();
  ~MasterFaculty();
  void printFaculty(TreeNode<Faculty*>* node);
  void option2(TreeNode<Faculty*>* node);
  void option6();
  void option9(Faculty* node);
  bool option10(Faculty* f);
  bool removeAdvisee(int ID, TreeNode<Faculty*>* fac);
  bool addAdvisee(int ID, int facID);
  void insertRollback(Faculty* fac);
  void rollback();
  void writeToFile(TreeNode<Faculty*>* node,string fileName);
  void readInTree(string fileName);
  BST<Faculty*> *facBST;
  TreeNode<Faculty*>* findFac(int ID);
  ifstream fileStream;
  GenLinkedList<Faculty*>* facRollback;
private:
  Faculty* newFac;
  ofstream outputstream;
  int lineCount;
};
#endif
