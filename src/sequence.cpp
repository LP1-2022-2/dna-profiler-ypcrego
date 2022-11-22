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
  // If the sequence hasn't been set or if there aren't any STR sequences, the
  // functions returns.
  // PT-BR: Se a sequência não tiver sido preenchida ou se não houver sequências
  // STR, a função retorna.
  if (sequence.empty() || profile.getNumStrSequences() == 0) {
    return;
  }

  // Maps each STR sequence to the max value found in the given sequence.
  // PT-BR: Mapeia cada sequencia STR para o valor máximo encontrado na
  // sequência dada.
  for (int ii = 0; ii < profile.getNumStrSequences(); ii++) {
    // Gets the STR sequence from variable map<int, string> map.
    // PT-BR: Pega a string de sequência STR do mapa que foi passado como
    // parâmetro.
    string str = map[ii];

    // pos stores a certain position during the iteration through the string.
    // count stores the number of repetitions of the STR sequence type at a
    // certain moment.
    // maxCount stores the number of maximum repeats of that type of STR
    // sequence.
    // prevPos stores the previous position of pos.
    int pos = 0;
    int count = 0;
    int maxCount = 0;
    int prevPos = 0;

    // Loops through the entire sequence (a string).
    // PT-BR:Loop para percorrer a sequência (string) inteira.
    while (pos <= (int)sequence.size()) {

      // If the STR type hasn't been found, increments pos by the length of the
      // STR type name. This is so that the code doesn't waste time looking
      // through each position, since the STR type has a fixed length (whatever
      // it may be).
      // PT-BR: Se a sequência não encontrou a o tipo STR, incrementa pos no
      // valor do tamanho de str e continua para o próximo loop. Isso é feito
      // para o código não precisar percorrer cada posição, uma vez que cada
      // tipo STR tem um tamanho fixo, seja ele qual for.
      if (sequence.find(str, pos) == string::npos) {
        pos += str.size();
        continue;
      }

      // Stores the position in which the STR type (a string) has been found.
      // Captura a posição em que a string STR foi encontrada.
      pos = sequence.find(str, pos);

      // Checks if the positions are consecutive; if they aren't, count is set
      // to zero. prevPos stores the previous value of pos.
      // PT-BR: Verifica se as posições são consecutivas; se não forem, count é
      // zerada. prevPos armazena o valor anterior de pos.
      if (pos - prevPos > (int)(str.size())) {
        count = 0;
      }

      // Increments count by one, since, at this point, it has found the STR
      // sequence type. PT-BR:Incrementa count, por ter encontrado a string.
      count++;

      // Updates the number of maximum repeats of the STR sequence type.
      // PT-BR: Define o número máximo de sequências encontradas.
      if (count > maxCount) {
        maxCount = count;
      }

      // Increases pos so it continues iterating through the sequence.
      // PT-BR: Incrementa pos para continuar percorrendo a sequência.
      pos += str.size();

      // prevPos stores the previous value of pos.
      // PT-BR: prevPos armazena o valor anterior de pos.
      prevPos = pos;
    }

    // After the sequence has reached its end, maps the number of maximum
    // repeats of the STR sequence type to "ii". "ii" represents the index of a
    // certain STR sequence type.
    // PT-BR: Após a finalização da sequência, mapeia o número máximo de
    // repetições encontradas para o valor ii, que representa o index de um
    // certo tipo de sequência STR.
    profile.setNumStrRepetitions(ii, maxCount);
  }
}

Database Sequence::getProfile() { return profile; }
