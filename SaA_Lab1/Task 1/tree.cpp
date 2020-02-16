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

void Tree::relationOf(string name1, string name2)
{
    if (name1 == name2)
    {
        cout << "Error : Names must be different" << endl;
    }
    else if (find(name1) == nullptr)
    {
        cout << "Error : There is no person with name " << name1 << endl;
    }
    else if (find(name2) == nullptr)
    {
        cout << "Error : There is no person with name " << name2 << endl;
    }
    else
    {
        _relationOf(name1, name2);
    }
}

int Tree::_relationOf(string name1, string name2)
{
    int count = 0;
    int temp;
    for (int i = 0; i < m_sonsCount; i++)
    {
        temp = m_sons[i]._relationOf(name1, name2);
        if (temp == 2)
        {
            return temp;
        }
        if (temp == 1)
        {
            ++count;
        }
    }

    if (count == 2)
    {
        cout << m_value << " is ancestor of " << name1 << " and " << name2;
    }
    else if (count == 1)
    {
        if (m_value == name1)
        {
            cout << name1 << " is ancestor of " << name2 << endl;
            ++count;
        }
        else if (m_value == name2)
        {
            cout << name2 << " is ancestor of " << name1 << endl;
            ++count;
        }
    }
    else if (m_value == name1 || m_value == name2)
    {
        ++count;
    }

    return count;
}