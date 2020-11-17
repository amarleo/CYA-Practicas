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
#include <string>
#include <vector>


class Transition {
private:
    std::string actual_state_;
    std::string next_state_;
    std::string symbol_; 
    int number_transitions_;
    std::vector<Transition> all_transitions_;
    friend class Dfa;
    // set<std::string, std::pair<std::string, std::string>> symbol_states_; Idea para almacenar tanto simbolos como los estados posibles
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

