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
#include <string>
#include <vector>

/**
 * \class Transition
 * The class Transition mainly is used for set a vector of Transitios, after the values were readen on 
 * the main program dfa_simulation.cc. It contains actual and next states, and the symbol asociated
 */

class Transition {
private:
  std::string actual_state_;
  std::string next_state_;
  std::string symbol_; 
  int number_transitions_;
  std::vector<Transition> all_transitions_;
  friend class Dfa;

public:
  Transition();
  Transition(std::string actual_state, std::string symbol, std::string next_state);
  ~Transition();

  std::string GetActualState();
  std::string GetNextState();
  std::string GetSymbol();

  void SetActualState(std::string actual_state);
  void SetNextState(std::string next_state);
  void SetSymbol(std::string symbol);
  void SetNumberTransitions(int number_transitions);
  
  void AddToTransitionSet(Transition& transition);
   
};

