#include "graph.hpp"



int main(int argc, char const *argv[])
{
    Graph graph("edges.txt");
    graph.printAdjacencyMatrix();
    graph.printEdges("Edges of graph are:\n");

    auto cover = graph.getEdgeCover();
    graph.printEdges(cover, "cover edge of graph consists of this edges:\n");

    graph.getEdgeCoverNP();
}
