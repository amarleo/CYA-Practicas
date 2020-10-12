/*
- Práctica 2: La criba de Erastóstenes

Centro: Escuela Superior de Ingeniería y Tecnología
Asignatura: Computabilidad y Algoritmia
Año: 2020/2021
Autor: Alejandro Martín de León
Contacto: alu0101015941@ull.edu.es

Fichero: erathostenes.cc
Este fichero contiene el código fuente de la Práctica 2 de CyA
Se hace uso de un vector de pares, contenedor de, en primer lugar un entero y en segundo lugar, un booleano,
El objetivo a conseguir es imprimir por pantalla mediante la funcion WriteVector, una lista de números primos.
Se pasa por referencia el número maximo de elementos que contendrá el vector [1..N]


Copyright 2020 Alejandro Martín de León
*/
#include <iostream>
#include <vector>

std::vector<std::pair<int, bool>> CreateVector(int list_size) {
  std::vector< std::pair <int, bool>> number_list;
  for (int i = 0; i < list_size; i++) {
    number_list.push_back({i+1, true});
  }
  return number_list;
}

void WriteVector(std::vector<std::pair<int, bool>> number_list) {
  for (unsigned i = 1; i < number_list.size(); i++) {
    if (number_list[i].second == true)
    std::cout << number_list[i].first << " ";
  }
  std::cout << std::endl;
}

std::vector<std::pair<int, bool>> Remove(std::vector<std::pair<int, bool>> number_list, int i) {
  if (number_list[i-1].second == true) {
    for (unsigned j = i*i; j <= number_list.size(); j += i) {
      number_list[j-1].second = false;
    }
  }
  return number_list;
}

std::vector<std::pair<int, bool>> Sieve(std::vector<std::pair<int, bool>> number_list) {
  for (unsigned i = 2; i*i <= number_list.size(); i++) {
    number_list = Remove(number_list, i);
  }
  return number_list;
}

std::vector<std::pair<int, bool>> DeleteNoPrimes(std::vector<std::pair<int, bool>> number_list) {
  for (unsigned i = 0; i < number_list.size(); i++) {
    if (number_list[i].second == false) {
      number_list.erase(number_list.begin() + i);
    }
  }
  return number_list;
}

int main(int argc, char *argv[]) {
  int max_number = std::atoi(argv[1]);
  std::vector<std::pair<int, bool> > number_list = CreateVector(max_number);
  number_list = Sieve(number_list);
  number_list = DeleteNoPrimes(number_list);
  WriteVector(number_list);
}
