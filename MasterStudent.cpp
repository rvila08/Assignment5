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
    cout << "Deleted student: " << deletedStu->studentID << endl;
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

void MasterStudent::readInTree(string fileName){
  int ID = 0;
  string name = "";
  string level = "";
  string major = "";
  double gpa = 0.0;
  int advisorID = 0;
  lineCount = 0;
  string line;
  fileStream.open(fileName);
  if(fileStream.is_open()){
    cout << "Reading file" << endl;
    while(getline(fileStream, line)){
      lineCount++;
      if(lineCount%6==1){ //lst line on file
        ID = stoi(line);
      }
      if(lineCount%6==2){ //2nd line on file
        name = line;
      }
      if(lineCount%6==3){ //3rd line on file
        level = line;
      }
      if(lineCount%6==4){ //4th file on file
        major = line;
      }
      if(lineCount%6==5){
        gpa = stod(line); //5th line on file
      }
      if(lineCount%6==0){
        advisorID = stoi(line);
        Student* newStu = new Student(ID,name,level,major,gpa,advisorID); //6th line on file
        stuBST->insert(newStu);
      }
    }
    cout << "Students inserted into tree" << endl;
  }
  else{
    cout << "Student table file does not exist. Students were not added to tree" << endl;
  }
}

void MasterStudent::writeToFile(TreeNode<Student*>* node,string fileName){
  if(node==NULL){
    return;
  }
  outputstream.open(fileName,std::ios_base::app);
  outputstream << node->key->studentID << endl;
  outputstream << node->key->name << endl;
  outputstream << node->key->level << endl;
  outputstream << node->key->major << endl;
  outputstream << node->key->gpa << endl;
  outputstream << node->key->advisorID << endl;
  outputstream.close();
  if(node->left!=NULL){
    writeToFile(node->left,fileName); //call the left subtree
  }
  if(node->right!=NULL){
    writeToFile(node->right,fileName); //call the right subtree
  }
}
