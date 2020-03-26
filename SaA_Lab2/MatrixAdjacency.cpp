#include "MatrixAdjacency.h"
#define INITIAL_NUM 3

MatrixAdjacency::MatrixAdjacency()
{
    values = new int*[INITIAL_NUM];
    for (int i = 0; i < INITIAL_NUM; i++)
    {
        values[i] = new int[INITIAL_NUM];
    }

    for(int i = 0; i < INITIAL_NUM; i++)
    {
        for (int j = 0; j < INITIAL_NUM; j++)
        {
            values[i][j] = 0;
        }
    }

    numOfNodes = INITIAL_NUM;
}

MatrixAdjacency::MatrixAdjacency(int num)
{
    assert(num > 0);
    values = new int*[num];
    for (int i = 0; i < num; i++)
    {
        values[i] = new int[num];
    }

    for(int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            values[i][j] = 0;
        }
    }

    numOfNodes = num;
}

MatrixAdjacency::~MatrixAdjacency()
{
    for (int i = 0; i < numOfNodes; i++)
    {
        delete[] values[i];
    }
    delete[] values;
}

bool MatrixAdjacency::addEdge(int first, int second)
{
    if (_hasEdge(first, second) == 0)
    {
        values[first][second] = 1;
        return true;
    }

    return false;
}

bool MatrixAdjacency::deleteEdge(int first, int second)
{
    if (_hasEdge(first, second) == 1)
    {
        values[first][second] = 0;
        return true;
    }

    return false;
}

void MatrixAdjacency::printGraph()
{
    for (int i = 0; i < numOfNodes; i++)
    {
        for (int j = 0; j < numOfNodes; j++)
        {
            if (values[i][j] == 1)
            {
                std::cout << "(" << i << ", " << j << ")" << std::endl;
            }
        }
    }
}

bool MatrixAdjacency::hasNode(int node)
{
    if (node >= 0 && node < numOfNodes)
    {
        return true;
    }

    return false;
}

bool MatrixAdjacency::hasEdge(int first, int second)
{
    return (_hasEdge(first, second) == 1 ? true : false);
}

int MatrixAdjacency::_hasEdge(int first, int second)
{
    if (first >= 0 && first < numOfNodes && second >= 0 && second < numOfNodes)
    {
        if (values[first][second] == 1)
        {
            return 1;
        }

        return 0;
    }

    return -1;
}