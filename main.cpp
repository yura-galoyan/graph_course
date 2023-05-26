#include "Graph.hpp"

#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
void createDotFile(const Graph::EdgeList& list , const Graph::EdgeList& cover);

int main(int argc, char const *argv[]){
    Graph graph("edges.txt");
    graph.printEdgeList("Edges of graph are:\n");

    auto cover = graph.getEdgeCoverNP();
    graph.printEdgeList(cover,"Minimum edge cover is: \n");
    createDotFile(graph.getEdges(), cover);

}


void createDotFile(const Graph::EdgeList& list, const Graph::EdgeList& cover){
    std::ofstream file("../graph.dot");
    file << "graph{\n";
    for(const auto& edge: list){
        file << edge.first <<"--"<<edge.second;
        if(std::count_if(cover.begin(), cover.end(), [edge](const auto& pair){
            return edge.first == pair.first && edge.second == pair.second;
        }  )){
           file << " [color=red,penwidth=3]";
        }
        file << "\n";
        
        
    }
    file << "}";
    file.close();

    system("dot -Tpng -O ../graph.dot");
#ifdef __linux__
    system("rm ../graph.dot");
#endif
#ifdef _WIN32
    system("del ..\\graph.dot");
#endif

    
};
