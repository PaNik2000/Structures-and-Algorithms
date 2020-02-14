#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream>

using namespace std;
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

    bool addSon(string name, string value, int sonsCount);

    Tree* find(string value);
};

#endif