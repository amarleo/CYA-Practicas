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
#include <fstream>
#include "grammar.h"

/// Constructor por defecto

Grammar::Grammar(){}

Grammar::Grammar(std::set<std::string> alphabet, std::set<std::string> collection_noterminal, std::string initial_noterminal, std::set<std::string> collection_productions) {
    alphabet_ = alphabet;
    collection_noterminal_ = collection_noterminal;
    initial_noterminal_ = initial_noterminal;
    collection_productions_ = collection_productions;  
}

/// destructor
Grammar::~Grammar() {
}

void Grammar::SetAlphabet(std::string alphabet) {
  alphabet_.insert(alphabet);
}

void Grammar::SetNoTerminals(std::set<std::string> collection_noterminal) {
  collection_noterminal_ = collection_noterminal; 
}

void Grammar::SetInitialNoTerminal(std::string initial_noterminal) {
  initial_noterminal_ = initial_noterminal;
}

void Grammar::SetProductions(std::string production) {
  collection_productions_.insert(production);
}

int Grammar::GetNumberProducts() {
  return number_productions_;
}

int Grammar::GetAlphabetSize() {
  return alphabet_.size();
}

int Grammar::GetNoTerminalSize() {
  return collection_noterminal_.size();
}

std::string Grammar::GetInitialNoTerminal() {
  return initial_noterminal_;
}

std::set<std::string> Grammar::GetAlphabet() {
  return alphabet_;
}

std::set<std::string> Grammar::GetCollectionNoTerminal() {
  return collection_noterminal_;
}

std::set<std::string> Grammar::GetCollectionProductions() {
  return collection_productions_;
}

void Grammar::writeGrammarFile(std::string filename, Grammar& grammar) {
  std::ofstream file;
  std::string line;
  std::set<std::string>::iterator it;

  file.open(filename);
  if (file.is_open(), std::fstream::out) {
    file << GetAlphabetSize() << "\n";
    for (it = GetAlphabet().begin(); it != GetAlphabet().end(); ++it) {
      file << *it << "\n";
    }
    file << GetNoTerminalSize() << "\n";
    for (it = collection_noterminal_.begin(); it != collection_noterminal_.end(); it++) {
      file << *it << "\n";
      std::cout << *it << std::endl;
    }
    file << grammar.initial_noterminal_ << "\n";
    file << GetNumberProducts() << "\n";
    for (it = collection_productions_.begin(); it != collection_productions_.end(); it++) {
      file << *it << "\n";
      
    }
  }
}