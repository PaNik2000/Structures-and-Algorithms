#include <iostream>
#include "tree.h"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
    Tree tree = Tree(7);

    tree.add(3);
    tree.add(5);
    tree.add(4);
    tree.add(32);
    tree.add(24);
    tree.add(45);

    tree.show();

    tree.add(5);

    cout << "Height of the tree: " << tree.getHeight() << endl;

    return 0;
}