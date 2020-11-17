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
#include "states.h"

#include <iostream>
#include <string>
#include <fstream>
#include <set>

class Dfa {
private:
    int number_symbols_ = 0;
    std::set<std::string> alphabet_;
    int number_states_;
    friend class States;
    friend class Transition;

public:
    Dfa(void);
    ~Dfa(void);

    void SetNumberSymbols(int number_symbols);
    void SetAlphabet(std::string symbol);

    int GetNumberSymbols();

    void ReadSymbols(std::string kDfa_file);
};


