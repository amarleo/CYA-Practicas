/*
- Práctica X:

Centro: Escuela Superior de Ingeniería y Tecnología
Asignatura: Computabilidad y Algoritmia
Año: 2020/2021
Autor: Alejandro Martín de León
Contacto: alu0101015941@ull.edu.es

Fichero: set_calculator.cc


Copyright 2020 Alejandro Martín de León
*/

#include "../include/dfa.h"
#include "../include/alphabet.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

bool IsComment(std::string line){
  if (line[0] != '/' && line[1] != '/') {
    return true;
  }
  else {
    return false;
  }
}

bool Help() {
  std::cout << "Uso: ./dfa_simulation [ARCHIVO DFA] [ARCHIVO ENTRADA] [ARCHIVO SALIDA]" <<std::endl;
  return 0;
}

void Error(int parameter_number, std::string parameter_command) {
  if ((parameter_command == "--help") && (parameter_number == 2)) {
    Help();
  } 
  else {
    std::cout << "Modo de empleo: ./dfa_simulation input.dfa input.txt output.txt" << std::endl;
    std::cout << "Pruebe './dfa_simulation --help' para más información." << std::endl;
  }
}

void ReadDfaFile(std::string filename, Dfa& dfa, States& state, Transition& transition) {
  std::fstream file;
  std::string line, initial_state, actual_state, next_state, symbol;
  std::stringstream converter, converter2;
  int number_symbols, state_number, accept_number, transition_number;
  file.open(filename);
  if (file.is_open()) {
    while(getline(file, line)) {
      if (IsComment(line)) {
        converter << line;
        converter >> number_symbols;
        dfa.SetNumberSymbols(number_symbols);
        for (int i = 0; i < dfa.GetNumberSymbols(); i++) {
          getline(file, line);      
          dfa.SetAlphabet(line);
        }
        getline(file, line);
        converter.clear();
        converter << line;
        converter >> state_number;
        state.SetStateNumber(state_number);
        for (int i = 0; i < state.GetStateNumber(); i++) { 
          getline(file, line);
          state.SetAllStates(line);    
        }
        getline(file, initial_state);
        state.SetInitialState(initial_state);      
        getline(file, line);
        converter.clear();
        converter << line;
        converter >> accept_number;
        state.SetAcceptStates(accept_number);
        for (int i = 0; i < accept_number; i++) { 
          getline(file, line);
          state.SetAllAcceptStates(line);        
        }
        getline(file, line);
        converter.clear();
        converter << line;
        converter >> transition_number;
        transition.SetNumberTransitions(transition_number);
        for (int i = 0; i < transition_number; i++) {
          file >> actual_state >> symbol >> next_state;
          Transition transition_states(actual_state,symbol,next_state);
          transition.AddToTransitionSet(transition_states);        
        }          
      }
    }
  }
  file.close();
}

void ReadInputFile(std::string filename, Alphabet& alphabet) {
  std::fstream file;
  std::string line;
  file.open(filename);
  if (file.is_open()) {
    while(getline(file, line)) {
      alphabet.SetAlphabet(line);
    }
  }
  file.close();
}

void WriteOutputFile(std::string filename, Alphabet& alphabet, Dfa& dfa, States& state, Transition& transition) {

  std::ofstream file;
  std::string line;
  std::set<std::string> alphabet_copy = alphabet.GetAlphabet();

  file.open(filename);
  if (file.is_open(), std::fstream::out) {
    for (std::set<std::string>::iterator it = alphabet_copy.begin(); it != alphabet_copy.end(); it++) {
      if(dfa.AlphabetIsAccepted(*it, state, transition) == true) {
        file << *it << " -> Sí" << std::endl;
      }
      else {
        file << *it << " -> No" << std::endl;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  
  if (argc == 1) {
      Error(argc, argv[0]);
      return 0;
  }

  if ((argc < 4) || (argc > 4)) {
    Error(argc, argv[1]);
    return 0;
  }

  std::string kDfa_file = argv[1];
  std::string kInput_file = argv[2];
  std::string kOutput_file = argv[3];
  Dfa dfa;
  States state;
  Transition transition;
  Alphabet alphabet;
  ReadDfaFile(kDfa_file, dfa, state, transition);
  ReadInputFile(kInput_file, alphabet);
  WriteOutputFile(kOutput_file, alphabet, dfa, state, transition);
  
  return 0;
}