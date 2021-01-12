//nodo actual,  número de nodos
//Hacer el algoritmo.
#include <iostream>
#include "node.h"

class Travel {
  private:
    int number_nodes_;
    //friend class Node;

  public:

  void setNumberNodes(int number_nodes);
  void greedy(Node& node);
};