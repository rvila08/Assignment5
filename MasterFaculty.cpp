#include "MasterFaculty.h"

using namespace std;

MasterFaculty::MasterFaculty(){
  facBST = new BST<Faculty*>();
  facRollback = new GenLinkedList<Faculty*>();
}

void MasterFaculty::option2(TreeNode<Faculty*>* node){
  if(node == NULL){
    return;
  }
  option2(node->left);
  printFaculty(node);
  option2(node->right);
}

void MasterFaculty::printFaculty(TreeNode<Faculty*>* node){
  Faculty* fac;
  fac = node->key;
  cout << "Faculty ID: " << fac->facultyID << endl;
  cout << "Name: " << fac->name << endl;
  cout << "Level: " << fac->level << endl;
  cout << "Department: " << fac->department << endl;
  cout << endl;
}

void MasterFaculty::option9(Faculty* node){
  facBST->insert(node);
  node->rollbackCommand = 0;
  insertRollback(node);
}

TreeNode<Faculty*>* MasterFaculty::findFac(int ID){
  newFac = new Faculty(ID);
  TreeNode<Faculty*>* fac = facBST->search(newFac);
  return fac;
}

bool MasterFaculty::option10(Faculty* f){
  if(facBST->deleteNode(f)){
    return true;
    f->rollbackCommand = 1;
    insertRollback(f);
  }
  return false;
}

bool MasterFaculty::addAdvisee(int ID, int facID){
    TreeNode<Faculty*>* fac = findFac(facID);
    if(fac!=nullptr){
      fac->key->adviseeList->insertFront(ID);
      return true;
    }
    return false;
}

bool MasterFaculty::removeAdvisee(int ID, TreeNode<Faculty*>* fac){

  int pos = fac->key->adviseeList->find(ID);
  if(pos>0){
    fac->key->adviseeList->deletePos(pos);
    return true;
  }
  return false;
}

void MasterFaculty::rollback(){
  Faculty* fac = facRollback->removeFront();
  if(fac->rollbackCommand == 0){
    facBST->deleteNode(fac);
    cout << "Faculty member with ID: " << fac->facultyID << " deleted." << endl;
  }
  else if(fac->rollbackCommand == 1){
    facBST->insert(fac);
    cout << "Faculty member with ID: " << fac->facultyID << " inserted." << endl;
  }
  else{
    cout << "Rollback command aborted." << endl;
  }
}

void MasterFaculty::insertRollback(Faculty* fac){
  facRollback->insertFront(fac);
  if(facRollback->getSize()>5){
    facRollback->deletePos(facRollback->getSize());
  }
}
