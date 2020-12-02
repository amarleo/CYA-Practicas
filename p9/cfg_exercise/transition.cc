/**
 * \note PROJECT HEADER
 * \note Proyect: DFA to Grammar.
 * \note subject: Computabilidad y Algoritmia
 * \note Author: Alejandro Martín de León
 * \note Contact: alu0101015941@ull.edu.es
 * \note Date: 2/12/2020 
 * \note Copyright 2020 Alejandro Martín de León
*/


#include <iostream>
#include <set>
#include <vector>
#include "transition.h"

/// Constructor por defecto
Transition::Transition() {}

/// Constructor parametrizado
Transition::Transition(std::string actual_state, std::string symbol, std::string next_state) {
    actual_state_ = actual_state;
    symbol_ = symbol;
    next_state_ = next_state;
}

/// Destructor
Transition::~Transition() {}

/// obten el estado actual 
std::string Transition::GetActualState() {
  return actual_state_;
}

/// Obten el estado siguiente
std::string Transition::GetNextState() {
  return next_state_;
}

/// Obten el simbolo en el estado actual
std::string Transition::GetSymbol() {
  return symbol_;
}

/// Establece el estado actual del DFA
void Transition::SetActualState(std::string actual_state) {
  actual_state_ = actual_state;
}

/// Establece el estado siguiente
void Transition::SetNextState(std::string next_state) {
  next_state_ = next_state;
}

/// Establece el simbolo correspondiente al estado actual
void Transition::SetSymbol(std::string symbol) {
  symbol_ = symbol;
}

/// Establece el numero de transiciones del DFA
void Transition::SetNumberTransitions(int number_transitions) {
  number_transitions_ = number_transitions;
}

/// Añade la transicion al vector de transiciones
void Transition::AddToTransitionSet(Transition& transition) {
  all_transitions_.push_back(transition);
}