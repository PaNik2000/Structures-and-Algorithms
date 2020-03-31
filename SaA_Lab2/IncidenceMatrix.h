#ifndef INCIDENCE_MATRIX_H
#define INCIDENCE_MATRIX_H

#include <iostream>

class IncidenceMatrix
{
private:
    int** values;
    int numOfNodes;
    int numOfEdges;
public:
    IncidenceMatrix();
    IncidenceMatrix(int nodes);
    ~IncidenceMatrix();

    bool addEdge(int first, int second);
    bool deleteEdge(int first, int second);

    void printGraph();
    void printMatrix();

    bool hasNode(int node);
    bool hasEdge(int first, int second);
};

#endif