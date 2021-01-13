#include <iostream>
#include <vector>

class Node {
    private: 
        //vector de vecinos, linea que los une, coste, visitado.
        bool visited_;
        std::vector<std::pair<std::pair<int,int>,float>> nodes_vector_;
        int first_node_;


    public:

    bool isVisited();
    void setNodes(int actual_node, int next_node, float cost); 
    void setFirstNode(int first_node);
    
    std::vector<std::pair<std::pair<int,int>,float>> getVectorNodes();

    int getVectorSize();
    int getFirstNode();

    void writeVectorNodes(std::vector<std::pair<std::pair<int,int>,float>> vector_nodes);
};