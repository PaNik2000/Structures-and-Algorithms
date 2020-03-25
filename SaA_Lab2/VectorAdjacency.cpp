#include "VectorAdjacency.h"

VectorAdjacency::VectorAdjacency()
{ }

VectorAdjacency::~VectorAdjacency()
{ }

void VectorAdjacency::addNode()
{
    for (auto i : values)
    {
        if (!i.empty() && i[0] == -1)
        {
            i.clear();
            return;
        }
    }

    values.push_back(vector<int>());
}

void VectorAdjacency::deleteNode(int node)
{
    if (node >= 0 && node < values.size() && values[node][0] != -1)
    {
        values[node].clear();
        values[node].push_back(-1);

        for (auto& i : values)
        {
            std::vector<int>::iterator iter = i.begin(); 
            for (;  iter != i.end(); iter++)
            {
                if (*iter == node)
                {
                    i.erase(iter);
                }
            }
        }
    }
}

bool VectorAdjacency::addEdge(int first, int second)
{
    if (first >= 0 && second >= 0 && first < values.size() && second < values.size())
    {
        if (hasEdge(first, second) == false)
        {
            if (!values[first].empty() && values[first][0] == -1)
            {
                values[first][0] = second;
            }
            else
            {
                values[first].push_back(second);
            }
            return true;
        }
    }

    return false;
}

bool VectorAdjacency::deleteEdge(int first, int second)
{
    if (first < values.size() && first >= 0 && values[first][0] != -1)
    {
        std::vector<int>::iterator iter;
        for (iter = values[first].begin(); iter != values[first].end(); iter++)
        {
            if (*iter == second)
            {
                values[first].erase(iter);

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
        if (values[node].empty() || values[node][0] != -1)
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
            result = values[node].size();
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
    int result = 0;
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