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

/// Constructor por defecto
Alphabet::Alphabet() {
}

/// destructor
Alphabet::~Alphabet() {
}

/// Inserta string en el objeto que contiene los sets de strings
void Alphabet::SetAlphabet(std::string alphabet) {
  all_alphabets_.insert(alphabet);
}

/// Devuelve el tamaño del set
int Alphabet::Size() {
  return all_alphabets_.size();
}

/// Devuelve el objeto contenedor de set de strings
std::set<std::string> Alphabet::GetAlphabet() {
  return all_alphabets_;
}