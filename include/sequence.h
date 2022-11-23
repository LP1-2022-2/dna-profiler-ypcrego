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
  // Stores the possible profile that matches the given sequence.
  Database profile;

public:
  string getSequence();
  void setSequence(string str);
  int getNumStrSequences();
  void setNumStrSequences(int n);

  // Returns the map that associates the maximum number of repeats of each STR
  // sequence to indexes.
  map<int, int> getStrRepetitions();

  // Given a key, returns the maximum number of repeats of the STR sequence type
  // that is mapped to that key.
  int getNumStrRepetitions(int key);

  // Given a key and a value, associates both.
  void setNumStrRepetitions(int key, int value);

	// Generates a profile, assigning a value to the variable "profile". Receives a map<int, string> map because it contains the names of the types of STR sequences, which is then used to count the repetitions of each STR sequence type.
  void generateProfile(map<int, string> map);

  Database getProfile();
};

#endif
