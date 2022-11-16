#ifndef OUTPUT_H
#define OUTPUT_H
#include "database.h"
#include "sequence.h"
#include <vector>

using std::vector;
class Output {
public:
  void printInstructions();
  void printWelcome();
  void printReadingFiles(char *database, char *inputDna);
  void printReadError(char *file);
  void printReadSuccess();
  void printMatch(string name);
  void printNoMatch();
};

#endif
