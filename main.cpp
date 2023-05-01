#include "graph.hpp"
#include <iostream>


int main(int argc, char const *argv[])
{
    Graph graph("edges.txt");
    graph.printAdjacencyMatrix();
    graph.printEdgeList("Edges of graph are:\n");

    auto cover = graph.getEdgeCover();
    graph.printEdgeList(cover, "cover edge of graph consists of this edges:\n");

    auto a = graph.getEdgeCoverNP();



}
