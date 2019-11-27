#include "BST.h"
#include "MasterStudent.h"
#include "MasterFaculty.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  MasterStudent* studentTree = new MasterStudent();
  MasterFaculty* facultyTree = new MasterFaculty();
  
  cout << "Boats n hoes" << endl;
  bool programRunning = true;
  int userChoice = 0;

  while (programRunning)
  {
    cout << endl;
    cout << "/////////////////////////////////////////" << endl;
    cout << "Here are your options: (Enter the number of the option you'd like to choose )" << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    cout << "/////////////////////////////////////////" << endl;
    cin >> userChoice;

    if (userChoice == 1)
    {
      studentTree->option1(studentTree->stuBST->root);
    }

    else if (userChoice == 2)
    {
      facultyTree->option2(facultyTree->facBST->root);
    }

    else if (userChoice == 3)
    {
      int ID = 0;
      cout << "Enter Student's ID" << endl;
      cin >> ID;
      TreeNode<Student*>* stu = studentTree->findStu(ID);
      if(stu!=nullptr){
        studentTree->printStudent(stu);
      }
      else{
        cout << "Student does not exist in tree" << endl;
        continue;
      }
    }

    else if (userChoice == 4)
    {
      int ID = 0;
      cout << "Enter Faculty's ID" << endl;
      cin >> ID;
      TreeNode<Faculty*>* fac = facultyTree->findFac(ID);
      if(fac!=nullptr){
        facultyTree->printFaculty(fac);
      }
      else{
        cout << "Faculty does not exist in tree" << endl;
      }
    }

    else if (userChoice == 5)
    {
      int stuID = 0;
      cout << "Enter Student ID" << endl;
      cin >> stuID;
      TreeNode<Student*>* stu = studentTree->findStu(stuID);
      if(stu!=nullptr){
        TreeNode<Faculty*>* fac = facultyTree->findFac(stu->key->advisorID);
        if(fac!=nullptr){
          TreeNode<Faculty*>* fac = facultyTree->findFac(stu->key->advisorID);
          facultyTree->printFaculty(fac);
        }
        else{
          cout << "Faculty member does not exist in tree" << endl;
        }
      }
      else{
        cout << "Student doesn't exist in tree" << endl;
      }
    }

    else if (userChoice == 6)
    {
      int facID = 0;
      cout << "Enter faculty ID" << endl;
      cin >> facID;
      TreeNode<Faculty*>*fac1 = facultyTree->findFac(facID);
      if(fac1!=nullptr){
        cout <<"printing advisor list " << endl;
        for(int i=0;i<fac1->key->adviseeList->getSize();++i){
          studentTree->printStudent(studentTree->findStu(fac1->key->adviseeList->returnPos(i)));
        }
      }
      else{
        cout << "Could not find faculty member" << endl;
        continue;
      }
    }

    else if (userChoice == 7)
    {
      int ID = 0;
      string name = "";
      string level = "";
      std::string major = "";
      double GPA = 0.0;
      int advisorID = 0;
      cout << "Enter Student ID" << endl;
      cin >> ID;
      cout << "Enter Student name" << endl;
      cin >> name;
      cout << "Enter Student level" << endl;
      cin >> level;
      cout << "Enter Student major" << endl;
      cin.ignore();                 //https://www.quora.com/What-does-cin-getline-do-in-C++
      getline(cin, major);
      cout << "Enter Student GPA" << endl;
      cin >> GPA;
      cout << "Enter Student advisor ID" << endl;
      cin >> advisorID;
      Student* stu = new Student(ID,name,level,major,GPA,advisorID);
      cout << "Student created" << endl;
      studentTree->option7(stu);
      cout << "student inserted into the tree" << endl;
      TreeNode<Faculty*>* fac = facultyTree->findFac(stu->advisorID);
      if(fac!=nullptr){
        facultyTree->addAdvisee(ID,advisorID);
      }
      else{
        cout << "Faculty member does not exist. Could not add advisee to a list" << endl;
        continue;
      }
    }

    else if (userChoice == 8)
    {
      int ID = 0;
      cout << "Enter ID of student to be deleted" << endl;
      cin >> ID;
      Student* newStu = new Student(ID);
      if(studentTree->option8(newStu)){
        cout << "Student deleted." << endl;
      }
      else{
        cout << "Student does not exist in the tree" << endl;
      }
      delete newStu;
    }

    else if (userChoice == 9)
    {
      int ID = 0;
      string name = "";
      string level = "";
      string department = "";
      cout << "Enter faculty ID" << endl;
      cin >> ID;
      cout << "Enter faculty member name" << endl;
      cin >> name;
      cout << "Enter faculty member level" << endl;
      cin.ignore();                 //https://www.quora.com/What-does-cin-getline-do-in-C++
      getline(cin, level);
      cout << "Enter faculty member department" << endl;
      cin.ignore();                 //https://www.quora.com/What-does-cin-getline-do-in-C++
      getline(cin, department);
      Faculty* fac = new Faculty(ID,name,level,department);
      facultyTree->option9(fac);
    }

    else if (userChoice == 10)
    {
      int ID = 0;
      cout << "Enter ID of faculty member to be deleted" << endl;
      cin >> ID;
      Faculty* newFac = new Faculty(ID);
      if(facultyTree->option10(newFac)){
        cout << "Faculty member deleted." << endl;
      }
      else{
        cout << "Faculty member does not exist in the tree" << endl;
      }
      delete newFac;
    }

    else if (userChoice == 11)
    {
      int stuID = 0;
      int newFacID = 0;
      cout << "Enter student ID" << endl;
      cin >> stuID;
      cout << "Enter new Faculty advisor ID" << endl;
      cin >> newFacID;
      TreeNode<Student*>* stu = studentTree->findStu(stuID);
      if(stu!=nullptr){
        TreeNode<Faculty*>* fac = facultyTree->findFac(stu->key->advisorID);
        if(fac!=nullptr){
          if(facultyTree->removeAdvisee(stuID,fac)){
            cout << "Advisee removed from advisor list" << endl;
          }
          else{
            cout << "Advisee is not on a previous advisor list" << endl;
          }
          if(facultyTree->addAdvisee(stuID,newFacID)){
            cout << "Advisee added to existing faculty member" << endl;
          }
          else{
            cout << "Could not add advisee to new advisor list" << endl;
          }
        }
        else{
          cout << "Student's advisor does not exist" << endl;
        }
      }
      else{
        cout << "Student does not exist in tree" << endl;
        continue;
      }

      stu->key->advisorID = newFacID;
    }

    else if (userChoice == 12)
    {
      int stuID = 0;
      int facID = 0;
      cout << "Enter student ID" << endl;
      cin >> stuID;
      cout << "Enter faculty member's id. Student ID will be removed from this advisee list." << endl;
      cin >> facID;
      TreeNode<Faculty*>* fac = facultyTree->findFac(facID);
      if(fac!=nullptr){
        if(facultyTree->removeAdvisee(stuID,fac)){
          cout << "Advisee removed from advisor list" << endl;
        }
        else{
          cout << "Advisee not on the advisor list." << endl;
          cout << "command aborted" << endl;
          continue;
        }
      }
      else{
        cout << "Faculty member does not exist in tree" << endl;
      }
    }

    else if (userChoice == 13)
    {
      int input = -1;
      cout << "Would you like to rollback student(0) or faculty tree(1)?" << endl;
      cin >> input;
      if(input == 0 && studentTree->stuRollback->getSize()>0){
        studentTree->rollback();
      }
      else if(input == 1 && facultyTree->facRollback->getSize()>0){
        facultyTree->rollback();
      }
      else{
        cout << "Rollback unavailable" << endl;
      }
    }

    else if (userChoice == 14)
    {
      break;
    }
    else
    {
      cout << "Not a valid option!" << endl;
      break;
    }
  }
    //***********
    //IF A FIND STUDENT OR A FIND FACULTY == nulltr then continue in the while loop
    //***********
}
