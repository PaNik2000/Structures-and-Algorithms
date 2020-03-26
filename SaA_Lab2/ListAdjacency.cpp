#include "ListAdjacency.h"

ListAdjacency::ListAdjacency()
{ }

ListAdjacency::~ListAdjacency()
{ }

void ListAdjacency::addNode()
{
    for (auto i : values)
    {
        if (!i.empty() && i.front() == -1)
        {
            i.clear();
            return;
        }
    }

    values.push_back(list<int>());
}

void ListAdjacency::deleteNode(int node)
{
    if (hasNode(node))
    {
        list<list<int>>::iterator iter = values.begin();
        advance(iter, node);
        if ((*iter).front() != -1)
        {
            (*iter).clear();
            (*iter).push_back(-1);

            for (auto& i : values)
            {
                list<int>::iterator iter2 = i.begin(); 
                for (; iter2 != i.end(); iter2++)
                {
                    if (*iter2 == node)
                    {
                        i.erase(iter2);
                    }
                }
            }
        }
    }
}

bool ListAdjacency::addEdge(int first, int second)
{
    if (first >= 0 && second >= 0 && first < values.size() && second < values.size())
    {
        if (hasEdge(first, second) == false)
        {
            list<list<int>>::iterator iter = values.begin();
            advance(iter, first);
            if (!(*iter).empty() && (*iter).front() == -1)
            {
               (*iter).front() = second;
            }
            else
            {
                (*iter).push_back(second);
            }
            return true;
        }
    }

    return false;
}

bool ListAdjacency::deleteEdge(int first, int second)
{
    if (hasNode(first))
    {
        list<list<int>>::iterator iter = values.begin();
        advance(iter, first);
        if ((*iter).front() != 1)
        {
            list<int>::iterator iter2;
            for (iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++)
            {
                if (*iter2 == second)
                {
                    (*iter).erase(iter2);

                    return true;
                }
            }
        }
    }

    return false;

}

void ListAdjacency::printGraph()
{
    list<list<int>>::iterator iter = values.begin();
    list<int>::iterator iter2;
    for (int i = 0; iter != values.end(); iter++, i++)
    {
        iter2 = (*iter).begin();
        for (int j = 0; iter2 != (*iter).end(); iter2++, j++)
        {
            std::cout << "(" << i << ", " << j << ")" << std::endl;
        }
    }
}

bool ListAdjacency::hasNode(int node)
{
    if (node >= 0 && node < values.size())
    {
        list<list<int>>::iterator iter = values.begin();
        advance(iter, node);
        if ((*iter).empty() || (*iter).front() != -1)
        {
            return true;
        }
    }

    return false;
}

bool ListAdjacency::hasEdge(int first, int second)
{
    if (first >= 0 && first < values.size())
    {
        list<list<int>>::iterator temp = values.begin();
        advance(temp, first);
        list<int>::iterator iter = (*temp).begin();
        for (; iter != (*temp).end(); iter++)
        {
            if (*iter == second)
            {
                return true;
            }
        }
    }

    return false;
}