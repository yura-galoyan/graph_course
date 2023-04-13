
#include <string>
#include <vector>
#include <set>


using Matrix =  std::vector<std::vector <int >>;
using EdgeList = std::vector<std::pair<int,int>>;
using SubsetsType = std::vector<std::vector<std::pair<int,int>>>;

class Graph
{
private:
    EdgeList edges;
    Matrix adjacencyMatrix;
    SubsetsType edgeSubsets;
    
    bool isEmpty = true;
    
    Matrix createAdjacencyMatrix(const std::vector<std::pair<int,int>>& edges, int size);
    SubsetsType getSubsetsOffArray(const EdgeList& list);


    std::set<int> vertexes;


public:
    Graph( std::string pathToInputFile );
    Graph(  );

    void init( std::string pathToInputFile);
    void printAdjacencyMatrix();
    void printSubsets( const SubsetsType& matrix );
    void printEdges(const std::string& msg = "");
    void printEdges(const EdgeList& edges,const std::string& msg = "");


    EdgeList getEdgeCover();
    EdgeList getEdgeCoverNP();


    ~Graph();
};
