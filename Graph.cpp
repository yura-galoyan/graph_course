
#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <iterator>

Graph::Graph( ){
    
}

Graph::Graph(std::string pathToInputFile ){
    init(pathToInputFile);
}

void Graph::init( std::string pathToInputFile){
    std::ifstream file;
    file.open("../" + pathToInputFile);
    if(!file.is_open()){
        std::cout<<"failed to open file"<<std::endl;
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

Matrix Graph::createAdjacencyMatrix(const std::vector< std::pair<int,int>>& edges,const int size){
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
    for(auto a: adjacencyMatrix){
        std::copy( std::begin(a), std::end(a),std::ostream_iterator<int>{std::cout," "}  );
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
};



void Graph::printEdges(const std::string& msg ){
    std::cout<<msg;
    std::vector<std::string> strVector;
    std::transform(  std::begin(edges), std::end(edges), std::back_inserter(strVector),[](const std::pair<int,int>& elem){
        return std::to_string( elem.first ) + " " + std::to_string(elem.second);
    } );


    std::copy(  std::begin(strVector), std::end(strVector),std::ostream_iterator<std::string>{std::cout,"\n"} );
    std::cout<<std::endl;
}


void Graph::printEdges(const EdgeList& edges,const std::string& msg ){
    
    std::vector<std::string> strVector;
    std::transform(  std::begin(edges), std::end(edges), std::back_inserter(strVector),[](const std::pair<int,int>& elem){
        return std::to_string( elem.first ) + " " + std::to_string(elem.second);
    } );

    std::cout<<msg;
    std::copy(  std::begin(strVector), std::end(strVector),std::ostream_iterator<std::string>{std::cout,"\n"} );
    std::cout<<std::endl;
}


EdgeList Graph::getEdgeCover(){
    
    std::set<int> coveredVertexes;

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

Graph::~Graph(){

}