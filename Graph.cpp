#include "Graph.hpp"

#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <iterator>


Graph::Graph(std::string pathToInputFile ){
    init(pathToInputFile);
}

void Graph::init( std::string pathToInputFile){
    std::ifstream file;
    file.open("../" + pathToInputFile);
    if(!file.is_open()){
        file.open(pathToInputFile);
    }
    if(!file.is_open()){
        throw std::runtime_error("failed to open file");
    }

    int max = std::numeric_limits<int>::min();
    int u = 0,v = 0;
    while(file >> u >> v){
        edges.push_back({u,v});
        max = std::max({max,u,v});
    }
    adjacencyMatrix = createAdjacencyMatrix(edges,max);
    file.close();
    
};

Graph::Matrix Graph::createAdjacencyMatrix(const std::vector< std::pair<int,int>>& edges,const int size){
    std::vector<int> temp;
    Matrix temp1;

    temp.assign(size + 1, 0);
    temp1.assign(size + 1,temp);

    for(const auto& edge: edges ){
        temp1[edge.first][edge.second]+= 1;
        temp1[edge.second][edge.first]+= 1;

        vertexes.insert( edge.first);
        vertexes.insert( edge.second);
    }
    isEmpty = false;
    return temp1;
}
void Graph::printAdjacencyMatrix(){
    if(isEmpty){
        std::cerr<<"graph is empty"<<std::endl;
        return;
    }
    std::cout<<"Adjacency matrix: "<<std::endl;
    for(auto a: adjacencyMatrix){
        std::copy( std::begin(a), std::end(a),std::ostream_iterator<int>{std::cout," "}  );
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
};



void Graph::printEdgeList(const std::string& msg ){
    printEdgeList(edges,msg);
}


void Graph::printEdgeList(const EdgeList& edges,const std::string& msg ){
    
    if(edges.empty()){
        return;
    }
    
    std::cout<<msg;
    std::vector<std::string> strVector;
    std::transform(  std::begin(edges), std::end(edges), std::back_inserter(strVector),[](const std::pair<int,int>& elem){
        return '[' + std::to_string( elem.first ) + " " + std::to_string(elem.second) + ']';
    } );

    std::copy( std::begin(strVector), std::end(strVector),std::ostream_iterator<std::string>{std::cout,"\n"} );
    std::cout<<std::endl;
}

bool Graph::canHaveEdgeCover(){
    for(const auto [u,v]: edges){
        if(u == v) return false;
    }
    return true;
}

auto Graph::getEdgeCoverNP()-> EdgeList{

    if(!canHaveEdgeCover()){
        std::cout<<"Graph doesn't have edge cover"<<std::endl;
        return EdgeList{};
    }

    auto edgeSubsets = getSubsetsOffArray(edges);

    
    EdgeList minEdgeList = getEdgeCoverHeuristics();

    for(const auto& edgeSubset: edgeSubsets)
        if(isEdgeCover(edgeSubset)){
            minEdgeList = minEdgeList.size() > edgeSubset.size() ? edgeSubset : minEdgeList;
        };
    return minEdgeList;
    
}

bool Graph::isEdgeCover(const EdgeList& edgeSubset){

    std::unordered_set<int> coveredVertexes;

    for(const auto& [u,v]: edgeSubset){
        coveredVertexes.insert(u);
        coveredVertexes.insert(v);
    }
    if(coveredVertexes.size() == vertexes.size()) return true;

    return false;
}

Graph::Subsets Graph::getSubsetsOffArray(const EdgeList& list){

    int n = list.size();
    std::vector<std::pair<int,int>> v;
    Subsets subsets;
    subsets.resize(1 << n,v);
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subsets[i].push_back(  list[j]  );
            }
        }
    }

    return subsets;
};


void Graph::printSubsets( const Subsets& subsets ){
    std::cout<< std::string(100,'-')<<std::endl;
    
    for(int i = 0;i< subsets.size(); ++i){
        for(int j = 0;j<subsets[i].size();++j){
            std::cout<<subsets[i][j].first<<" "<<subsets[i][j].second<<"| ";
        }
        std::cout<<std::endl;
    }
  
    std::cout<< std::string(100,'-')<<std::endl;
    
};

auto Graph::getEdgeCoverHeuristics()->EdgeList{
    std::unordered_set<int> coveredVertexes;
    EdgeList cover;
    for(auto edge: edges){
        if(coveredVertexes.count(edge.second) == 0 || coveredVertexes.count(edge.first) == 0  ){
            coveredVertexes.insert(edge.first);
            coveredVertexes.insert(edge.second);
            cover.push_back(edge);
        }
    }
    return cover;
};
