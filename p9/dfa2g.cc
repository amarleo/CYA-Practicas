/**
 * \note PROJECT HEADER
 * \note Proyect: DFA
 * \note subject: Computabilidad y Algoritmia
 * \note Author: Alejandro Martín de León
 * \note Contact: alu0101015941@ull.edu.es
 * \note Date: 18/11/2020 
 * \note Copyright 2020 Alejandro Martín de León
*/

#include "dfa.h"
#include "alphabet.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

/**
 * \fn Boolean function that reveals if a string is a comment 
 */
bool IsComment(std::string line){
  if (line[0] != '/' && line[1] != '/') {
    return true;
  }
  else {
    return false;
  }
}

/**
 * \fn Boolean function that prints help to the user
 */

bool Help() {
  std::cout << "Uso: ./dfa2g [ARCHIVO ENTRADA DFA] [ARCHIVO SALIDA GRA]\n" << std::endl;
  std::cout << "Interpretación de los archivos:" <<std::endl;
  std::cout << "-> [ARCHIVO ENTRADA DFA]: Archivo de extensión .dfa que contiene los estados y transiciones del Autómata, así como su alfabeto y respectivos símbolos" << std::endl;
  std::cout << "-> [ARCHIVO SALIDA GRA]: Archivo de extensión .gra sobre el que se volcará el resultado. Si el nombre del fichero no existe, se creará uno nuevo. Sin embargo, si ya existe uno, se sobreescribe." << std::endl;
  return 0;
}

/**
 * \fn Function that controls some common executation errors, also calls to Help() function 
 */

void Error(int parameter_number, std::string parameter_command) {
  if ((parameter_command == "--help") && (parameter_number == 1)) {
    Help();
  } 
  else {
    std::cout << "Modo de empleo: ./dfa2g input.dfa output.gra" << std::endl;
    std::cout << "Pruebe './dfa2g --help' para más información." << std::endl;
  }
}

/**
 * \fn Function that Read a DFA File
 */

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
        converter >> number_symbols;  // Number of symbols
        dfa.SetNumberSymbols(number_symbols);
        for (int i = 0; i < dfa.GetNumberSymbols(); i++) {
          getline(file, line);      
          dfa.SetAlphabet(line);
        }
        getline(file, line);
        converter.clear();
        converter << line;
        converter >> state_number;  // Number of states
        state.SetStateNumber(state_number);
        for (int i = 0; i < state.GetStateNumber(); i++) { 
          getline(file, line);
          state.SetAllStates(line);    
        }
        getline(file, initial_state);
        state.SetInitialState(initial_state);  // Initial State  
        getline(file, line);
        converter.clear();
        converter << line;
        converter >> accept_number;
        state.SetAcceptStates(accept_number);  // Number of Accept States
        for (int i = 0; i < accept_number; i++) { 
          getline(file, line);
          state.SetAllAcceptStates(line);        
        }
        getline(file, line);
        converter.clear();
        converter << line;
        converter >> transition_number;
        transition.SetNumberTransitions(transition_number);  // Number of Transitions
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

/**
 * \fn Function which read the input file, container of the alphabets. 
 */

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

/**
 * \fn Function that prints on the required output file  
 */

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

/**
 * \fn Main function 
 */

int main(int argc, char *argv[]) {

  if (argc == 1) {
      Error(argc, argv[0]);
      return 0;
  }
  
  if ((argc < 3) || (argc > 3)) {
    Error(argc, argv[1]);
    return 0;
  }

  std::string kInput_file = argv[1];
  std::string kOutput_file = argv[2];
  Dfa dfa;
  States state;
  Transition transition;
  Alphabet alphabet;
  ReadDfaFile(kInput_file, dfa, state, transition);
  //ReadInputFile(kInput_file, alphabet);
  WriteOutputFile(kOutput_file, alphabet, dfa, state, transition);
  
  return 0;
}