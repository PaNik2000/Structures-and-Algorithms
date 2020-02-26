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
    tree = *(tree.remove(temp));
    tree.show();

    cout << "Degree of a tree: " << tree.getDegree() << endl;
    cout << "Number of elements which has degree equals to degree of a tree: " << tree.numberOfMaxDegree() << endl;

    int* nose = tree.getNumberOfSpecialElements();
    if (nose[0] == 0)
    {
        cout << "There is no special elements" << endl;
    }
    else
    {
        cout << "Special elements: ";
        for (int i = 0; nose[i] != 0; i++)
        {
            cout << nose[i];
            if (nose[i + 1] != 0)
            {
                cout << " ";
            }
            else
            {
                cout << "\n";
            }
        }
    }

    return 0;
}