#include <iostream>
#include "ListOfEdges.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv)
{
    ListOfEdges graph = ListOfEdges();

    graph.insertEdge(1, 2);
    graph.insertEdge(2, 3);
    graph.insertEdge(1, 3);
    graph.insertEdge(1, 4);

    graph.deleteEdge(2, 3);
    if (!graph.deleteEdge(3, 4))
    {
        cout << "No such edge" << endl;
    }

    graph.printGraph();

    return 0;
}