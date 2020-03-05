#ifndef LIST_OF_EDGES_H
#define LIST_OF_EDGES_H

#include <iostream>

class ListOfEdges
{
private:
    int* nodes;
    int capacity;

    int getNumberOfEdges();
    bool grow();
public:
    ListOfEdges();
    ~ListOfEdges();

    bool addEdge(int first, int second);
    bool deleteEdge(int first, int second);
    void printGraph();

    bool hasNode(int node);
    bool hasEdge(int first, int second);

    int getPlusDegree(int node);
    int getMinusDegree(int node);
};

#endif