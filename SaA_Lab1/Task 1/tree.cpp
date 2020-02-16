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

bool Tree::add(string name, string value, int sonsCount)
{
    Tree* temp = this->find(name);

    if (temp == nullptr)
    {
        cout << "Error : can't find person with name " << name << endl;
        return false;
    }

    for (int i = 0; i < temp->m_sonsCount; i++)
    {
        if (temp->m_sons[i].m_value == "")
        {
            temp->m_sons[i].m_value = value;
            temp->m_sons[i].m_sonsCount = sonsCount;

            temp->m_sons[i].m_sons = new Tree[sonsCount];
            return true;
        }
    }

    cout << "Error : can't add more sons to " << name << endl;
    return false;
}

Tree* Tree::find(string value)
{
    if (m_value == value)
    {
        return this;
    }

    Tree* result = nullptr;
    for (int i = 0; i < m_sonsCount && m_sons[i].m_value != ""; i++)
    {
        result = m_sons[i].find(value);

        if (result != nullptr)
        {
            return result;
        }
    }

    return result;
}

void Tree::show(int offset)
{
    for (int i = 0; i < offset; i++)
    {
        cout << " ";
    }

    cout << m_value << endl;

    for (int i = 0; i < m_sonsCount && m_sons[i].m_value != ""; i++)
    {
        m_sons[i].show(offset + 1);
    }
}