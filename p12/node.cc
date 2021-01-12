#include "node.h"

#include <iostream>

bool Node::isVisited() {

  if (visited_ == true) {
    return true;
  }
  else {
    return false;
  }
}

void Node::setNextNodes(int next_node, float cost) {
    next_nodes_vector_.push_back(std::make_pair(next_node,cost));
}