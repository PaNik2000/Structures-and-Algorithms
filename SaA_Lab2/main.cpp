#include <iostream>
#include "ListOfEdges.h"
#include "VectorAdjacency.h"
#include "MatrixAdjacency.h"
#include "ListAdjacency.h"
#include "MatrixWeight.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv)
{
    bool res;
    int temp1;
    int temp2;

    cout << "Choose type of structure to work with graph" << endl;
    cout << "1. List of edges." << endl;
    cout << "2. Vector of adjacency." << endl;
    cout << "3. Matrix of adjacency." << endl;
    cout << "4. List of adjacency." << endl;
    cout << "5. Weights matrix." << endl;
    cout << "Your choise: ";
    cin >> temp1;

    if (temp1 == 1)
    {
        ListOfEdges graph = ListOfEdges();

        graph.addEdge(0, 1);
        graph.addEdge(2, 0);

        cout << "Working with graph on list of edges\n----------" << endl;
        cout << "Initial graph:" << endl;
        graph.printGraph();
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

            res = graph.addEdge(temp1, temp2);
            if (!res)
            {
                cout << "Can't add such edge" << endl;
            }
        }

        graph.printGraph();

        cout << "Enter node you want to work with: ";
        cin >> temp1;

        cout << "Does graph have this node: " << ((res = graph.hasNode(temp1)) ? "true" : "false") << endl;
        if (res)
        {
            cout << "Plus degree of this node: " << graph.getPlusDegree(temp1) << ". ";
            cout << "Minus degree of this node: " << graph.getMinusDegree(temp1) << endl;

        }
    }
    else if (temp1 == 2)
    {
        cout << "Working with graph on vector of adjacency\n----------" << endl;
        cout << "Enter number of nodes: ";
        cin >> temp1;
        if (temp1 < 1)
        {
            cout << "Wrong number of nodes" << endl;
        }
        else
        {
            VectorAdjacency graph = VectorAdjacency();

            for (int i = 0; i < temp1; i++)
            {
                graph.addNode();
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

                res = graph.addEdge(temp1, temp2);
                if (!res)
                {
                    cout << "Can't add such edge" << endl;
                }
            }

            graph.printGraph();

            cout << "Enter edge you want to delete (-1 if don't want): ";
            cin >> temp1;
            if (temp1 != -1)
            {
                cin >> temp2;
                graph.deleteEdge(temp1, temp2);
                
                graph.printGraph();
            }
        }
    }
    else if (temp1 == 3)
    {
        cout << "Working with graph on matrix of adjacency\n----------" << endl;
        cout << "Enter number of nodes: ";
        cin >> temp1;
        if (temp1 < 1)
        {
            cout << "Wrong number of nodes" << endl;
        }
        else
        {
            MatrixAdjacency graph = MatrixAdjacency(temp1);

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

                res = graph.addEdge(temp1, temp2);
                if (!res)
                {
                    cout << "Can't add such edge" << endl;
                }
            }

            graph.printGraph();

            cout << "Enter edge you want to delete (-1 if don't want): ";
            cin >> temp1;
            if (temp1 != -1)
            {
                cin >> temp2;
                graph.deleteEdge(temp1, temp2);
                
                graph.printGraph();
            }
        }
    }
    else if (temp1 == 4)
    {

        cout << "Working with graph on list of adjacency\n----------" << endl;
        cout << "Enter number of nodes: ";
        cin >> temp1;
        if (temp1 < 1)
        {
            cout << "Wrong number of nodes" << endl;
        }
        else
        {
            ListAdjacency graph;

            for (int i = 0; i < temp1; i++)
            {
                graph.addNode();
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

                res = graph.addEdge(temp1, temp2);
                if (!res)
                {
                    cout << "Can't add such edge" << endl;
                }
            }

            graph.printGraph();

            cout << "Enter edge you want to delete (-1 if don't want): ";
            cin >> temp1;
            if (temp1 != -1)
            {
                cin >> temp2;
                graph.deleteEdge(temp1, temp2);
                
                graph.printGraph();
            }
        }
    }
    else if (temp1 == 5)
    {
        cout << "Working with graph on weights matrix\n----------" << endl;
        cout << "Enter number of nodes: ";
        cin >> temp1;
        if (temp1 < 1)
        {
            cout << "Wrong number of nodes" << endl;
        }
        else
        {
            MatrixWeight graph = MatrixWeight(temp1);
            int weight;

            cout << "Edges are entered in format \"<first node> <second node>\" and weight of edge on the next line" << endl;

            while (true)
            {
                cout << "Enter nodes of edge (or -1 if you want to stop):";

                cin >> temp1;
                if (temp1 == -1)
                {
                    break;
                }
                cin >> temp2;

                cout << "Enter weigth for this edge: ";
                cin >> weight;

                res = graph.addEdge(temp1, temp2, weight);
                if (!res)
                {
                    cout << "Can't add such edge" << endl;
                }
            }

            graph.printGraph();

            cout << "Enter edge you want to delete (-1 if don't want): ";
            cin >> temp1;
            if (temp1 != -1)
            {
                cin >> temp2;
                graph.deleteEdge(temp1, temp2);
                
                graph.printGraph();
            }
        }
    }
    else
    {
        cout << "Wrong choise." << endl;
    }

    return 0;
}