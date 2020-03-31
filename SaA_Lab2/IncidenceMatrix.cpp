#include "IncidenceMatrix.h"
#define INITIAL_SIZE 3

IncidenceMatrix::IncidenceMatrix()
{
    values = new int*[INITIAL_SIZE];
    for (int i = 0; i < INITIAL_SIZE; i++)
    {
        values[i] = new int;
        *values[i] = 0;
    }

    numOfNodes = INITIAL_SIZE;
    numOfEdges = 0;
}

IncidenceMatrix::IncidenceMatrix(int nodes)
{
    values = new int*[nodes];
    for (int i = 0; i < nodes; i++)
    {
        values[i] = new int;
        *values[i] = 0;
    }

    numOfNodes = nodes;
    numOfEdges = 0;
}

IncidenceMatrix::~IncidenceMatrix()
{
    for (int i = 0; i < numOfNodes; i++)
    {
        delete values[i];
    }

    delete values;
}

bool IncidenceMatrix::addEdge(int first, int second)
{
    if (hasEdge(second, first))
    {
        for (int i = 0; i < numOfEdges; i++)
        {
            if (values[second][i] == -1 && values[first][i] == 1)
            {
                values[second][i] = 1;

                return true;
            }
        }
    }

    if (!hasEdge(first, second))
    {
        int temp[numOfEdges];
        for (int i = 0; i < numOfNodes; i++)
        {
            for (int j = 0; j < numOfEdges; j++)
            {
                temp[j] = values[i][j];
            }

            delete values[i];
            values[i] = new int[numOfEdges + 1];
            for(int j = 0; j < numOfEdges; j++)
            {
                values[i][j] = temp[j];
            }

            if (i == first)
            {
                values[i][numOfEdges] = -1;
            }
            else if (i == second)
            {
                values[i][numOfEdges] = 1;
            }
            else
            {
                values[i][numOfEdges] = 0;
            }
        }

        ++numOfEdges;
        return true;
    }

    return false;
}

bool IncidenceMatrix::deleteEdge(int first, int second)
{
    if (hasEdge(first, second))
    {
        int num;
        for (int i = 0; i < numOfEdges; i++)
        {
            if (vaules[first][i] == 1 && values[second][i] == 1)
            {
                values[second][i] = -1;
                return true;
            }
            if (vaules[first][i] == -1 && values[second][i] == 1)
            {
                num = i;
                break;
            }
        }

        int temp[numOfEdges - 1];
        for (int i = 0; i < numOfNodes; i++)
        {
            for (int j = 0; j < num; j++)
            {
                temp[j] = values[i][j];
            }
            for (int j = num + 1; j < numOfEdges; j++)
            {
                temp[j - 1] = values[i][j];
            }

            delete vaules[i];
            vaules[i] = new int[numOfEdges - 1];

            for (int j = 0; j < numOfEdges - 1; j++)
            {
                values[i][j] = temp[j];
            }
        }

        --numOfEdges;
        return true;
    }

    return false;
}

void IncidenceMatrix::printGraph()
{
    int temp1 = -1;
    int temp2 = -1;

    for (int i = 0; i < numOfEdges; i++)
    {
        for (int j = 0; j < numOfNodes; j++)
        {
            if (temp1 != -1 && temp2 != -1)
            {
                std::cout << "(" << temp1 << ", " << temp2 << ")" << std::endl;
                temp1 = -1;
                temp2 = -1;
                break;
            }
            else if (values[j][i] == -1)
            {
                temp1 = j;
            }
            else if (values[j][i] == 1)
            {
                if (temp2 != -1)
                {
                    temp1 = j;
                    std::cout << "(" << temp1 << ", " << temp2 << ")" << std::endl;
                    std::cout << "(" << temp2 << ", " << temp1 << ")" << std::endl;
                    break;
                }
                else
                {
                    temp2 = j;
                }
            } 
        }
    }
}

void IncidenceMatrix::printMarix()
{
    for (int i = 0; i < numOfNodes; i++)
    {
        for (int j = 0; j < numOfEdges; j++)
        {
            cout << (values[i][j] == -1 ? "" : " ") << values[i][j] << "," << (j == numOfEdges - 1 ? "\n" : " ");
        }
    }
}

bool IncidenceMatrix::hasEdge(int first, int second)
{
    if (hasNode(first) && hasNode(second))
    {
        for (int i = 0; i < numOfEdges; i++)
        {
            if (values[first][i] == -1 && values[second][i] == 1)
            {
                return true;
            }
            if (values[first][i] == 1 && values[second][i] == 1)
            {
                return true;
            }
        }
    }

    return false;
}

bool IncidenceMatrix::hasNode(int node)
{
    if (node >= 0 && node < numOfNodes)
    {
        return true;
    }

    return false;
}