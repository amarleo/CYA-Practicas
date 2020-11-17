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
#include "../include/dfa.h"

Dfa::Dfa(void) {
}

Dfa::~Dfa(void) {
}

void Dfa::SetNumberSymbols(int number_symbols) {
   number_symbols_ = number_symbols;
}

void Dfa::SetAlphabet(std::string symbol) {
    alphabet_.insert(symbol);
}

int Dfa::GetNumberSymbols() {
    return number_symbols_;
}