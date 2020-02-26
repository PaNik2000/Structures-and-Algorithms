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
    Tree* result = nullptr;

    if (value == m_value)
    {
        result = this;
    }
    else if (value < m_value && m_left != nullptr)
    {
        result = m_left->find(value);
    }
    else if (m_right != nullptr)
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

Tree* Tree::remove(int value)
{
    if (find(value) == nullptr)
    {
        cout << "There is no such element" << endl;
        return this;
    }
    else if(m_value == value)
    {
        if (m_left == nullptr)
        {
            return m_right;
        }
        if (m_right == nullptr)
        {
            return m_left;
        }

        Tree* temp = m_left;
        temp->add(m_right);
        return temp;
    }
    else
    {
        this->_remove(value);
        return this;
    }
}

void Tree::_remove(int value)
{
    if (value < m_value)
    {
        if (m_left->m_value == value)
        {
            if (m_left->m_left == nullptr && m_left->m_right == nullptr)
            {
                delete m_left;
                m_left = nullptr;
            }
            else
            {
                Tree* temp;

                if (m_left->m_left == nullptr && m_left->m_right != nullptr)
                {
                    temp = m_left->m_right;
                }
                else if (m_left->m_left != nullptr && m_left->m_right == nullptr)
                {
                    temp = m_left->m_left;
                }
                else
                {
                    temp = m_left->m_left;
                    temp->add(m_left->m_right);
                }

                delete m_left;
                m_left = temp;
            }
        }
        else
        {
            m_left->_remove(value);
        }
    }
    else
    {
        if (m_right->m_value == value)
        {
            if (m_right->m_left == nullptr && m_right->m_right == nullptr)
            {
                delete m_right;
                m_right = nullptr;
            }
            else
            {
                Tree* temp;

                if (m_right->m_left == nullptr && m_right->m_right != nullptr)
                {
                    temp = m_right->m_right;
                }
                else if (m_right->m_left != nullptr && m_right->m_right == nullptr)
                {
                    temp = m_right->m_left;
                }
                else
                {
                    temp = m_right->m_left;
                    temp->add(m_right->m_right);
                }

                delete m_right;
                m_right = temp;
            }
        }
        else
        {
            m_right->_remove(value);
        }
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int Tree::getDegree()
{
    int result1 = 0;
    int result2 = 0;

    if (m_left != nullptr)
    {
        ++result1;
        result2 = m_left->getDegree();
    }
    if (m_right != nullptr)
    {
        ++result1;
        result2 = max(result2, m_right->getDegree());
    }

    return max(result1, result2);
}

int Tree::numberOfMaxDegree()
{
    return _numberOfDegree(getDegree());
}

int Tree::_numberOfDegree(int degree)
{
    int result = 0;
    int currentDegree = 0;
    if (m_left != nullptr)
    {
        ++currentDegree;
        result += m_left->_numberOfDegree(degree);
    }
    if (m_right != nullptr)
    {
        ++currentDegree;
        result += m_right->_numberOfDegree(degree);
    }

    if (currentDegree == degree)
    {
        ++result;
    }

    return result;
}

int foo(int height)
{
    int result = 0;
    int count = 1;
    
    for (int i = height; i > 2; i--)
    {
        result += count;
        count *= 2;
    }

    return result;
}

int* Tree::getNumberOfSpecialElements()
{
    int height = getHeight();
    if (height > 2)
    {
        int capacity = foo(height);
        int* result = new int[capacity + 1];
        result[0] = 0;
        _getNumberOfSpecialElements(result);

        return result;
    }
    else
    {
        return new int[1]{0};
    }
}

void Tree::_getNumberOfSpecialElements(int* array)
{
    int leftH = (m_left != nullptr ? m_left->getHeight() : 0);
    int rightH = (m_right != nullptr ? m_right->getHeight() : 0);

    if (leftH == rightH && leftH != 0)
    {
        if (m_left->getNumberOfElements() != m_right->getNumberOfElements())
        {
            for (int i = 0; ;i++)
            {
                if (array[i] == 0)
                {
                    array[i] = m_value;
                    array[i + 1] = 0;
                    break;
                }
            }
        }
    }

    if (leftH > 2)
    {
        m_left->_getNumberOfSpecialElements(array);
    }
    if(rightH > 2)
    {
        m_right->_getNumberOfSpecialElements(array);
    }
}