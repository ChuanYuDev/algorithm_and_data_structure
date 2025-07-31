#include "dsaa/linked_list.hpp"

int main()
{
    dsaa::LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    auto node_ptr = ll.insert(4);
    ll.traverse();

    ll.erase(node_ptr);
    ll.traverse();
    return EXIT_SUCCESS;
}