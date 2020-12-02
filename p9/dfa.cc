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

/// Constructor con fichero pasado por parámetro
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

Grammar& Dfa::ConvertToGrammar(Grammar& grammar, States& state, Transition& transition) {

  std::string initial_noterminal = state.GetInitialState();
  grammar.SetInitialNoTerminal(initial_noterminal);

  std::set<std::string>::iterator it = alphabet_.begin(); 
  std::string alphabet;

  while (it != alphabet_.end()) {
    alphabet = *it;
    grammar.SetAlphabet(alphabet);
    it++;
  }

  
  std::set<std::string> collection_noterminal = state.GetAllStates();
  grammar.SetNoTerminals(collection_noterminal);

  std::string production;

  for (unsigned i = 0; i < transition.all_transitions_.size(); i++) {
    production = transition.all_transitions_[i].GetActualState() + " -> " + transition.all_transitions_[i].GetSymbol() + transition.all_transitions_[i].GetNextState();
    grammar.SetProductions(production);
    //std::string right_side_rule = transition.all_transitions_[i].GetNextState();
    /*
    if ((transition.all_transitions_[i+1].GetActualState() != transition.all_transitions_[i].GetActualState()) && (state.IsAcceptState(right_side_rule))) {
      production = transition.all_transitions_[i].GetActualState() + " -> ~";
      grammar.SetProductions(production);
      grammar.IncreaseNumberProductions();
    }
    */
    grammar.IncreaseNumberProductions();
  }
  return grammar;
}