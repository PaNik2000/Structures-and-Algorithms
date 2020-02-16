#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Tree
{
private:
    string m_value;
    int m_sonsCount;
    Tree* m_sons;
public:

    Tree();
    Tree(string value, int sonsCount);

    string getValue();
    // void setValue(string value);
    // int getSonsCount();

    bool add(string name, string value, int sonsCount);

    Tree* find(string value);

    void show(int offset = 0);
};

#endif