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


























/*
bool Dfa::AlphabetIsAccepted(std::string alphabet, States& state, Transition& transition) {
  std::string actual_state = state.initial_state_;
  unsigned counter = 0;
  for (unsigned i = 0; i < alphabet.size(); i++) {
      
    //for (unsigned j = 0; j < transition.all_transitions_.size(); j++) {
      std::string symbol;
      symbol = alphabet[i];
      std::cout << std::endl;
      //std::cout << "Actual: " << actual_state << " Transicion " << transition.all_transitions_[i].GetActualState() << std::endl;
      //std::cout << "Symbol: " << symbol << " Transicion " << transition.all_transitions_[i].GetActualState();

      unsigned j = 0;
        
        while((transition.all_transitions_[j].GetActualState() != actual_state) && (transition.all_transitions_[j].GetSymbol() != symbol) && (counter < alphabet.size())) {
          actual_state = transition.all_transitions_[j].GetNextState();
          
          if ((state.IsAcceptState(actual_state) == true) && (symbol == alphabet.cend())) {
              
              return true;
          }
        }
      }
        
        std::cout << std::endl;
        }
        
   // }
  
  return false;
}*/