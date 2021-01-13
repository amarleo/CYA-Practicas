#include <iostream>
#include <vector>

class Node {
    private: 
        std::vector<std::pair<std::pair<int,int>,float>> nodes_vector_;
        int first_node_;
        std::vector<std::pair<int,int>> vector_time_;

    public:
    Node();
    ~Node();
    void setNodes(int actual_node, int next_node, float cost); 
    void setFirstNode(int first_node);
    void setVectorTime(int hora_inicial, int hora_final);
    
    std::vector<std::pair<std::pair<int,int>,float>> getVectorNodes();
    std::vector<std::pair<int,int>> getVectorTime();
    int getVectorSize();
    int getFirstNode();
    

    void writeVectorNodes(std::vector<std::pair<std::pair<int,int>,float>> vector_nodes);
};