#include "dsaa/binary_search_tree.hpp"

int main()
{
    dsaa::Bst bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(1);
    bst.insert(1);
    bst.insert(2);
    bst.insert(10);
    bst.traverse();
    return EXIT_SUCCESS;
}