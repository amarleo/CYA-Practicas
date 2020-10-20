/*
Copyright 2020 Alejandro Martín de León

- Práctica 3: Productos capicúa

Centro: Escuela Superior de Ingeniería y Tecnología
Asignatura: Computabilidad y Algoritmia
Año: 2020/2021
Autor: Alejandro Martín de León
Contacto: alu0101015941@ull.edu.es

Fichero: palindrome_prod.cc
*/
#include <iostream>
#include <cctype>
#include <fstream>
#include <cmath>

bool IsPalindrome(int number) {
  int digit, reverse = 0, number_initial = number;
  do {
      digit = number % 10;
      reverse = (reverse * 10) + digit;
      number = number / 10;
  } while (number != 0);

  if (number_initial == reverse) {
      return true;
  } else {
      return false;
  }
}

void OutputFile(char *outfile, int i, int j, int resultado) {
    std::ofstream output;
    output.open(outfile, std::fstream::out | std::fstream::app);
    output << i << " * " << j << " = " << resultado << "\n";
}

void help() {
  std::cout << "--- AYUDA ---\nPara ejecutar el programa es necesario pasar los siguientes argumentos" << std::endl;
  std::cout << "./palindrome [NUMERO CIFRAS] [FICHERO TXT]" << std::endl;
  std::cout << "- [NUMERO CIFRAS]: Número > 0 a elegir el número de cifras" << std::endl;
  std::cout << "- [FICHERO TXT]: Fichero con la extención .txt, por ejemplo: fichero.txt" << std::endl;
}

bool ProgramErrors(int number_elements, char *outfile) {
  if (number_elements < 3) {
    std::cout << "ERROR: Argumentos insuficientes" << std::endl;
    help();
    return true;
  } else if (number_elements > 3) {
    std::cout << "ERROR: Se han pasado demasiados argumentos." << std::endl;
    help();
    return true;
  } else {
     if (number_elements <= 0 || isdigit(number_elements) == 1) {
      std::cout << "ERROR: el número introducido es erróneo. Por favor, introduzca un número entero en el rango N > 0" << std::endl;
      return true;
    }
    return false;
  }
}

int MinimumLimit(int number) {
  return pow(10, number-1);
}

int MaximumLimit(int number) {
  return pow(10, number);
}

int main(int argc, char *argv[]) {
  int number = std::atoi(argv[1]);
  char *outfile = argv[2];
  std::remove(outfile);
  if (ProgramErrors(argc, outfile) == true) {
    return 1;
  }

  int maximum_limit = MaximumLimit(number);
  int minimum_limit = MinimumLimit(number);
  int resultado = 0;

  for (int i = minimum_limit; i < maximum_limit; i++) {
    for (int j = minimum_limit; j < maximum_limit; j++) {
      resultado = i * j;
      if ((IsPalindrome(resultado) == true) && (i <= j)) {
        OutputFile(outfile, i, j, resultado);
      }
    }
  }

  return 0;
}
