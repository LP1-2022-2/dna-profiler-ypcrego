
#include "../include/database.h"
#include "../include/output.h"
#include "../include/sequence.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

// Reads a line (string *ss), separates its contents using commas as delimiters,
// and stores the substrings into a map. The map associates each substring to a
// integer key.
map<int, string> setSequenceStrTypes(string *ss) {
  int ii = 0;
  map<int, string> sequenceTypes;
  if ((*ss).find(',') == string::npos)
    return sequenceTypes;

  // Stores the string to be read.
  istringstream file(*ss);

  string temp;

  std::getline(file, temp, ',');

  while (std::getline(file, temp, ',')) {
    sequenceTypes[ii] = temp;
    ii++;
  }

  return sequenceTypes;
}

// Receives pointers to a line (string *ss) and a vector of <Database> (*data).
// Then, separates the contents of the line using comma as delimiters, and
// stores the resulting substrings into a position of "*data", depending on
// their types. If it's the first substring of the line, stores that substring
// as a name in a certain position of "*data". If it's not, stores the substring
// as a number in another position of "*data". Repeats the proccess until the
// line reaches its end.
void setDatabaseProfile(string *ss, vector<Database> *data) {
  istringstream file(*ss);
  string temp;

  // If no comma has been found in the istringstream, exit function.
  if (!std::getline(file, temp, ',')) {
    return;
  }

  // Inserts a person's name into "data", a <vector> containing the database, at
  // its last position. Appropriately resizes it before doing so.
  int ii = (*data).size();
  (*data).resize(ii + 1);
  (*data)[ii].setName(temp);

  while (std::getline(file, temp, ',')) {

    // Loops through each STR sequence to set its correspondent number of
    // repetitions. Does so at the given position ("jj") of vector "data". The
    // loop continues until there are no more STR sequences to receive values.
    // Furthermore, the number of STR sequences can be acquired by getting the
    // value at "*data" 's first position. since the number of STR sequences is
    // static.
    for (int jj = 0; jj < (*data)[0].getNumStrSequences(); jj++) {

      (*data)[ii].setNumStrRepetitions(jj, atoi(temp.c_str()));

      std::getline(file, temp, ',');
    }
  }
}

int main(int argc, char *argv[]) {
  // csvFile contains the .csv file with the DNA database; dnaFile contains the
  // sequence to be matched.
  ifstream csvFile;
  ifstream dnaFile;

  string ss;
  Output output;

  // Validates flags and number of arguments before continuing.
  if (argc != 5 || strcmp(argv[1], "-d") != 0 || strcmp(argv[3], "-s") != 0) {
    output.printInstructions();
    exit(1);
  }

  output.printWelcome();

  csvFile.open(argv[2]);
  dnaFile.open(argv[4]);

  // Prints a user-directed message that contains the name of both files.
  output.printReadingFiles(argv[2], argv[4]);

  // Validates csvFile before continuing.
  if (csvFile.bad() || !csvFile || csvFile.is_open() == 0 ||
      csvFile.peek() == std::ifstream::traits_type::eof()) {
    output.printReadError(argv[2]);
    output.printInstructions();
    exit(1);
    return 0;
  }

  // Validates dnaFile before continuing.
  if (dnaFile.bad() || !dnaFile || dnaFile.is_open() == 0 ||
      dnaFile.peek() == std::ifstream::traits_type::eof()) {
    output.printReadError(argv[4]);
    output.printInstructions();
    exit(1);
    return 0;
  }

  // Gets the first line of the file, which contains the names of the STR
  // sequences. Then, assigns each type of STR sequence to a key in the map
  // sequenceTypes.
  std::getline(csvFile, ss, '\n');
  map<int, string> sequenceTypes = setSequenceStrTypes(&ss);

  // Validates number of sequences before continuing.
  if (sequenceTypes.size() == 0) {
    output.printReadError(argv[2]);
    output.printInstructions();
    exit(1);
    return 0;
  }

  output.printReadSuccess();
  // Stores each person's name, along with their respectives maximum numbers of
  // repeated STR sequences.
  // PT-BR: Armazena o nome de cada pessoa, junto com seus respectivos números
  // de sequências repetidas para cada tipo.
  vector<Database> database;

  // Defines the number of STR types (extracted from the variable map<int,
  // string> "sequenceTypes") to all objects of class Database. Since
  // sequenceTypes contains all possible values of STR sequences during the
  // execution, it's possible to extract the total number of STR types from it.
  // The first position of variable "database", "database[0]" is used only for
  // convenience, as StrSequences is a static variable in Database.
  // PT-BR: Define o número máximo de tipos de sequência para os objetos da
  // classe Database. ([0] é usado apenas para conveniência, pois o atributo na
  // classe é estático).
  database[0].setNumStrSequences(sequenceTypes.size());

  // Inserts individuals into the database while csvFile hasn't reached its end.
  // PT-BR: Cadastra os indivíduos em database enquanto o arquivo não tiver
  // chegado ao fim.
  while (!csvFile.eof()) {
    std::getline(csvFile, ss, '\n');
    setDatabaseProfile(&ss, &database);
  }

  csvFile.close();

  // Stores the sequence to be matched.
  Sequence inputDna;
  std::getline(dnaFile, ss, '\n');

  dnaFile.close();

  // Sets the sequence string (the DNA sequence to be matched) in inputDna.
  inputDna.setSequence(ss);

  // Generates a profile based on the DNA sequence read from dnaFile. Uses
  // sequenceType as a parameter because it has the strings that correspond to
  // the STR types.
  inputDna.generateProfile(sequenceTypes);

  // Creates the profile for a possible match for the given DNA sequence.
  Database correctProfile;

  // Iterates through each profile and searches for a match between it and the
  // profile that was generated in inputDna.
  for (int ii = 0; ii < database.size(); ii++) {
    bool found = 0;
		
    // database[ii].findProfile() returns a bool that indicates success or
    // failure. It searches the database for a match between the profile at
    // position "ii" of database and the one in "inputDna".
    found = database[ii].findProfile(inputDna.getProfile());

    if (found) {
      correctProfile = database[ii];
      break;
    }
  }

  // If there is a match, print the name of the person whose data matched. If
  // not, print a message of no match found.
  if (!correctProfile.empty()) {
    output.printMatch(correctProfile.getName());
  } else {
    output.printNoMatch();
  }

  return 0;
}
