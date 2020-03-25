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

    bool res;
    int temp1;
    int temp2;

    graph1.addEdge(0, 1);
    graph1.addEdge(2, 0);

    cout << "Working with graph on list of edges\n----------" << endl;
    cout << "Initial graph:" << endl;
    graph1.printGraph();
    cout << "Edges are entered in format \"<first node> <second node>\"" << endl;

    while (true)
    {
        cout << "Enter edge (or -1 if you want to stop):";

        cin >> temp1;
        if (temp1 == -1)
        {
            break;
        }
        cin >> temp2;

        res = graph1.addEdge(temp1, temp2);
        if (!res)
        {
            cout << "Can't add such edge" << endl;
        }
    }

    graph1.printGraph();

    cout << "Enter node you want to work with: ";
    cin >> temp1;

    cout << "Does graph have this node: " << ((res = graph1.hasNode(temp1)) ? "true" : "false") << endl;
    if (res)
    {
        cout << "Plus degree of this node: " << graph1.getPlusDegree(temp1) << ". ";
        cout << "Minus degree of this node: " << graph1.getMinusDegree(temp1) << endl;

    }


    cout << "Working with graph on vector of adjacency\n----------" << endl;
    cout << "Enter number of nodes: ";
    cin >> temp1;
    if (temp1 < 1)
    {
        cout << "Wrong number of nodes" << endl;
    }

    for (int i = 0; i < temp1; i++)
    {
        graph2.addNode();
    }

    cout << "Edges are entered in format \"<first node> <second node>\"" << endl;

    while (true)
    {
        cout << "Enter edge (or -1 if you want to stop):";

        cin >> temp1;
        if (temp1 == -1)
        {
            break;
        }
        cin >> temp2;

        res = graph2.addEdge(temp1, temp2);
        if (!res)
        {
            cout << "Can't add such edge" << endl;
        }
    }

    graph2.printGraph();

    cout << "Enter edge you want to delete (-1 if don't want): ";
    cin >> temp1;
    if (temp1 != -1)
    {
        cin >> temp2;
        graph2.deleteEdge(temp1, temp2);
        
        graph2.printGraph();
    }

    return 0;
}