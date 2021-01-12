#include <iostream>
#include <vector>


class Node {
    private: 
        //vector de vecinos, linea que los une, coste, visitado.
        bool visited_;
        std::vector<std::pair<int,float>> next_nodes_vector_;


    public:

    bool isVisited();
    void setNextNodes(int next_node, float cost); 
};