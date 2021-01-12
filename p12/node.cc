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

void Node::setNodes(int actual_node,int next_node, float cost) {
    nodes_vector_.push_back(std::make_pair(std::make_pair(actual_node, next_node), cost));
}

void Node::setFirstNode(int first_node) {
  first_node_ = first_node;
}

std::vector<std::pair<std::pair<int,int>,float>> Node::getVectorNodes() {
    return nodes_vector_;
}

int Node::getFirstNode() {
  return first_node_;
}

int Node::getVectorSize() {
  return nodes_vector_.size();
}