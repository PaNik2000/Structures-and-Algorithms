#ifndef TREE_H
#define TREE_H

#include <iostream>

using std::cout;
using std::endl;

class Tree
{
private:
    int m_value;
    Tree* m_left;
    Tree* m_right;

    int _show(int** matrix, int x, int y);
    int getNumberOfElements();

public:
    Tree();
    Tree(int value);
    ~Tree();

    int getValue();

    void add(int value);
    Tree* find(int value);
    int getHeight();

    void show();
};

#endif