#ifndef LIST_ADJACENCY_H
#define LIST_ADJACENCY_H

#include <list>
#include <iostream>

using std::list;

class ListAdjacency
{
private:
    list<list<int>> values;
public:
    ListAdjacency();
    ~ListAdjacency();

    void addNode();
    void deleteNode(int node);
    bool addEdge(int first, int second);
    bool deleteEdge(int first, int second);

    void printGraph();

    bool hasNode(int node);
    bool hasEdge(int first, int second);
};

#endif