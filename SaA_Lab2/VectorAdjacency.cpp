#include "VectorAdjacency.h"

VectorAdjacency::VectorAdjacency()
{ }

VectorAdjacency::~VectorAdjacency()
{ }

void VectorAdjacency::addNode()
{
    for (auto i : values)
    {
        if (i[0] == -1)
        {
            i.clear();
            return;
        }
    }

    values.push_back({});
}

void VectorAdjacency::deleteNode(int node)
{
    if (node >= 0 && node < values.size() && values[node][0] != -1)
    {
        values[node].clear();
        values[node].push_back(-1);

        for (auto& i : values)
        {
            for (auto& j : i)
            {
                if (j == node)
                {
                    i.erase(j);
                }
            }
        }
    }
}

bool VectorAdjacency::addEdge(int first, int second)
{
    if (first >= 0 && first < values.size() && values[first][0] != -1)
    {
        values[first].push_back(second);

        return true;
    }

    return false;
}

bool VectorAdjacency::deleteEdge(int first, int second)
{
    if (first < values.size() && first >= 0 && values[first][0] != -1)
    {
        for (auto& i : values[first])
        {
            if (i == second)
            {
                values[first].erase(i)

                return true;
            }
        }
    }

    return false;

}

void VectorAdjacency::printGraph()
{
    for (int i = 0; i < values.size(); i++)
    {
        for (int j : values[i])
        {
            cout << "(" << i << ", " << j << ")" << endl;
        }
    }
}

bool VectorAdjacency::hasNode(int node)
{
    if (node >= 0 && node < values.size())
    {
        if (values[node] != -1)
        {
            return true;
        }
    }

    return false;
}

bool VectorAdjacency::hasEdge(int first, int second)
{
    if (first >= 0 && first < values.size())
    {
        for (int i : values[first])
        {
            if (i == second)
            {
                return true;
            }
        }
    }

    return false;
}

int VectorAdjacency::getPlusDegree(int node)
{
    int result = 0;

    if (node >= 0 && node < values.size())
    {
        if (values[node][0] != -1)
        {
            result = vaules[node].size();
        }
        else
        {
            result = -1;
        }
    }
    else
    {
        result = -1;
    }

    return result;
}

int VectorAdjacency::getMinusDegree(int node)
{
    result = 0;
    if (node >= 0 && node < values.size() && values[node][0] != -1)
    {
        for (auto i : values)
        {
            for (auto j : i)
            {
                if (j == node)
                {
                    ++result;
                }
            }
        }
    }
    else
    {
        result = -1;
    }

    return result;
}