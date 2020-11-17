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

bool Dfa::AlphabetIsAccepted(std::string alphabet, States& state, Transition& transition) {
  std::string actual_state = state.initial_state_;
  unsigned counter = 0;
  for(auto it = alphabet.cbegin(); it < alphabet.cend(); it++) {
      
    for (unsigned i = 0; i < transition.all_transitions_.size(); i++) {
      std::string symbol;
      symbol = *it;
      if ((transition.all_transitions_[i].GetActualState() == actual_state) && (transition.all_transitions_[i].GetSymbol() == symbol) && (counter < alphabet.size())) {
      std::cout << "actual state: " << actual_state << " symbol: " << symbol << std::endl;
        actual_state = transition.all_transitions_[i].GetNextState();
        //std::cout << "Actual: " << actual_state << std::endl;
        if ((state.IsAcceptState(actual_state) == true) && (it == alphabet.cend())) {
            return true;
        }
      counter++;
      }
    }
  }
  return false;
}