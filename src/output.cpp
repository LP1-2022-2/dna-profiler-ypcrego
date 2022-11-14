#include "../include/output.h"

using std::endl;

void Output::printInstructions() {
  cout << "Usage: dna_profiler -d <database_file> -s <dna_sequence_file>\n "
          "Where the arguments are:\n\t<database_file>\tThe DNA database "
          "file\n\t<dna_sequence_file>\tThe DNA sequence file you wish to "
          "identify (find a match for)."
       << endl;
}

void Output::printWelcome() {
  cout << endl
       << "============================================\n\t Welcome to the "
          "Basic DNA "
          "Profiler, v1.0\n\t Copyright (C) 2022, Yves P. Costa "
          "Rêgo\n============================================\n\nThis program "
          "loads a "
          "DNA database and an unknown DNA sequence and tries to find a "
          "match between the input DNA sequence and the DNA database."
       << endl
       << endl;
}

void Output::printReadingFiles(char *database, char *inputDna) {
  cout << "[+] Preparing to read the DNA database file [" << database << "]"
       << endl
       << "[+] Preparing to read the unknown DNA sequence file [" << inputDna
       << "]" << endl
       << "[+] Processing data, please wait." << endl
       << endl;
}

void Output::printReadError(char *file) {
  cout << "================================================\n[X] ERROR: File ["
       << file
       << "] not found.\n================================================"
       << endl
       << endl;
}

void Output::printReadSuccess() {
  cout << "[+] Input files successfully read.\n[+] Searching the "
          "database for a match... please wait."
       << endl
       << endl;
}

void Output::printMatch(string name) {
  cout << "Match ID (99.9%): " << name << endl;
}

void Output::printNoMatch() {
  cout << ">>> Sorry, no match in our database.\n";
}