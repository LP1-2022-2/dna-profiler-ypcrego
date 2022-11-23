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

  // Associates the maximum number of repeats of a given STR sequence in a
  // person's DNA to a index.
  map<int, int> StrRepetitions;

public:
  Database();
  string getName();
  void setName(string name);

  // Returns the number of STR sequence types.
  int getNumStrSequences();

  void setNumStrSequences(int numSequences);

  // Returns the map that associates the maximum number of repeats of each STR
  // sequence to indexes.
  map<int, int> getStrRepetitions();

  // Given a key, returns the maximum number of repeats of the STR sequence type
  // that is mapped to that key.
  int getNumStrRepetitions(int key);

  // Given a key and a value, associates both.
  void setNumStrRepetitions(int key, int value);

  // Given a DNA sequence (in the form of a profile), finds another profile.
  // Returns 0 if a profile hasn't been found, and 1 if it has been found.
  bool findProfile(Database generatedProfile);

  // Checks if the Database object is empty.
  bool empty();
};

#endif
