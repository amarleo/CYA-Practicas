/*
- Práctica 7: DFA

Centro: Escuela Superior de Ingeniería y Tecnología
Asignatura: Computabilidad y Algoritmia
Año: 2020/2021
Autor: Alejandro Martín de León
Contacto: alu0101015941@ull.edu.es

Fichero: states.cc


Copyright 2020 Alejandro Martín de León
*/
#include "../include/states.h"
#include <iostream>


States::States(void) {
}

States::~States(void) {
}

void States::SetStateNumber(int state_number) {
    state_number_ = state_number;
}

void States::SetAllStates(std::string all_states) {
    all_states_.insert(all_states);
}

void States::SetInitialState(std::string initial_state) {
    initial_state_ = initial_state;
}

void States::SetAcceptStates(int accept_state) {
    accept_state_ = accept_state;
}

void States::SetAllAcceptStates(std::string accept_states) {
    all_accept_states_.insert(accept_states);
}

int States::GetAcceptNumber() {
    return accept_state_;
}


int States::GetStateNumber() {
    return state_number_;
}

bool States::IsAcceptState(std::string actual_state) {
  
  for (std::set<std::string>::iterator it = all_accept_states_.begin(); it != all_accept_states_.end(); it++) {
   
   if (*it == actual_state) {
      // std::cout << "It: " << *it << " actual: " << actual_state << std::endl;
       return true;
   }
  }
    return false;
}
