#ifndef DSAA_BINARY_SEARCH_TREE_HPP_
#define DSAA_BINARY_SEARCH_TREE_HPP_

#include <iostream>

namespace dsaa
{

class Node
{
public:
    int key = 0;
    Node *left_child = nullptr;
    Node *right_child = nullptr;

    Node(int key)
    {
        this->key = key;
    }
};

class Bst
{
private:
    Node *root = nullptr;

public:
    Bst() = default;

    Node *& search(Node *&node_ptr, int key)
    {
        if (node_ptr) 
        {
            if (key == node_ptr->key)
                return node_ptr;

            else if (key < node_ptr->key)
                return search(node_ptr->left_child, key);

            else
                return search(node_ptr->right_child, key);
        }
        
        return node_ptr;
    }

    Node *& search(int key)
    {
        return search(root, key);
    }

    void insert(int key)
    {
        Node *&node_ptr = search(key);

        if (node_ptr != nullptr)
        {
            std::cerr << "key " << key << " has already existed in the tree" << std::endl;        
            return;
        }

        node_ptr = new Node(key);
    }

    void traverse(Node *node_ptr)
    {
        if (node_ptr)
        {
            traverse(node_ptr->left_child);
            std::cout << node_ptr->key << " ";
            traverse(node_ptr->right_child);
        }
    }

    void traverse()
    {
        traverse(root);
        std::cout << std::endl;
    }

    void destruct(Node *node_ptr)
    {
        if (node_ptr)
        {
            destruct(node_ptr->left_child);
            destruct(node_ptr->right_child);
            delete node_ptr;
        }
    }

    ~Bst()
    {
        destruct(root);
    }
};

} // namespace dsaa

#endif // DSAA_BINARY_SEARCH_TREE_HPP_