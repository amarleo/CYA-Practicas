#include "travel.h"
//#include "node.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


void ReadFile(std::string filename, Travel& travel, Node& node) {
  std::fstream file;
  std::string line;
  std::stringstream converter;
  float cost;
  std::string string_cost;
  int number_nodes, actual_state, next_state;
  bool first_time = false;
  file.open(filename);
    if (file.is_open()) {
      while(getline(file, line)) {
        converter << line;
        converter >> number_nodes; // Número de nodos
        //std::cout << number_nodes << std::endl;
        travel.setNumberNodes(number_nodes);
        while(!file.eof()) {

          file >> actual_state >> next_state >> string_cost;
          cost = std::stof(string_cost);
          node.setNodes(actual_state, next_state, cost);
          if (first_time == false) {
            node.setFirstNode(actual_state);
            first_time = true;
          }
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
  Node node;

  ReadFile(infile, travel, node);
  travel.greedy(node);
}