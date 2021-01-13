//nodo actual,  número de nodos
//Hacer el algoritmo.
#include <iostream>
#include "node.h"

class Travel {
  private:
    int number_nodes_;
  public:
  Travel();
  ~Travel();
  void setNumberNodes(int number_nodes);
  void greedy(Node& node);

};