#include "GenLinkedList.h"
#include <iostream>

using namespace std;

class Faculty{
public:
  Faculty(int facID, string n, string lvl, string dep);
  Faculty(int facID);
  Faculty();
  ~Faculty();
  void removeAdvisee(int ID);
  bool operator==(Faculty *f);
  bool operator<(Faculty *f);
  bool operator>(Faculty *f);
  bool operator!=(Faculty *f);
  int facultyID;
  string name;
  string level;
  string department;
  GenLinkedList<int>* adviseeList;
  int rollbackCommand;
private:
};
