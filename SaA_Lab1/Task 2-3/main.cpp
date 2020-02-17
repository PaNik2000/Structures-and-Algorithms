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

    return 0;
}