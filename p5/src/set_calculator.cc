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



int main() {

  
  std::vector<long> test_bench = {1, 3, 70, 129, 130};
  Set A(132, test_bench);
  std::cout << "Tamaño: " << A.GetSize() << std::endl;
  
  test_bench = A.GetVector();

  
  for (unsigned i = 0; i < test_bench.size(); i++) {
    std::cout << test_bench[i] << std::endl;
  
  }
  
return 0;
}