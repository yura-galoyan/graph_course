
#include <string>
#include <vector>
#include <set>
#include <unordered_set>

class Graph{
private:
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

    EdgeList getEdgeCover();
    EdgeList getEdgeCoverNP();

private:
    EdgeList edges;
    Matrix adjacencyMatrix;
    Subsets edgeSubsets;
    
    bool isEmpty = true;
    

    Matrix createAdjacencyMatrix(const std::vector<std::pair<int,int>>& edges, int size);
    Subsets getSubsetsOffArray(const EdgeList& list);
    bool isEdgeCover(const EdgeList&);

    std::set<int> vertexes;


};
