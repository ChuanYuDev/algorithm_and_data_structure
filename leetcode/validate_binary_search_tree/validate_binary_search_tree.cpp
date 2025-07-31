#include <vector>
#include <map>
#include <iostream>

const int null_num = -232;

// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution is to represent the BST using list
//      If the BST is valid, the list will be in an ascending order
class Solution
{
public:

    void inOrder(TreeNode *root, std::vector<int> &list)
    {
        if (root == nullptr)
            return;

        // Represent the BST value via list
        // Add left subtree to the list
        inOrder(root->left, list);

        // Add root value to the list
        list.push_back(root->val);

        // Add right subtree to the list
        inOrder(root->right, list);
    }

    bool isValidBST(TreeNode *root)
    {
        std::vector<int> list;
        inOrder(root, list);

        // Check if this list is in an ascending order
        for (std::vector<int>::size_type i = 0; i < list.size() - 1; ++i)
        {
            if (list[i] >= list[i + 1])
                return false;
        }

        return true;
    }
};

class SolutionSlow
{
public:
    bool isLess(TreeNode *root, int value)
    {
        if (root == nullptr)
            return true;

        if (root->val >= value)
            return false;
        
        return isLess(root->left, value) && isLess(root->right, value);
    }

    bool isGreater(TreeNode *root, int value)
    {
        if (root == nullptr)
            return true;

        if (root->val <= value)
            return false;
        
        return isGreater(root->left, value) && isGreater(root->right, value);
    }

    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        // All left subtree node value < root value 
        TreeNode *left_ptr = root->left;

        if (left_ptr != nullptr)
        {
            if (!isLess(left_ptr, root->val))
                return false;
        }

        // Right value > root value
        TreeNode *right_ptr = root->right;

        if (right_ptr != nullptr)
        {
            if (!isGreater(right_ptr, root->val))
                return false;
        }

        // Both the left and right subtrees must also be binary search trees.
        return isValidBST(left_ptr) && isValidBST(right_ptr);
    }
};

TreeNode *createTree(std::vector<int> tree_list)
{
    // 0 1 2 3 4 5 6
    // 1 2 -> 0
    // 3 4 -> 1
    // 5 6 -> 2

    int size = tree_list.size();

    if (size == 0)
        return nullptr;

    // If size >= 1
    TreeNode *root;

    // Map
    //      i, node_ptr
    std::map<int, TreeNode *> map;

    int i = 0;
    // Assign tree_list[0] to root
    root = new TreeNode(tree_list[i]);
    map.insert(std::make_pair(i, root));

    // i >= 1
    // The root of i is (i - 1)/2 
    //      if i is odd, it's left node
    //      if i is even, it's right node
    for (; i < size; i++)
    {
        // If value is null, stop creating treenode
        if (tree_list[i] == null_num)
            continue;

        int root_i = (i - 1) / 2;
        TreeNode *parent_i_ptr = map[root_i];
        TreeNode *child_ptr = new TreeNode(tree_list[i]);

        if (i % 2 == 1)
            parent_i_ptr->left = child_ptr;
        else
            parent_i_ptr->right = child_ptr;
        
        map.insert(std::make_pair(i, child_ptr)); 
    }

    return root;    
}

void printTree(TreeNode *root)
{
    // If root is null, print -232
    if (root == nullptr)
    {
        std::cout << null_num << std::endl;
        return;
    }

    // Print root value
    std::cout << root->val << std::endl;

    printTree(root->left);
    printTree(root->right);

}

int main(int argc, char *argv[])
{
    // Use -232 to represent null in the list
    Solution sol;
    std::vector<int> tree_list;
    TreeNode *root;

    // Example 1
    tree_list = {2, 1, 3};

    root = createTree(tree_list);

    std::cout << "Answser: true" << std::endl;
    std::cout << std::boolalpha << "Output: " << sol.isValidBST(root) << std::endl;

    // Example 2
    tree_list = {5, 1, 4, null_num, null_num, 3, 6};

    root = createTree(tree_list);

    std::cout << "Answser: false" << std::endl;
    std::cout << std::boolalpha << "Output: " << sol.isValidBST(root) << std::endl;

    // Example 3
    tree_list = {5, 4, 6, null_num, null_num, 3, 7};

    root = createTree(tree_list);

    std::cout << "Answser: false" << std::endl;
    std::cout << std::boolalpha << "Output: " << sol.isValidBST(root) << std::endl;

    // Example 4
    tree_list = {1, null_num, 1};

    root = createTree(tree_list);

    std::cout << "Answser: false" << std::endl;
    std::cout << std::boolalpha << "Output: " << sol.isValidBST(root) << std::endl;


    printTree(root);
    return 0;
}