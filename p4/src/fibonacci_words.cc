/*
- Práctica 4: Palabras de Fibonacci

Centro: Escuela Superior de Ingeniería y Tecnología
Asignatura: Computabilidad y Algoritmia
Año: 2020/2021
Autor: Alejandro Martín de León
Contacto: alu0101015941@ull.edu.es

Fichero: fibonacci_words.cc


Copyright 2020 Alejandro Martín de León
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

// funcion que comprueba si se trata de un fichero
bool IsFile(char *file) {
    std::string file_str = file;
    std::string aux;
  for (int i = file_str.size() - 1; i > (file_str.size() - 5); i--) {
    aux.push_back(file_str[i]);
  }
  if (aux == "txt.") {
      return true;
  }
  return false;
}

// funcion sobre el formato de fichero
void FileFormatHelp() {

}

// funcion ayuda, imprime por pantalla el formato correcto de ejecucion del programa
void Help() {
  std::cout << "--- AYUDA ---\nPara ejecutar el programa es necesario pasar los siguientes argumentos:" << std::endl;
  std::cout << "\t\t./fibonacci [INPUT_FILE] [OUTPUT_FILE]\n" << std::endl;
  std::cout << "- [INPUT_FILE]: Fichero contenedor de los datos Fibonacci, por ejemplo input.txt" << std::endl;
  std::cout << "- [OUTPUT_FILE]: Fichero contenedor del resultado del programa Fibonacci, por ejemplo output.txt" << std::endl;
}

// funcion errores, comprueba si se ha producido algún eror en la forma de ejecupar el programa
bool ProgramErrors(int number_elements, char *infile, char *outfile) {
  switch (number_elements)
  {
  case 1:
      std::cout << "ERROR: No se ha pasado ninguno de los ficheros requeridos. Por favor, siga la ayuda:";
      help();
      return 1;
      break;
  case 2:
      std::cout << "Únicamente se ha introducido uno de los ficheros requeridos. Por favor, siga la ayuda:";
      help();
      return 1;
      break;
  default:
    IsFile(infile);
    IsFile(outfile);
      break;
  }
}

// Función lectura de fichero
void ReadFile(char *input_file) {
  std::ifstream file(input_file);
  std::string file_line;
 
    file >> file_line;
    std::cout << file_line << std::endl;

  
}

// Función escritura de fichero
void WriteFile() {

}

int main(int argc, char *argv[]) {
  char *input_file = argv[1];
  char *output_file = argv[2];
  ProgramErrors(argc, input_file, output_file);
  ReadFile(input_file);
  
  return 0;
}