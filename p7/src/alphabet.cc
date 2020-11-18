/**
 * \note PROJECT HEADER
 * \note Proyect: DFA
 * \note subject: Computabilidad y Algoritmia
 * \note Author: Alejandro Martín de León
 * \note Contact: alu0101015941@ull.edu.es
 * \note Date: 18/11/2020 
 * \note Copyright 2020 Alejandro Martín de León
*/


#include <iostream>
#include <string>
#include "../include/alphabet.h"


Alphabet::Alphabet() {
}

Alphabet::~Alphabet() {
}

void Alphabet::SetAlphabet(std::string alphabet) {
  all_alphabets_.insert(alphabet);
}

int Alphabet::Size() {
  return all_alphabets_.size();
}

std::set<std::string> Alphabet::GetAlphabet() {
  return all_alphabets_;
}