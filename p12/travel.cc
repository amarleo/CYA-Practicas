/**
 * PROJECT HEADER
 * @author: Alejandro Martín de León
 * Contact:  alu0101015941@ull.edu.es
 * Subject: Computabilidad y Algoritmia
 * Practice: Numberº12
 * @file: travel.cc
 * @date: 13/01/2021
 */

#include "travel.h"

#include <iostream>
#include <limits>
#include <vector>

Travel::Travel(){}
Travel::~Travel(){}

/**
* @brief Método que establece el número de nodos
*/
void Travel::setNumberNodes(int number_nodes) {
  number_nodes_ = number_nodes;
}

/**
* @brief Método que efectua el algoritmo greedy
*/
void Travel::greedy(Node& node) {
  float minimum_cost = std::numeric_limits<float>::max();
  float total_cost = 0;
  int nodo_inicial = node.getFirstNode();
  int nodo_final = 0, nodo_inspeccionar = nodo_inicial, minimum_node;
  std::string solution = "{" + std::to_string(nodo_inicial) + ",";
  std::vector<std::pair<std::pair<int,int>,float>> vector_nodes = node.getVectorNodes();
  while (nodo_inicial != nodo_final) {
    for (int i = 0; i < node.getVectorSize(); i++) {
      if (vector_nodes[i].first.first == nodo_inspeccionar) {  // Restringe a aquellas iteraciones cuyo origen sea el mismo
        if (vector_nodes[i].second < minimum_cost) {  
          minimum_cost = vector_nodes[i].second;
          minimum_node = vector_nodes[i].first.second;
        }
      }  
    }
    nodo_inspeccionar = minimum_node; 
    total_cost += minimum_cost;
    nodo_final = nodo_inspeccionar;
    solution += std::to_string(nodo_final) + ",";
    minimum_cost = std::numeric_limits<float>::max();
  }
  solution.pop_back();
  solution += "}";
  std::cout << "Camino Solución: " << solution << "\nCoste total: " << total_cost << std::endl;
}

  