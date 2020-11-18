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
#include <string>
#include <set>

class Alphabet {
private:
  std::set<std::string> all_alphabets_;
public:
  Alphabet();
  ~Alphabet();
  
  void SetAlphabet(std::string alphabet);
  int Size();
  std::set<std::string> GetAlphabet();
};

