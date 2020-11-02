/*
- Práctica 5: La Clase Set

Centro: Escuela Superior de Ingeniería y Tecnología
Asignatura: Computabilidad y Algoritmia
Año: 2020/2021
Autor: Alejandro Martín de León
Contacto: alu0101015941@ull.edu.es

Fichero: set.cc


Copyright 2020 Alejandro Martín de León
*/
#include "../include/set.h"
#include <iostream>

Set::Set(void) {
  size_ = 8 * sizeof(long);
}

Set::Set(int size, std::vector<long> longs_sets) {
  size_ = size;
  long start = 1, end = 64;
  while(size > 0) {
    long number_long = 0;
    for (unsigned i = 0; i < longs_sets.size(); i++) {
    if ((longs_sets[i] >= start) && (longs_sets[i] <= end)) {
        long default_long = 1;
        default_long <<= longs_sets[i] - 1; //Muevo las posiciones del long por defecto
        number_long |= default_long;
      }
    }
    start += 64;
    end += 64;
    long_vector_.push_back(number_long);
    size -= 64;
  }
}

Set::~Set() {
}

int Set::GetSize(void) {
  return size_;
}

std::vector<long> Set::GetVector() {
  return long_vector_;
}

void Set::SetSize(int size) {
  size_ = size;
}






