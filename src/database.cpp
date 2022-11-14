#include "../include/database.h"

int Database::numStrSequences;

Database::Database() { name = ""; }

Database::Database(string name, map<int, int> StrRepetitions)
    : name(name), StrRepetitions(StrRepetitions) {}

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
  for (int ii = 0; ii < numStrSequences; ii++) {
    if (StrRepetitions[ii] == generatedProfile.getNumStrRepetitions(ii)) {
      count++;
    }
  }
  if (count == 3)
    return 1;
  else
    return 0;
};

bool Database::empty() {
  if (name == "")
    return 1;
  else
    return 0;
}

map<int, int> Database::getStrRepetitions() { return StrRepetitions; }