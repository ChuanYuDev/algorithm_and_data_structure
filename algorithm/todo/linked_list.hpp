#ifndef DSAA_LINKED_LIST_HPP_
#define DSAA_LINKED_LIST_HPP_

#include <memory>
#include <iostream>

namespace dsaa
{

struct Node
{
    int key = 0;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node() = default;

    Node(int key)
    {
        this->key = key;
    }
};

class LinkedList
{
private:
    Node *head_ptr_ = nullptr;
    Node *tail_ptr_ = nullptr;

public:
    LinkedList()
    {
        head_ptr_ = new Node();
        tail_ptr_ = new Node();

        head_ptr_->next = tail_ptr_;
        tail_ptr_->prev = head_ptr_;
    }

    ~LinkedList()
    {
        Node *next = nullptr;

        for (Node *node_ptr = head_ptr_; node_ptr;)
        {
            next = node_ptr->next;
            delete node_ptr;
            node_ptr = next;
        }
    }

    Node *insert(Node *node_ptr, int key)
    {
        Node *curr_node_ptr = new Node(key);
        curr_node_ptr->next = node_ptr;
        curr_node_ptr->prev = node_ptr->prev;

        node_ptr->prev->next = curr_node_ptr;
        node_ptr->prev = curr_node_ptr;

        return curr_node_ptr;
    }

    Node * insert(int key)
    {
        return insert(tail_ptr_, key);
    }

    void erase(Node *node_ptr)
    {
        node_ptr->prev->next = node_ptr->next;
        node_ptr->next->prev = node_ptr->prev;

        node_ptr->prev = nullptr;
        node_ptr->next = nullptr;

        delete node_ptr;
    }

    void traverse()
    {
        for (Node *node_ptr = head_ptr_; node_ptr;)
        {
            std::cout << node_ptr->key << " ";
            node_ptr = node_ptr->next;
        }
        std::cout << std::endl;
    }
};

} // namespace dsaa

#endif // DSAA_LINKED_LIST_HPP_