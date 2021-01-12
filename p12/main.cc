#include "travel.h"
#include "node.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void ReadFile(std::string filename, Travel& travel) {
  std::fstream file;
  std::string line;
  std::stringstream converter;
  float coste;
  int number_nodes, actual_state, next_state;
  file.open(filename);
    if (file.is_open()) {
      while(getline(file, line)) {
        converter << line;
        converter >> number_nodes; // Número de nodos
        //std::cout << number_nodes << std::endl;
        travel.setNumberNodes(number_nodes);
        while(!file.eof()) {
            file >> actual_state >> next_state >> coste;
            //std::cout << actual_state << " " << next_state << " " << coste << std::endl;
        }
      }
  }
}

int main(int argc, char *argv[]){
if (argc == 1) {
      std::cout << "Un parámetro";
      return 0;
  }
  
 

  std::string infile = argv[1];
  Travel travel;

  ReadFile(infile, travel);
}