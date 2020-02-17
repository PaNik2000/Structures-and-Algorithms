#include "tree.h"

Tree::Tree()
{
    m_value = 0;
    m_left = nullptr;
    m_right = nullptr;
}

Tree::Tree(int value)
{
    m_value = value;
    m_left = nullptr;
    m_right = nullptr;
}

Tree::~Tree()
{ }

int Tree::getValue()
{
    return m_value;
}

void Tree::add(int value)
{
    if (value == m_value)
    {
        cout << "Error : Tree can't have two same elements" << endl;
    }
    else if (value < m_value)
    {
        if (m_left != nullptr)
        {
            m_left->add(value);
        }
        else
        {
            m_left = new Tree(value);
        }
    }
    else
    {
        if (m_right != nullptr)
        {
            m_right->add(value);
        }
        else
        {
            m_right = new Tree(value);
        }
    }
}

void Tree::add(Tree* subTree)
{
    if (subTree->m_value == m_value)
    {
        cout << "Error : Tree can't have two same elements" << endl;
        return;
    }
    if (subTree->m_value > m_value)
    {
        if (m_right == nullptr)
        {
            m_right = subTree;
        }
        else
        {
            m_right->add(subTree);
        }
    }
    else
    {
        if (m_left == nullptr)
        {
            m_left = subTree;
        }
        else
        {
            m_left->add(subTree);
        }
    }
}

Tree* Tree::find(int value)
{
    Tree* result;

    if (value == m_value)
    {
        result = this;
    }
    else if (value < m_value)
    {
        result = m_left->find(value);
    }
    else
    {
        result = m_right->find(value);
    }

    return result;
}

int Tree::getHeight()
{
    int left = 0;
    int right = 0;

    if (m_left != nullptr)
    {
        left = m_left->getHeight();
    }
    if (m_right != nullptr)
    {
        right = m_right->getHeight();
    }
    return (right > left ? right + 1 : left + 1);
}

void Tree::show()
{
    int height = getHeight();
    int num = getNumberOfElements();
    int** matrix = new int*[height];
    for (int i = 0; i < height; i++)
    {
        matrix[i] = new int[num];
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < num; j++)
        {
            matrix[i][j] = 0;
        }
    }

    _show(matrix, 0, 0);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (matrix[i][j] == 0)
            {
                cout << "  ";
            }
            else
            {
                cout <<" " << matrix[i][j];
            }
        }
        cout << "\n";
    }
}


int Tree::_show(int** matrix, int x, int y)
{
    if (m_left != nullptr)
    {
        y = m_left->_show(matrix, x + 1, y);
    }

    matrix[x][y] = m_value;
    y++;

    if (m_right != nullptr)
    {
        y = m_right->_show(matrix, x + 1, y);
    }

    return y;
}

int Tree::getNumberOfElements()
{
    int result = 1;

    result += (m_left != nullptr ? m_left->getNumberOfElements() : 0);
    result += (m_right != nullptr ? m_right->getNumberOfElements() : 0);

    return result;
}

bool Tree::remove(int value)
{
    bool result;

    if (m_left->m_value == value)
    {
        Tree* temp = m_left;
        temp->m_right->add(temp->m_left);
        m_left = temp->m_right;
        delete temp;

        result = true;
    }
    else if (m_right->m_value == value)
    {
        Tree* temp = m_right;
        temp->m_left->add(temp->m_right);
        m_right = temp->m_left;
        delete temp;

        result = true;
    }
    else
    {
        result = m_left->remove(value);
        if (result != true)
        {
            result = m_right->remove(value);
        }
    }

    return result;
}