#include "MasterStudent.h"

using namespace std;

MasterStudent::MasterStudent(){
  stuBST = new BST<Student*>();
  stuRollback = new GenLinkedList<Student*>();

}

void MasterStudent::option1(TreeNode<Student*>* node){
  if(node == NULL){
    return;
  }
  option1(node->left);
  printStudent(node);
  option1(node->right);
}

void MasterStudent::printStudent(TreeNode<Student*>* node){
  Student* stu;
  stu = node->key;
  cout << "Student ID: " << stu->studentID << endl;
  cout << "Name: " << stu->name << endl;
  cout << "Level: " << stu->level << endl;
  cout << "Major: " << stu->major << endl;
  cout << "GPA: " << stu->gpa << endl;
  cout << "Faculty Advisor: " << stu->advisorID << endl;
  cout << endl;
}

bool MasterStudent::option7(Student* newStu){
  stuBST->insert(newStu);
  newStu->rollbackCommand = 0; // delete in rollback is 0
  insertRollback(newStu);
}

bool MasterStudent::option8(Student* newStu){
  Student* deletedStu = stuBST->deleteNode(newStu);
  if(deletedStu!=nullptr){
    deletedStu->rollbackCommand = 1; //insert in rollback is 1
    cout << deletedStu->studentID << endl;
    insertRollback(deletedStu);
    return true;
  }
  else{
    return false;
  }
}

TreeNode<Student*>* MasterStudent::findStu(int ID){
  newStu = new Student(ID);
  TreeNode<Student*>* stu = stuBST->search(newStu);
  return stu;
}

void MasterStudent::insertRollback(Student* stu){
  stuRollback->insertFront(stu);
  if(stuRollback->getSize()>5){
    cout << "Rollback size bigger than 5" << endl;
    stuRollback->deletePos(stuRollback->getSize()-1);
  }
}

void MasterStudent::rollback(){
  Student* stu = stuRollback->removeFront();
  if(stu->rollbackCommand == 0){
    stuBST->deleteNode(stu);
    cout << "Student with ID: " << stu->studentID << " deleted." << endl;
  }
  else if(stu->rollbackCommand == 1){
    stuBST->insert(stu);
    cout << "Student with ID: " << stu->studentID << " inserted." << endl;
  }
  else{
    cout << "Rollback command aborted." << endl;
  }
}
