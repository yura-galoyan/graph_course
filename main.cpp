#include "graph.hpp"
#include <iostream>


int main(int argc, char const *argv[])
{
    Graph graph("edges.txt");
    graph.printAdjacencyMatrix();
    graph.printEdgeList("Edges of graph are:\n");

    auto cover = graph.getEdgeCoverNP();
    graph.printEdgeList(cover,"minimum edge cover is");



}
