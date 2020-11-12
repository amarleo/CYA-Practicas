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
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <limits>

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
        std::cout << default_long;
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

std::string ToBinary(long natural_number) {
  std::string binary_number;
  
  while (natural_number > 0) {
    if (natural_number % 2 == 0) {
      binary_number.push_back('0');
    }
    else { 
      binary_number.push_back('1');
    }
    natural_number /= 2;
  }
  for (int i = 0 + binary_number.size(); i < 64; i++) {
    binary_number.push_back('0');
  }
  reverse(binary_number.begin(), binary_number.end());
  return binary_number;
}

std::ostream& operator<<(std::ostream& os, Set set_toprint) {
  os << "\n[";
  for (unsigned i = 0; i < set_toprint.long_vector_.size(); i++) {
    os << ToBinary(set_toprint.long_vector_[i]) << ",";
  }
  return os;
}





