/*
- Práctica 3: Productos capicúa

Centro: Escuela Superior de Ingeniería y Tecnología
Asignatura: Computabilidad y Algoritmia
Año: 2020/2021
Autor: Alejandro Martín de León
Contacto: alu0101015941@ull.edu.es

Fichero: palindrome_prod.cc


Copyright 2020 Alejandro Martín de León
*/
#include <iostream>
#include <cctype>
#include <fstream>

bool isPalindrome(int number) {
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

void outputFile(char *outfile, int i, int j, int resultado) {
    std::ofstream output;
    output.open(outfile, std::fstream::out | std::fstream::app);
    output << i << " * " << j << " = " << resultado << "\n";
}

int main(int argc, char *argv[]) {
  int number = std::atoi(argv[1]);
  char *outfile = argv[2];
  std::remove(outfile);
  if (number <= 0 || isdigit(number) == 1) {
      std::cout << "ERROR: el número introducido es erróneo. Por favor, introduzca un número entero en el rango N > 0" << std::endl;
      return 0;
  }
  int numero_cifras = 1;
  for (int i = 1; i <= number ; i++) {
    numero_cifras *= 10;
  }
  int resultado = 0;
  for (int i = 1; i < numero_cifras; i++) {
    for (int j = 1; j < numero_cifras; j++) {
      resultado = i * j;
      if ((isPalindrome(resultado) == true) && (resultado > 9)) {
        outputFile(outfile, i, j, resultado);
      }
    }
  }
}