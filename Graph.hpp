#ifndef GRAPH_HPP
#define GRAPH_HPP


#include <string>
#include <vector>
#include <set>
#include <unordered_set>

class Graph{
public:
    using Matrix =  std::vector<std::vector <int > >;
    using Edge = std::pair<int,int>;
    using EdgeList = std::vector<Edge>;
    using Subsets = std::vector<EdgeList>;

public:
    Graph(  ) = default;
    Graph( std::string pathToInputFile );

    void init( std::string pathToInputFile);
    void printAdjacencyMatrix();
    void printSubsets( const Subsets& matrix );
    void printEdgeList(const std::string& msg = "");
    void printEdgeList(const EdgeList& edges,const std::string& msg = "");

    EdgeList getEdgeCoverHeuristics();
    EdgeList getEdgeCoverNP();
    inline EdgeList getEdges(){ return edges; };
private:
    
    EdgeList edges;
    Matrix adjacencyMatrix;
    
    bool isEmpty = true;
    
private:
    Matrix createAdjacencyMatrix(const std::vector<std::pair<int,int>>& edges, int size);
    Subsets getSubsetsOffArray(const EdgeList& list);
    bool canHaveEdgeCover();
    bool isEdgeCover(const EdgeList&);

    std::unordered_set<int> vertexes;


};

#endif //GRAPH_HPP