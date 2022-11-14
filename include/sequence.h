#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "database.h"
#include <string>
using std::string;
#include <map>
using std::map;

#include <algorithm>
class Sequence {
private:
  string sequence;
  Database profile;

public:
  string getSequence();
  void setSequence(string str);
  int getNumStrSequences();
  void setNumStrSequences(int n);
  map<int, int> getStrRepetitions();
  int getNumStrRepetitions(int key);
  void setNumStrRepetitions(int key, int value);
  void generateProfile(map<int, string> map);
  Database getProfile();
};

#endif