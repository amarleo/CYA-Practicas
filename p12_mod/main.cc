/**
 * PROJECT HEADER
 * @author: Alejandro Martín de León
 * Contact:  alu0101015941@ull.edu.es
 * Subject: Computabilidad y Algoritmia
 * Practice: Numberº12
 * @file: main.cc
 * @date: 13/01/2021
 */
#include "travel.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

bool Help() {
  std::cout << "---USO DEL PROGRAMA---" << std::endl;
  std::cout << "Uso: ./greedy [ARCHIVO ENTRADA GREEDY]\n" << std::endl;
  std::cout << "Interpretación de los archivos:" <<std::endl;
  std::cout << "-> [ARCHIVO ENTRADA GREEDY]: Archivo de entrada que contiene los nodos, así como el coste para cada uno de los desplazamientos. Un formato aceptado sería el siguiente" << std::endl;
  std::cout << "3\t\t// Número de ciudades\n1 2 3.4\t\t// Ciudad_origen, Ciudad_destino, Peso" << std::endl;
  return 0;
}

/**
* @brief Método lectura de fichero
*/
void ReadFile(std::string filename, Travel& travel, Node& node) {
  std::fstream file;
  std::string line;
  std::stringstream converter;
  float cost;
  std::string string_cost;
  int number_nodes, actual_state, next_state, hora_inicial, hora_final;
  bool first_time = false;
  file.open(filename);
    if (file.is_open()) {
      while(getline(file, line)) {
        converter << line;
        converter >> number_nodes; // Número de nodos
        travel.setNumberNodes(number_nodes);
        while(!file.eof()) {
          file >> actual_state >> next_state >> string_cost >> hora_inicial >> hora_final; 
          cost = std::stof(string_cost);  // Transforma el string en float
          node.setNodes(actual_state, next_state, cost);  
          if (first_time == false) {
            node.setFirstNode(actual_state); 
            first_time = true;
          }
        }
      }
  }
}

/**
* @brief Progama principal
*/
int main(int argc, char *argv[]){
if (argc != 2) {
      Help();
      return 0;
  }
  std::string infile = argv[1];
  Travel travel;
  Node node;
  ReadFile(infile, travel, node);
  travel.greedy(node);
}