#include "tree.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
    string name;
    int count;

    cout << "Enter the name of root person and number of his descendants: ";
    cin >> name >> count;

    Tree tree = Tree(name, count);

    bool enterStop = false;
    while (!enterStop)
    {   char choice;
        cout << "Do you want to enter more persons? (y/n)\nAnswer: ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
        {
            enterStop = true;
        }
        else if (choice == 'y' || choice == 'Y')
        {
            string ancestor;
            cout << "Enter ancestor's name, name of the person and number of descendants: ";
            cin >> ancestor >> name >> count;

            if (tree.find(name) != nullptr)
            {
                cout << "Error : Person with name " << name << " already exists" << endl;
            }
            else
            {
                tree.addSon(ancestor, name, count);
            }
        }
        else
        {
            cout << "Error : Incorrect choice" << endl;
        }
    }

    return 0;
}