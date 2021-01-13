/**
 * PROJECT HEADER
 * @author: Alejandro Martín de León
 * Contact:  alu0101015941@ull.edu.es
 * Subject: Computabilidad y Algoritmia
 * Practice: Numberº12
 * @file: node.cc
 * @date: 13/01/2021
 */
#include "node.h"

#include <iostream>

/**
* @brief Método que introduce en el vector, los pares y flotantes indicados
*/
void Node::setNodes(int actual_node,int next_node, float cost) {
    nodes_vector_.push_back(std::make_pair(std::make_pair(actual_node, next_node), cost));
}

/**
* @brief Método que establece el primer nodo del problema
*/
void Node::setFirstNode(int first_node) {
  first_node_ = first_node;
}

/**
* @brief Método que retorna el vector de nodos.
*/
std::vector<std::pair<std::pair<int,int>,float>> Node::getVectorNodes() {
    return nodes_vector_;
}

/**
* @brief Método que retorna el primer nodo del problema
*/
int Node::getFirstNode() {
  return first_node_;
}

/**
* @brief Método que retorna el tamaño del vector
*/
int Node::getVectorSize() {
  return nodes_vector_.size();
}

/**
* @brief Método auxiliar que escribe el vector de nodos
*/
void writeVectorNodes(std::vector<std::pair<std::pair<int,int>,float>> vector_nodes) {
  for (unsigned i = 0; i < vector_nodes.size(); i++) {
      std::cout << "(" <<  vector_nodes[i].first.first << ", " <<vector_nodes[i].first.second << ", " << vector_nodes[i].second << ")" <<std::endl;
  }
}