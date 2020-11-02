/*
- Práctica 5: La Clase Set

Centro: Escuela Superior de Ingeniería y Tecnología
Asignatura: Computabilidad y Algoritmia
Año: 2020/2021
Autor: Alejandro Martín de León
Contacto: alu0101015941@ull.edu.es

Fichero: set.h


Copyright 2020 Alejandro Martín de León
*/
#include <iostream>
#include <vector>

class Set {
private:
  int size_;
  std::vector<long> long_vector_;

public:
  Set(void);  
  Set(int size, std::vector<long> longs_sets);
  ~Set();

  int GetSize(void);  
  std::vector<long> GetVector();

  void SetSize(int size);
  
    
};




