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
#include "../include/transition.h"

Transition::Transition(/* args */) {
}

Transition::~Transition() {
}

std::string Transition::GetActualState() {
    return actual_state_;
}

std::string Transition::GetNextState() {
    return next_state_;
}

void Transition::SetActualState(std::string actual_state) {
    actual_state_ = actual_state;
}


void Transition::SetNextState(std::string next_state) {
    next_state_ = next_state;
}

void Transition::SetNumberTransitions(int number_transitions) {
    number_transitions_ = number_transitions;
}