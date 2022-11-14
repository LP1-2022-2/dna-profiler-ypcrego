
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

// Mapeia os tipos de sequencia ao mapa.
// Atuais problemas da funcao: ela nao realmente separa pela virgula.
// Basicamente, ela vai apagando de 4 em 4 e cadastrando os 4 primeiros
// caracteres no mapa. Nao é isso que eu quero, quero realmente separar por
// virgula e cadastrar assim.
map<int, string> setSequenceStrTypes(string *ss) {
  int ii = 0;
  istringstream file(*ss);
  map<int, string> sequenceTypes;
  string temp;

  std::getline(file, temp, ',');

  while (std::getline(file, temp, ',')) {
    sequenceTypes[ii] = temp;
    ii++;
  }

  return sequenceTypes;
}

void setDatabase(string *ss, vector<Database> *data) {
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
    // repetitions. Does so at the given position of vector "data". Since the
    // number of STR sequences is static, it's sufficient to get the value at
    // "*data" 's first position.
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

  output.printReadingFiles(argv[2], argv[4]);

  // Validates csvFile before continuing.
  if (csvFile.bad() || !csvFile || csvFile.is_open() == 0) {
    output.printReadError(argv[2]);
    output.printInstructions();
    exit(1);
    return 0;
  }

  // Validates dnaFile before continuing.
  if (dnaFile.bad() || !dnaFile || dnaFile.is_open() == 0) {
    output.printReadError(argv[4]);
    output.printInstructions();
    exit(1);
    return 0;
  }

  output.printReadSuccess();

  // Gets the first line of the file, which contains the names of the STR
  // sequences. Then, assigns each type of STR sequence to a key in the map
  // sequenceTypes.
  std::getline(csvFile, ss, '\n');
  map<int, string> sequenceTypes = setSequenceStrTypes(&ss);

  // Stores each person's name, along with their respectives maximum numbers of
  // repeated STR sequences. Armazena o nome de cada pessoa, junto com seus
  // respectivos números de sequências repetidas para cada tipo.
  vector<Database> database;

  // Defines the number of STR types (extracted from the variable map<int,
  // string> "sequenceTypes") to all objects of class Database. Since
  // sequenceTypes contains all possible values of STR sequences during the
  // execution, it's possible to extract the total number of STR types from it.
  // The first position of variable "database", "database[0]" is used only for
  // convenience, as StrSequences is a static variable in Database.
  // Define o número máximo de tipos de sequência para os objetos da classe
  // Database. ([0] é usado apenas para conveniência, pois o atributo na classe
  // é estático).
  database[0].setNumStrSequences(sequenceTypes.size());

  // Inserts individuals into the database while csvFile hasn't reached its end.
  // Cadastra os indivíduos em database enquanto o arquivo não tiver chegado ao
  // fim.
  while (!csvFile.eof()) {
    std::getline(csvFile, ss, '\n');
    setDatabase(&ss, &database);
  }

  csvFile.close();

  Sequence inputDna;
  std::getline(dnaFile, ss, '\n');

  dnaFile.close();

  // sequence.setNumStrSequences(database[0].getNumStrSequences());
  inputDna.setSequence(ss);

  // Generates a profile based on the DNA sequence read from dnaFile. Uses
  // sequenceType as a parameter because it has the strings that correspond to
  // the STR types.
  inputDna.generateProfile(sequenceTypes);

  // Creates the profile for a possible match for the given DNA sequence.
  Database correctProfile;
  for (int ii = 0; ii < database.size(); ii++) {
    bool found = 0;
    // database[ii].findProfile() returns a bool that indicates success or
    // failure. It searches the database for a match between the profile at
    // position "ii" and "inputDna".
    found = database[ii].findProfile(inputDna.getProfile());

    if (found) {
      correctProfile = database[ii];
      break;
    }
  }

  if (!correctProfile.empty()) {
    output.printMatch(correctProfile.getName());
  } else {
    output.printNoMatch();
  }
  return 0;
}
