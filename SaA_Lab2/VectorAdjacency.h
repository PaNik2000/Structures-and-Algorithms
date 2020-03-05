#ifndef VECTOR_ADJACENCY_H
#define VECTOR_ADJACENCY_H

#include <vector>
#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;

class VectorAdjacency
{
private:
    vector<vector<int>> values;
public:
    VectorAdjacency();
    ~VectorAdjacency();

    void addNode();
    void deleteNode(int node);
    bool addEdge(int first, int second);
    bool deleteEdge(int first, int second);

    void printGraph();

    bool hasNode(int node);
    bool hasEdge(int first, int second);

    int getPlusDegree(int node);
    int getMinusDegree(int node);
};

#endif