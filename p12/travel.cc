#include "travel.h"

#include <iostream>
#include <limits>
#include <vector>

void Travel::setNumberNodes(int number_nodes) {
  number_nodes_ = number_nodes;
}

void Travel::greedy(Node& node) {
  float minimum_cost = std::numeric_limits<float>::max();
  float total_cost = 0;
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
    }
    
    nodo_inspeccionar = minimum_node; 
    total_cost += minimum_cost;
    nodo_final = nodo_inspeccionar;
    minimum_cost = std::numeric_limits<float>::max();
   
  }

  std::cout << "Nodo final " << nodo_final << " Coste total " << total_cost << std::endl;
}

int Travel::deleteElement(std::vector<std::pair<std::pair<int,int>,float>> vector_nodes, int size, std::pair<std::pair<int,int>,float> element) {
  int i ;
  for (i = 0; i < size; i++){
      if (vector_nodes[i] == element) {
          break;
      }
  }
  
    if (i < size) {
        size = size - 1;
        for (int j = 1; j < size; j++) {
            vector_nodes[j] = vector_nodes[j+1];
        }
    }
    return size;
  }
  