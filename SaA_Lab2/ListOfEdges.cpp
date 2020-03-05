#include "ListOfEdges.h"
#define INITIAL_CAPACITY 5

ListOfEdges::ListOfEdges()
{
    nodes = new int[INITIAL_CAPACITY * 2];
    nodes[0] = -1;
    nodes[1] = -1;
    capacity = INITIAL_CAPACITY;
}

ListOfEdges::~ListOfEdges()
{
    delete[] nodes;
}

int ListOfEdges::getNumberOfEdges()
{
    for (int i = 0; i < capacity; i++)
    {
        if (nodes[i * 2] == -1)
        {
            return i;
        }
    }
    
    return capacity;
}

bool ListOfEdges::grow()
{
    int temp[capacity * 2];

    for (int i = 0; i < capacity * 2; i++)
    {
        temp[i] = nodes[i];
    }

    delete[] nodes;

    capacity *= 2;
    nodes = new int[capacity * 2];
    if (nodes == nullptr)
    {
        return false;
    }

    for (int i = 0; i < capacity / 2; i++)
    {
        nodes[i] = temp[i];
    }

    return true;
}

bool ListOfEdges::addEdge(int first, int second)
{
    if (first < 0 || second < 0)
    {
        return false;
    }

    int size;
    if ((size = getNumberOfEdges()) == capacity)
    {
        bool temp = grow();
        if (!temp)
        {
            return false;
        }
    }
    
    nodes[size * 2] = first;
    nodes[size * 2 + 1] = second;

    if (size < capacity - 1)
    {
        nodes[size * 2 + 2] = -1;
        nodes[size * 2 + 3] = -1;
    }

    return true;
}

bool ListOfEdges::deleteEdge(int first, int second)
{
    if (hasEdge(first, second))
    {
        int i;
        int size;

        for (i = 0; i < (size = getNumberOfEdges()); i++)
        {
            if (nodes[i * 2] == first && nodes[i * 2 + 1] == second)
            {
                nodes[i * 2] = -1;
                nodes[i * 2 + 1] = -1;
                break;
            }
        }

        int temp[2];
        for (; i < size; i++)
        {
            temp[0] = nodes[i * 2];
            temp[1] = nodes[i * 2 + 1];

            nodes[i * 2] = nodes[(i + 1) * 2];
            nodes[i * 2 + 1] = nodes[(i + 1) * 2 + 1];

            nodes[(i + 1) * 2] = temp[0];
            nodes[(i + 1) * 2 + 1] = temp[1];
        }

        return true;
    }
    
    return false;
}

void ListOfEdges::printGraph()
{
    for (int i = 0; i < getNumberOfEdges(); i++)
    {
        std::cout << "(" << nodes[i * 2] << ", " << nodes[i * 2 + 1] << ")" << std::endl;
    }
}

bool ListOfEdges::hasNode(int node)
{
    for (int i = 0; i < getNumberOfEdges(); i++)
    {
        if (nodes[i * 2] == node || nodes[i * 2 + 1] == node)
        {
            return true;
        }
    }

    return false;
}

bool ListOfEdges::hasEdge(int first, int second)
{
    for (int i = 0; i < getNumberOfEdges(); i++)
    {
        if (nodes[i * 2] == first && nodes[i * 2 + 1] == second)
        {
            return true;
        }
    }

    return false;
}

int ListOfEdges::getPlusDegree(int node)
{
    int result = 0;

    for (int i = 0; i < getNumberOfEdges(); i++)
    {
        if (nodes[i * 2] == node)
        {
            ++result;
        }
    }

    return result;
}

int ListOfEdges::getMinusDegree(int node)
{
    int result = 0;

    for (int i = 0; i < getNumberOfEdges(); i++)
    {
        if (nodes[i * 2 + 1] == node)
        {
            ++result;
        }
    }

    return result;
}