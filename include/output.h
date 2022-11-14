#ifndef OUTPUT_H
#define OUTPUT_H
#include "database.h"
#include "sequence.h"
#include <vector>

using std::vector;
class Output {
private:
  Sequence *sequence;
  Database *database;
  Database *profile;

public:
  void printInstructions();
  void setSequence(Sequence *sequence);
  void setDatabase(Database *database);
  void setProfileFound(Database *profile);
  void printData(map<int, string> *sequenceTypes, vector<Database> *database);
  void printWelcome();
  void printReadingFiles(char *database, char *inputDna);
  void printReadError(char *file);
  void printReadSuccess();
  void printMap(map<int, string> *sequenceTypes);
  void printMatch(string name);
  void printNoMatch();
};
#endif