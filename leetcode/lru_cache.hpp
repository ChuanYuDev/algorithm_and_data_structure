#ifndef LEETCODE_LRU_CACHE_HPP_
#define LEETCODE_LRU_CACHE_HPP_

#include <unordered_map>

namespace leetcode
{
struct Node
{
    int key = 0;
    int value = 0;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node() = default;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
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

    void insert(Node *node_ptr, Node *curr_node_ptr)
    {
        curr_node_ptr->next = node_ptr;
        curr_node_ptr->prev = node_ptr->prev;

        node_ptr->prev->next = curr_node_ptr;
        node_ptr->prev = curr_node_ptr;
    }

    void insert(Node *node_ptr)
    {
        insert(tail_ptr_, node_ptr);
    }

    Node * erase(Node *node_ptr)
    {
        node_ptr->prev->next = node_ptr->next;
        node_ptr->next->prev = node_ptr->prev;

        node_ptr->prev = nullptr;
        node_ptr->next = nullptr;

        return node_ptr;
    }
    
    Node * erase()
    {
        return erase(head_ptr_->next);
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

class LRUCache
{
private:
    int capacity_ = 0;
    std::unordered_map<int, Node *> key_node_ptr_map_; 
    LinkedList ll;

public:
    LRUCache(int capacity)
    {
        capacity_ = capacity;
    }
    
    int get(int key)
    {
        if (key_node_ptr_map_.find(key) == key_node_ptr_map_.end())
            return -1;
        
        Node *node_ptr = key_node_ptr_map_[key];

        ll.erase(node_ptr);
        ll.insert(node_ptr);

        return node_ptr->value;
    }
    
    void put(int key, int value)
    {
        Node *node_ptr = nullptr;

        if (key_node_ptr_map_.find(key) != key_node_ptr_map_.end())        
        {
            node_ptr = key_node_ptr_map_[key];
            node_ptr->value = value;
            ll.erase(node_ptr);
            ll.insert(node_ptr);
        }
        else
        {
            if (key_node_ptr_map_.size() == static_cast<std::size_t>(capacity_))
            {
                node_ptr = ll.erase();
                key_node_ptr_map_.erase(node_ptr->key);
                delete node_ptr;
            }

            node_ptr = new Node(key, value);
            ll.insert(node_ptr);
            key_node_ptr_map_[key] = node_ptr;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

} // namespace

#endif // LEETCODE_LRU_CACHE_HPP_