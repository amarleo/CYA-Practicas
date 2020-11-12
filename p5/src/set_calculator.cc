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

#include "../include/set.h"
#include <iostream>
#include <fstream>


void ReadFile(char *input_file) {
  std::ifstream file(input_file);
  std::string file_line;
  std::string result_set;
  std::string total_set;
  long long_read;
  std::string const kdelimiters{"{,} "};
  std::string const kdelimiter_final{"}"};
  size_t position = 0, begin;
  int iterator = 0;
  while (std::getline(file, file_line)) {
    while(((begin = file_line.find_first_not_of(kdelimiters, position)) != std::string::npos)) {
      if (file_line[iterator] == '+') {
        break;
      } 
      else {
      position = file_line.find_first_of(kdelimiters, begin + 1);
      long_read = file_line.substr(begin, position - begin);
      
      total_set.push_back(long_read);
      }
    }
    //std::cout << "Primer Conjunto" << result_set << std::endl;
  }
}






int main(int argc, char *argv[]) {

  
  std::vector<long> test_bench = {1, 5, 9};
  Set A(64, test_bench);
  std::cout << "Tamaño: " << A.GetSize() << std::endl;
  
  test_bench = A.GetVector();
/*
  for (unsigned i = 0; i < test_bench.size(); i++) {
    std::cout << test_bench[i] << std::endl;
  }
  */
  ReadFile(argv[1]);
  //std::cout << A << std::endl;
return 0;
}