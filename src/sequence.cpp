#include "../include/sequence.h"
#include <iostream>

using namespace std;

string Sequence::getSequence() { return sequence; }

void Sequence::setSequence(string str) { sequence = str; }

int Sequence::getNumStrSequences() { return profile.getNumStrSequences(); }

void Sequence::setNumStrSequences(int n) { profile.setNumStrSequences(n); }

map<int, int> Sequence::getStrRepetitions() {
  return profile.getStrRepetitions();
}

int Sequence::getNumStrRepetitions(int key) {
  return profile.getNumStrRepetitions(key);
}

void Sequence::setNumStrRepetitions(int key, int value) {
  profile.setNumStrRepetitions(key, value);
}

void Sequence::generateProfile(map<int, string> map) {
  // Se a sequência não tiver sido preenchida ou se não houver sequências STR, a
  // função retorna.
  if (sequence.empty() || profile.getNumStrSequences() == 0) {
    return;
  }
  // Maps each STR sequence to the max value found in the given sequence.
  // Mapeia cada sequencia STR para o valor máximo encontrado na sequência dada.
  for (int ii = 0; ii < profile.getNumStrSequences(); ii++) {
    // Gets the STR sequence from map
    // Pega a string de sequência STR do mapa que foi passado como parâmetro.
    string str = map[ii];

    int pos = 0;
    int count = 0;
    int maxCount = 0;
    int prevPos = 0;

    // Loop para percorrer a sequência (string) inteira.
    while (pos <= sequence.size()) {

      // Se a sequência não encontrou a string STR, incrementa pos no valor do
      // tamanho de str e continua para o próximo loop.
      if (sequence.find(str, pos) == string::npos) {
        pos += str.size();
        continue;
      }

      // Captura a posição em que a string STR foi encontrada.
      pos = sequence.find(str, pos);

      // Verifica se as posições são consecutivas; se não forem, count é zerada.
      // prevPos armazena o valor anterior de pos.
      if (pos - prevPos > (str.size())) {
        count = 0;
      }

      // Incrementa count, por ter encontrado a string.
      count++;

      // Define o número máximo de sequências encontradas.
      if (count > maxCount) {
        maxCount = count;
      }

      // Incrementa pos para continuar percorrendo a sequência.
      pos += str.size();

      // prevPos armazena o valor anterior de pos.
      prevPos = pos;
    }

    // Após a finalização do loop, mapeia o valor ii de repetitions para o
    // número máximo de repetições encontradas.
    profile.setNumStrRepetitions(ii, maxCount);
  }
}

Database Sequence::getProfile() { return profile; };