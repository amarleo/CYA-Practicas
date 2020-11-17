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
#include <set>
#include <vector>
#include "../include/transition.h"

Transition::Transition() {
}


Transition::Transition(std::string actual_state, std::string symbol, std::string next_state) {
    actual_state_ = actual_state;
    symbol_ = symbol;
    next_state_ = next_state;
}


Transition::~Transition() {
}

std::string Transition::GetActualState() {
    return actual_state_;
}

std::string Transition::GetNextState() {
    return next_state_;
}

std::string Transition::GetSymbol() {
    return symbol_;
}

void Transition::SetActualState(std::string actual_state) {
    actual_state_ = actual_state;
}


void Transition::SetNextState(std::string next_state) {
    next_state_ = next_state;
}

void Transition::SetSymbol(std::string symbol) {
    symbol_ = symbol;
}

void Transition::SetNumberTransitions(int number_transitions) {
    number_transitions_ = number_transitions;
}

void Transition::AddToTransitionSet(Transition& transition) {
    all_transitions_.push_back(transition);
}