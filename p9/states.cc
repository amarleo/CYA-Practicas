/**
 * \note PROJECT HEADER
 * \note Proyect: DFA
 * \note subject: Computabilidad y Algoritmia
 * \note Author: Alejandro Martín de León
 * \note Contact: alu0101015941@ull.edu.es
 * \note Date: 18/11/2020 
 * \note Copyright 2020 Alejandro Martín de León
*/

#include "states.h"
#include <iostream>

/// Constructor por defecto
States::States(void) {
}

/// Destructor
States::~States(void) {
}

/// Establece el número de estados
void States::SetStateNumber(int state_number) {
  state_number_ = state_number;
}

/// Inserta en el set de todos los estados, cualquier estado
void States::SetAllStates(std::string all_states) {
  all_states_.insert(all_states);
}

/// Establece el estado inicial
void States::SetInitialState(std::string initial_state) {  
  initial_state_ = initial_state;
}

/// Establece y almacena los estados de aceptación
void States::SetAcceptStates(int accept_state) {
  accept_state_ = accept_state;
}

/// Inserta en el set que contiene todos los estados, un estado individual
void States::SetAllAcceptStates(std::string accept_states) {
  all_accept_states_.insert(accept_states);
}

/// Obtiene el número de estados de aceptacion
int States::GetAcceptNumber() {
  return accept_state_;
}


/// Obtiene el numero de estados
int States::GetStateNumber() {
  return state_number_;
}

std::string States::GetInitialState() {
  return initial_state_;
}


std::set<std::string> States::GetAllStates() {
  return all_states_;
}

/// Determina si el estado pasado por referencia se trata de un estado de aceptación
bool States::IsAcceptState(std::string actual_state) {
  for (std::set<std::string>::iterator it = all_accept_states_.begin(); it != all_accept_states_.end(); it++) { 
    if (*it == actual_state) {
       return true;
    }
  }
  return false;
}
