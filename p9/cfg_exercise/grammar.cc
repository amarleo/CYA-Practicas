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
#include <string>
#include <fstream>
#include "grammar.h"

/// Constructor por defecto

Grammar::Grammar(){}

/**
 * @brief Constructo parametrizado
 * @param (alphabet) Tipo de dato set de strings que contiene todos y cada uno de los simbolos
 * @param (collection_noterminal) Contiene el conjunto de símbolos no terminales
 * @param (initial_noterminal) Contiene el símbolo de arranque
 * @param (collection_productions) Contiene el conjunto de Producciones producidas por el programa
 * 
 * 
*/

Grammar::Grammar(std::set<std::string> alphabet, std::set<std::string> collection_noterminal, std::string initial_noterminal, std::set<std::string> collection_productions) {
    alphabet_ = alphabet;
    collection_noterminal_ = collection_noterminal;
    initial_noterminal_ = initial_noterminal;
    collection_productions_ = collection_productions;  
}

/// destructor
Grammar::~Grammar() {
}


/**
 * @brief Método set 
 * @param (alphabet) Tipo de dato set de strings que contiene todos y cada uno de los simbolos
 * 
 * Inserta símbolos de tipo string en el alfabeto correspondiente.
*/
void Grammar::SetAlphabet(std::string alphabet) {
  alphabet_.insert(alphabet);
}

/**
 * @brief Método set 
 * @param (alphabet) Tipo de dato set de strings que contiene todos y cada uno de los simbolos
 * 
 * Set de la coleccion de simbolos no terminales de tipo set de strings .
*/
void Grammar::SetNoTerminals(std::set<std::string> collection_noterminal) {
  collection_noterminal_ = collection_noterminal; 
}


/// Método Set que establece el símbolo de arranque
void Grammar::SetInitialNoTerminal(std::string initial_noterminal) {
  initial_noterminal_ = initial_noterminal;
}

/// Método Set que inserta el parámetro de tipo string en una coleccion que contendrá todos los productos.
void Grammar::SetProductions(std::string production) {
  collection_productions_.insert(production);
}

///Método Get, retorna el número de producciones
int Grammar::GetNumberProducts() {
  return number_productions_;
}

///Método Get, retorna el tamaño del alfabeto o el número de simbolos terminales
int Grammar::GetAlphabetSize() {
  return alphabet_.size();
}

///Método Get, retorna el tamaño del conjunto de símbolos no terminales
int Grammar::GetNoTerminalSize() {
  return collection_noterminal_.size();
}

///Método Get, retorna el símbolo de arranque
std::string Grammar::GetInitialNoTerminal() {
  return initial_noterminal_;
}

///Método Get, retorna el alfabeto o símbolos termnales, se trata de un set de strings
std::set<std::string> Grammar::GetAlphabet() {
  return alphabet_;
}

///Método Get, retorna El conjunto de simbolos no terminales
std::set<std::string> Grammar::GetCollectionNoTerminal() {
  return collection_noterminal_;
}

///Método Get, retorna el conjunto de producciones
std::set<std::string> Grammar::GetCollectionProductions() {
  return collection_productions_;
}

std::string Grammar::NullableSymbols(std::string nullable_symbol) {
  std::string concatenate;
  return concatenate = concatenate + nullable_symbol;
}

/**
 * @brief Método Escritura de la Gramática 
 * @param (filename) Tipo de dato string que contiene el nombre del fichero de salida
 * @param (grammar) Referencia al objeto de la clase Grammar
 * 
 * Se trata de el método que permite la escritura en un fichero de salida .gra
*/
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
    }
    file << grammar.initial_noterminal_ << "\n";
    file << GetNumberProducts() << "\n";
    for (it = collection_productions_.begin(); it != collection_productions_.end(); it++) {
      file << *it << "\n";
      
    }
    
  }
}