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
#include "grammar.h"

/// Constructor por defecto

Grammar::Grammar(){}

Grammar::Grammar(std::string alphabet, std::set<std::string> collection_noterminal, std::string initial_noterminal, std::set<std::string> collection_productions) {
    alphabet_ = alphabet;
    collection_noterminal_ = collection_noterminal;
    initial_noterminal_ = initial_noterminal;
    collection_productions_ = collection_productions;  
}

/// destructor
Grammar::~Grammar() {
}

void Grammar::SetAlphabet(std::string alphabet) {
  alphabet_ = alphabet;
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

void Grammar::writeGrammarFile(std::string file) {

}