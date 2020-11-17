/*
- Práctica 7: DFA

Centro: Escuela Superior de Ingeniería y Tecnología
Asignatura: Computabilidad y Algoritmia
Año: 2020/2021
Autor: Alejandro Martín de León
Contacto: alu0101015941@ull.edu.es

Fichero: .h


Copyright 2020 Alejandro Martín de León
*/

#include <iostream>
#include <string>
#include "../include/alphabet.h"


Alphabet::Alphabet(/* args */)
{
}

Alphabet::~Alphabet()
{
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