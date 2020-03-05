#include <iostream>
#include "ListOfEdges.h"
#include "VectorAdjacency.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv)
{
    ListOfEdges graph1 = ListOfEdges();
    VectorAdjacency graph2 = VectorAdjacency();

    graph1.addEdge(0, 2);
    graph1.addEdge(2, 1);
    graph1.addEdge(0, 3);
    graph1.addEdge(1, 4);
    

    graph2.addNode();
    graph2.addNode();
    graph2.addNode();
    graph2.addNode();
    graph2.addNode();
    
    graph2.addEdge(0, 1);
    graph2.addEdge(2, 1);
    graph2.addEdge(0, 3);
    graph2.addEdge(1, 4);
    
    graph1.printGraph();
    cout << "\n";
    graph2.printGraph();

    return 0;
}