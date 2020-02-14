#include "tree.h"

Tree::Tree()
{
    m_value = "";
    m_sonsCount = 0;
    m_sons = nullptr;
}

Tree::Tree(string value, int sonsCount)
{
    m_value = value;
    m_sonsCount = sonsCount;

    m_sons = new Tree[m_sonsCount];
}

string Tree::getValue()
{
    return m_value;
}

bool Tree::addSon(string name, string value, int sonsCount)
{
    if (m_value == name)
    {
        for (int i = 0; i < m_sonsCount; i++)
        {
            if (m_sons[i].m_value == "")
            {
                m_sons[i].m_value = value;
                m_sons[i].m_sonsCount = sonsCount;

                m_sons[i].m_sons = new Tree[sonsCount];
                return true;
            }
        }
        cout << "Error : can't add more sons to " << m_value << endl;
        return true;
    }

    bool result = false;
    for (int i = 0; i < m_sonsCount; i++)
    {
        result = m_sons[i].addSon(name, value, sonsCount);
        if (result == true)
        {
            return result;
        }
    }

    return result;
}

Tree* Tree::find(string value)
{
    if (m_value == value)
    {
        return this;
    }

    Tree* result = nullptr;
    for (int i = 0; i < m_sonsCount; i++)
    {
        result = m_sons[i].find(value);

        if (result != nullptr)
        {
            return result;
        }
    }

    return result;
}