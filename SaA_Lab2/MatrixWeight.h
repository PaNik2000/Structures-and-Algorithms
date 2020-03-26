#ifndef MATRIX_WEIGHT_H
#define MATRIX_WEIGHT_H

#include <iostream>
#include <assert.h>

class MatrixWeight
{
private:
    int** values;
    int numOfNodes;

    int _hasEdge(int first, int second);
public:
    MatrixWeight();
    MatrixWeight(int num);
    ~MatrixWeight();

    bool addEdge(int first, int second, int weight);
    bool deleteEdge(int first, int second);

    void printGraph();

    bool hasNode(int node);
    bool hasEdge(int first, int second);
};

#endif