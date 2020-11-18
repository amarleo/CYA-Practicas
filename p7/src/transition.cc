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
#include <set>
#include <vector>
#include "../include/transition.h"

Transition::Transition() {}

Transition::Transition(std::string actual_state, std::string symbol, std::string next_state) {
    actual_state_ = actual_state;
    symbol_ = symbol;
    next_state_ = next_state;
}

Transition::~Transition() {}

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