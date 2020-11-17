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
//#include "../include/states.h"
//#include "../include/transition.h"

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
  std::string line, q0;
  std::stringstream converter, converter2;
  int number_symbols, state_number, accept_number, transition_number;
  file.open(filename);

  if (file.is_open()) {
      while(getline(file, line)) {
          if (IsComment(line)) {
              //number_symbols = std::stoi(line);
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
              getline(file, q0);
              state.SetQ0(q0);
              
              getline(file, line);
              converter.clear();
              converter << line;
              converter >> accept_number;
              state.SetAcceptStates(accept_number);
              for (int i = 0; i < state.GetAcceptNumber(); i++) { 
                  getline(file, line);
                  state.SetAllAcceptStates(line);
                  //std::cout << line << std::endl;
              }
              getline(file, line);
              converter.clear();
              converter << line;
              converter >> transition_number;
              transition.SetNumberTransitions(transition_number);
              for (int i = 0; i < transition_number; i++) {
                  
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

void WriteOutputFile(std::string filename, Alphabet& alphabet) {

    std::fstream file;
    std::string line;
    std::set<std::string> alphabet_copy = alphabet.GetAlphabet();

    file.open(filename);
    if (file.is_open()) {
        for (std::set<std::string>::iterator i = alphabet_copy.begin(); i != alphabet_copy.end(); i++) {
            file << *i << '\n';
        }
    }
}

int main(int argc, char *argv[]) {

std::string parameter_command = argv[1];
/*
if ((argc < 4) || (argc > 4)) {
    Error(argc, parameter_command);
    return 0;
}*/
std::string kDfa_file = argv[1];
std::string kInput_file = argv[2];
std::string kOutput_file = argv[3];
Dfa dfa;
States state;
Transition transition;
Alphabet alphabet;
ReadDfaFile(kDfa_file, dfa, state, transition);
ReadInputFile(kInput_file, alphabet);
WriteOutputFile(kOutput_file, alphabet);

return 0;
}