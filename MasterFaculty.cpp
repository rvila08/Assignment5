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
  Faculty* deletedFac = facBST->deleteNode(f);
  if(deletedFac!=nullptr){
    deletedFac->rollbackCommand = 1; //insert in rollback is 1
    cout << "Deleted faculty member: " << deletedFac->facultyID << endl;
    insertRollback(deletedFac);
    return true;
  }
  else{
    return false;
  }
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

void MasterFaculty::writeToFile(TreeNode<Faculty*>* node,string fileName){
  if(node==NULL){
    return;
  }
  outputstream.open(fileName,std::ios_base::app);
  outputstream << node->key->facultyID << endl;
  outputstream << node->key->name << endl;
  outputstream << node->key->level << endl;
  outputstream << node->key->department << endl;
  outputstream.close();
  if(node->left!=NULL){
    writeToFile(node->left,fileName);
  }
  if(node->right!=NULL){
    writeToFile(node->right,fileName);
  }
}

void MasterFaculty::readInTree(string fileName){
  int ID = 0;
  string name = "";
  string level = "";
  string department = "";
  lineCount = 0;
  string line;
  fileStream.open(fileName);
  if(fileStream.is_open()){
    cout << "Reading file" << endl;
    while(getline(fileStream, line)){
      lineCount++;
      if(lineCount%4==1){
        ID = stoi(line);
      }
      if(lineCount%4==2){
        name = line;
      }
      if(lineCount%4==3){
        level = line;
      }
      if(lineCount%4==0){
        department = line;
        Faculty* newFac = new Faculty(ID,name,level,department);
        facBST->insert(newFac);
      }
    }
    cout << "Faculty members inserted into tree" << endl;
  }
  else{
    cout << "Faculty table file does not exist. Faculty members were not added to tree" << endl;
  }
}

void MasterFaculty::linkAdvisees(TreeNode<Student*>* node){
  if(node==NULL){
    return;
  }
  linkAdvisees(node->left);
  adviseeID = node->key->studentID;
  advisorID = node->key->advisorID;
  if(addAdvisee(adviseeID,advisorID)){
    cout << "Advisee ID: " << adviseeID << " added to Advisor: " << advisorID << endl;
  }
  else{
    cout << "Unable to add Advisee ID: " << adviseeID << " to a list" << endl;
  }
  linkAdvisees(node->right);
}
