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

bool Travel::isTime(int iterador, int hora_actual, Node& node) {
  std::vector<std::pair<int,int>> time_vector = node.getVectorTime();
  if ((hora_actual > time_vector[iterador].first) && (hora_actual < time_vector[iterador].second)) {
    return true;
  }
  else {
    return false;
  }
}

/**
* @brief Método que efectua el algoritmo greedy
*/

// MODIFICACION
// Actualmente el programa es capaz de obtener, almacenar las horas, además de compararla con una hora actual.
// El vector de tiempo esta ordenado a la par con el vector de pares que contiene los nodos dirigidos y el coste, 
// Por tanto, cada iteración entre ambos vectores coincide.
// Se detallan apuntes para completar el objetivo de la mod satisfactoriamente
void Travel::greedy(Node& node) {
  float minimum_cost = std::numeric_limits<float>::max();
  float total_cost = 0;
  int nodo_inicial = node.getFirstNode();
  int nodo_final = 0, nodo_inspeccionar = nodo_inicial, minimum_node;
  std::string solution = "{" + std::to_string(nodo_inicial) + ",";
  std::vector<std::pair<std::pair<int,int>,float>> vector_nodes = node.getVectorNodes();
  while (nodo_inicial != nodo_final) {
    for (int i = 0; i < node.getVectorSize(); i++) {  //mod: Crear un bucle que establezca la hora actual
      if (vector_nodes[i].first.first == nodo_inspeccionar) {  // mod: Comprobar que la hora coincide && (isTime(i, hora_actual, node))
        if (vector_nodes[i].second < minimum_cost) {  
          minimum_cost = vector_nodes[i].second;
          minimum_node = vector_nodes[i].first.second;
        } // sino coincide la hora, debe realizarse otro ciclo hasta la siguiente hora
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

