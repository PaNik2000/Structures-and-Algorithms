#include <iostream>
#include "tree.h"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
    int temp;
    cout << "Enter the value of root: ";
    cin >> temp;
    Tree tree = Tree(temp);

    cout << "Enter next value (or '0' if you want to stop): ";
    
    while (true)
    {
        cin >> temp;
        if (temp == 0)
        {
            break;
        }
        tree.add(temp);
        tree.show();
        cout << "Next one: ";
    }

    cout << "Result tree (height = " << tree.getHeight() << "):" << endl;
    tree.show();

    cout << "Enter value which you want to delete: ";
    cin >> temp;
    if (tree.find(temp))
    {
        tree.remove(temp);
        tree.show();
    }
    else
    {
        cout << "There is no such element";
    }

    return 0;
}