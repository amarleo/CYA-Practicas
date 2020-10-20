/*
Copyright 2020 Alejandro Martín de León

- Práctica 3: Productos capicúa

Centro: Escuela Superior de Ingeniería y Tecnología
Asignatura: Computabilidad y Algoritmia
Año: 2020/2021
Autor: Alejandro Martín de León
Contacto: alu0101015941@ull.edu.es

Fichero: palindrome_prod.cc
Este programa contiene el código fuente de la practica.
Este fichero tiene como finalidad solucionar el problema planteado
de los productos capicua. 

- Compilacion: 
Situandonos en el directorio de la práctica, podemos hacer uso del 
programa Make. Bastaria con escribir por pantalla: 
  make

Ademas de esta, tenemos la opcion de compilar:
 $ g++ -std=c++14 -g -Wall -o palindrome_prod palindrome_prod.cc
- Ejecución:
Una vez compilado, procedemos a ejecutar el programa de la siguiente 
manera: 
  ./palindrome [N Cifras] [*.txt]
*/
#include <iostream>
#include <cctype>
#include <fstream>
#include <cmath>

// booleano que comprueba si un numero es capicua
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

// funcion manejo de fichero. Abre y vuelva en el fichero los datos
std::ofstream OutputFile(char *outfile, int i, int j, int resultado) {
    std::ofstream output;
    output.open(outfile, std::fstream::out | std::fstream::app);
    output << i << " * " << j << " = " << resultado << "\n";
    return output;
}

// funcion ayuda, imprime por pantalla el formato correcto de ejecucion del programa
void help() {
  std::cout << "--- AYUDA ---\nPara ejecutar el programa es necesario pasar los siguientes argumentos" << std::endl;
  std::cout << "./palindrome [NUMERO CIFRAS] [FICHERO TXT]" << std::endl;
  std::cout << "- [NUMERO CIFRAS]: Número > 0 a elegir el número de cifras" << std::endl;
  std::cout << "- [FICHERO TXT]: Fichero con la extención .txt, por ejemplo: fichero.txt" << std::endl;
}

// funcion errores, comprueba si se ha producido algun error en la forma de ejecutar el programa
bool ProgramErrors(int number_digits, char *outfile) {
  if (number_digits < 3) {
    std::cout << "ERROR: Argumentos insuficientes" << std::endl;
    help();
    return true;
  } else if (number_digits > 3) {
    std::cout << "ERROR: Se han pasado demasiados argumentos." << std::endl;
    help();
    return true;
  } else {
     if (number_digits <= 0 || isdigit(number_digits) == 1) {
      std::cout << "ERROR: el número introducido es erróneo. Por favor, introduzca un número entero en el rango N > 0" << std::endl;
      return true;
    }
    return false;
  }
}

// funcion que establece el rango minimo, dependiendo del numero de digitos
int MinimumLimit(int number) {
  return pow(10, number-1);
}

// funcion que establece el rango maximo, dependiendo del numero de digitos
int MaximumLimit(int number) {
  return pow(10, number);
}

int main(int argc, char *argv[]) {
  int number_digits = std::atoi(argv[1]);
  char *outfile = argv[2];
  std::remove(outfile);
  if (ProgramErrors(argc, outfile) == true) {
    return 1;
  }

  int maximum_limit = MaximumLimit(number_digits);
  int minimum_limit = MinimumLimit(number_digits);
  int resultado = 0;
  std::ofstream output;

  for (int i = minimum_limit; i < maximum_limit; i++) {
    for (int j = minimum_limit; j < maximum_limit; j++) {
      resultado = i * j;
      if ((IsPalindrome(resultado) == true) && (i <= j)) {
        output = OutputFile(outfile, i, j, resultado);
      }
    }
  }
  output.close();
  return 0;
}
