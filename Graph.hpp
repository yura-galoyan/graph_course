
#include <string>
#include <vector>
#include <set>

using Matrix =  std::vector<std::vector <int >>;
using EdgeList = std::vector<std::pair<int,int>>;


class Graph
{
private:
    EdgeList edges;
    Matrix adjacencyMatrix;
    bool isEmpty = true;
    
    Matrix createAdjacencyMatrix(const std::vector<std::pair<int,int>>& edges, int size);


    std::set<int> vertexes;


public:
    Graph( std::string pathToInputFile );
    Graph(  );

    void init( std::string pathToInputFile);
    void printAdjacencyMatrix();
    void printEdges(const std::string& msg = "");
    void printEdges(const EdgeList& edges,const std::string& msg = "");
    EdgeList getEdgeCover();


    ~Graph();
};
