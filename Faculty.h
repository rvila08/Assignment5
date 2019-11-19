#include <iostream>
#include "GenLinkedLists.h"

using namespace std;

class Faculty{
public:
  Faculty(int facID, string n, string lvl, string dep);
  Faculty();
  ~Faculty();
private:
  int facultyID;
  string name;
  string level;
  string department;

};
