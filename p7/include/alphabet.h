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

