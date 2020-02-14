#include "tree.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    Tree tree = Tree("Oleg", 2);

    tree.addSon("Oleg", "Denis", 3);
    tree.addSon("Denis", "Nikita", 1);
    tree.addSon("Nikita", "Artem", 0);
    tree.addSon("Denis", "Leisan", 0);
    tree.addSon("Denis", "Aleksey", 0);
    tree.addSon("Denis", "Ivan", 3);

    return 0;
}