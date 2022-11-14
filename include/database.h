#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <map>
using std::map;

class Database {

private:
  string name;
  // Number of STR sequences in the database.
  static int numStrSequences;
  // Associates the maximum number of a given STR sequence in a person's DNA to
  // a index.
  map<int, int> StrRepetitions;

public:
  Database();
  Database(string name, map<int, int> StrRepetitions);
  string getName();
  void setName(string name);
  int getNumStrSequences();
  void setNumStrSequences(int numSequences);
  map<int, int> getStrRepetitions();
  int getNumStrRepetitions(int key);
  void setNumStrRepetitions(int key, int value);
  bool findProfile(Database generatedProfile);
  bool empty();
};

#endif