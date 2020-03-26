#include "MatrixWeight.h"
#define INITIAL_NUM 3

MatrixWeight::MatrixWeight()
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
            if (i == j)
            {
                values[i][j] = 0;
            }
            else
            {
                values[i][j] = -1;
            }
        }
    }

    numOfNodes = INITIAL_NUM;
}

MatrixWeight::MatrixWeight(int num)
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
            if (i == j)
            {
                values[i][j] = 0;
            }
            else
            {
                values[i][j] = -1;
            }        }
    }

    numOfNodes = num;
}

MatrixWeight::~MatrixWeight()
{
    for (int i = 0; i < numOfNodes; i++)
    {
        delete[] values[i];
    }
    delete[] values;
}

bool MatrixWeight::addEdge(int first, int second, int weight)
{
    if (_hasEdge(first, second) == 0)
    {
        if (first != second)
        {
            values[first][second] = weight;
            return true;
        }
    }

    return false;
}

bool MatrixWeight::deleteEdge(int first, int second)
{
    if (_hasEdge(first, second) == 1)
    {
        values[first][second] = -1;
        return true;
    }

    return false;
}

void MatrixWeight::printGraph()
{
    for (int i = 0; i < numOfNodes; i++)
    {
        for (int j = 0; j < numOfNodes; j++)
        {
            if (values[i][j] != -1 && values[i][j] != 0)
            {
                std::cout << "(" << i << ", " << j << ") - " << values[i][j] << std::endl;
            }
        }
    }
}

bool MatrixWeight::hasNode(int node)
{
    if (node >= 0 && node < numOfNodes)
    {
        return true;
    }

    return false;
}

bool MatrixWeight::hasEdge(int first, int second)
{
    return (_hasEdge(first, second) == 1 ? true : false);
}

int MatrixWeight::_hasEdge(int first, int second)
{
    if (first >= 0 && first < numOfNodes && second >= 0 && second < numOfNodes)
    {
        if (values[first][second] > 0)
        {
            return 1;
        }

        return 0;
    }

    return -1;
}