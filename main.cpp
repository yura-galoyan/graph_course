#include "Graph.hpp"

#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
void createDotFile(const Graph::EdgeList& list , const Graph::EdgeList& cover);

int main(int argc, char const *argv[]){
    Graph graph("edges.txt");
    // graph.printAdjacencyMatrix();
    // graph.printEdgeList("Edges of graph are:\n");

    auto cover = graph.getEdgeCoverNP();
    // graph.printEdgeList(cover,"Minimum edge cover is: \n");
    createDotFile(graph.getEdges(), cover);

}


void createDotFile(const Graph::EdgeList& list, const Graph::EdgeList& cover){
    std::ofstream file("../graph.dot");

    file << "graph{\n";

    for(const auto& [u,v]: list){
        file << u <<"--"<<v<<"\n";
    }
    file << "}";
    file.close();
    system("dot -Tpng -O ../graph.dot");
    
};