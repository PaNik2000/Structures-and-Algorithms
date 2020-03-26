#ifndef MATRIX_ADJACENCY_H
#define MATRIX_ADJACENCY_H

#include <iostream>
#include <assert.h>

class MatrixAdjacency
{
private:
    int** values;
    int numOfNodes;

    int _hasEdge(int first, int second);
public:
    MatrixAdjacency();
    MatrixAdjacency(int num);
    ~MatrixAdjacency();

    bool addEdge(int first, int second);
    bool deleteEdge(int first, int second);

    void printGraph();

    bool hasNode(int node);
    bool hasEdge(int first, int second);
};

#endif