#include "travel.h"

#include <iostream>
#include <limits>
#include <vector>

void Travel::setNumberNodes(int number_nodes) {
  number_nodes_ = number_nodes;
}

void Travel::greedy(Node& node) {
  float minimum_cost = std::numeric_limits<float>::max();
  int nodo_inicial = node.getFirstNode();
  int nodo_final = 0, nodo_inspeccionar = nodo_inicial, minimum_node;
  int iterator;
  std::vector<std::pair<std::pair<int,int>,float>> vector_nodes = node.getVectorNodes();
  while (nodo_inicial != nodo_final) {
  for (unsigned i = 0; i < node.getVectorSize(); i++) {
      if (vector_nodes[i].first.first == nodo_inspeccionar) {
          if (vector_nodes[i].second < minimum_cost) {
              minimum_cost = vector_nodes[i].second;
              minimum_node = vector_nodes[i].first.second;
          }
      }

      
      std::cout << "coste: " << minimum_cost << "siguiente nodo: " << nodo_inspeccionar << std::endl;
    }
    nodo_inspeccionar = minimum_node; 
  }

/*if (vector_nodes[i].first.second == nodo_inicial) {
          std::cout << "solución" << std::endl;
          nodo_final = nodo_inicial;
      }
      else {
          std::cout << "No solución" << std::endl;
      }*/


/*
    for (unsigned i = 0; i < node.getVectorSize(); i++) {
      std::cout << "(" <<  vector_nodes[i].first.first << ", " <<vector_nodes[i].first.second << ", " << vector_nodes[i].second <<std::endl;

  }*/
  
}