#include "../include/database.h"

int Database::numStrSequences;

Database::Database() { name = ""; }

string Database::getName() { return name; }

void Database::setName(string name) { this->name = name; }

void Database::setNumStrSequences(const int numSequences) {
  this->numStrSequences = numSequences;
}

int Database::getNumStrSequences() { return numStrSequences; }

int Database::getNumStrRepetitions(int key) { return StrRepetitions[key]; }

void Database::setNumStrRepetitions(int key, int value) {
  StrRepetitions[key] = value;
}

// Takes a given DNA sequence and searches the database for a match.
bool Database::findProfile(Database generatedProfile) {
  int count = 0;
  map<int, int>::iterator it;

  // Loops through the StrRepetitions map until there aren't more STR sequence
  // types.
  for (int ii = 0; ii < numStrSequences; ii++) {

    // Compares the value at a certain position of StrRepetitions to the value
    // at the same position of generatedProfile.
    if (StrRepetitions[ii] == generatedProfile.getNumStrRepetitions(ii)) {
      count++;
    }
  }
  // Returns true if the sequence is a exact match.
  if (count == numStrSequences)
    return 1;
  else
    return 0;
}

// Checks if the object is empty by checking its name.
bool Database::empty() {
  if (name == "")
    return 1;
  else
    return 0;
}

map<int, int> Database::getStrRepetitions() { return StrRepetitions; }
