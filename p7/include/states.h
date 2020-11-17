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
#include "transition.h"

class States {
private:
  int state_number_ = 0;
  int accept_state_ = 0;
  std::set<std::string> all_states_;
  std::set<std::string> all_accept_states_;
  //friend class Dfa;
  std::string q0_;

public:
  States(void);
  ~States(void);

  void SetStateNumber(int state_number);
  void SetAllStates(std::string all_states);
  void SetQ0(std::string q0);
  void SetAcceptStates(int accept_state);
  void SetAllAcceptStates(std::string accept_states);

  int GetStateNumber();
  int GetAcceptNumber();
};






