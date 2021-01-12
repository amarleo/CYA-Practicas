#include "travel.h"

#include <iostream>
#include <limits>
#include <vector>

void Travel::setNumberNodes(int number_nodes) {
  number_nodes_ = number_nodes;
}

void Travel::greedy(Node& node) {
  float minimum = std::numeric_limits<float>::infinity();
  int nodo_inicial = node.getFirstNode();
  int nodo_final = 0;
  int iterator;
  std::vector<std::pair<std::pair<int,int>,float>> vector_nodes = node.getVectorNodes();
  while (nodo_inicial != nodo_final) {
  
  for (unsigned i = 0; i < node.getVectorSize(); i++) {
      if (vector_nodes[i].first.second == nodo_inicial) {
          std::cout << "solución" << std::endl;
          nodo_final = nodo_inicial;
      }
      else {
          std::cout << "No solución" << std::endl;
      }
    }
  }
   /* for (unsigned i = 0; i < node.getVectorSize(); i++) {
      std::cout << "(" <<  vector_nodes[i].first.first << ", " <<vector_nodes[i].first.second << std::endl;

  }*/

}