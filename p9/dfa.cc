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
#include "dfa.h"

/// Constructor por defecto
Dfa::Dfa(void) {
}

/// Destructor 
Dfa::~Dfa(void) {
}

/// Establece el numero de simbolos
void Dfa::SetNumberSymbols(int number_symbols) {
  number_symbols_ = number_symbols;
}

/// Inserta en el set cada uno de los simbolos 
void Dfa::SetAlphabet(std::string symbol) {
  alphabet_.insert(symbol);
}

/// Devuelve el numero de simbolos que contiene el alfabeto
int Dfa::GetNumberSymbols() {
  return number_symbols_;
}

/// funcion booleana que determina si una cadena llega a un estado de aceptación
bool Dfa::AlphabetIsAccepted(std::string alphabet, States& state, Transition& transition) {
  std::string actual_state = state.initial_state_;
  for (unsigned i = 0; i < alphabet.size(); i++) {
    std::string symbol;
    std::string last_symbol;
    last_symbol = alphabet[alphabet.size()-1];
    symbol = alphabet[i];
    for (unsigned j = 0; j < transition.all_transitions_.size(); j++) {
      if ((transition.all_transitions_[j].GetActualState() == actual_state) && transition.all_transitions_[j].GetSymbol() == symbol) {
        actual_state = transition.all_transitions_[j].GetNextState();
        if (state.IsAcceptState(actual_state) && (i == alphabet.size() - 1)) {
            return true;
        }
        break;
      }
    }
  } 
  return false;
}