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
#include <string>
#include <fstream>
#include <set>

/**
 * \class DFA
 * The motivation of this class mainly is to check the DFA algorithm
 * 
 */

class Dfa {
private:
  int number_symbols_ = 0;
  std::set<std::string> alphabet_;
  int number_states_;

public:
  Dfa(void);
  ~Dfa(void);
  
  void SetNumberSymbols(int number_symbols);
  void SetAlphabet(std::string symbol);
  
  int GetNumberSymbols();
  
  void ReadSymbols(std::string kDfa_file);
  
  bool AlphabetIsAccepted(std::string alphabet, States& state, Transition& transition);
};


