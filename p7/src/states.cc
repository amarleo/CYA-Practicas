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

void States::SetQ0(std::string q0) {
    q0_ = q0;
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


