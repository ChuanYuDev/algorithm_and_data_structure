#include <vector>
#include <queue>
#include <map>
#include <iostream>

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

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> result;
        std::queue<TreeNode *> queue;

        // Check root is nullptr
        if (root == nullptr)
            return result;

        // Add root to the queue
        queue.push(root);

        // queue is not empty
        while (!queue.empty())
        {
            // Based on the queue size n
            int n = queue.size();

            std::vector<int> element_result;

            // The first n elements belong to the level i
            // The other elements belong to the level i + 1
            for (int i = 0; i < n; i++)
            {
                // Retrieve elements from queue 
                TreeNode *node_ptr = queue.front();
                queue.pop();

                // Add element value to the element_result
                element_result.push_back(node_ptr->val);

                // Check node ptr is null
                // Add left and right non-null node ptr to the queue
                if (node_ptr->left != nullptr)
                    queue.push(node_ptr->left);

                if (node_ptr->right != nullptr)
                    queue.push(node_ptr->right);
            }

            result.push_back(element_result);
        }

        return result;
    }
};

const int null_num = -1001;

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
    for (i = 1; i < size; i++)
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

void printResult(std::vector<std::vector<int>> & result)
{
    std::cout << "[";
    for (const auto & element: result)
    {
        std::cout << "[";

        for (const auto & inner_element: element)
        {
            std::cout << inner_element << " ";
        }
        std::cout << "] ";
    }
    std::cout << "] ";
    std::cout << std::endl;
}

int main()
{
    Solution sol;
    std::vector<std::vector<int>> result;
    std::vector<int> tree_list;
    TreeNode *root;

    // Example 1
    tree_list = {3, 9, 20, null_num, null_num, 15, 7};
    root = createTree(tree_list);
    result = sol.levelOrder(root);
    std::cout << "Answser: [[3],[9,20],[15,7]]" << std::endl;

    std::cout << "Output: ";
    printResult(result);

    // Example 2
    tree_list = {1};
    root = createTree(tree_list);
    result = sol.levelOrder(root);
    std::cout << "Answser: [[1]]" << std::endl;

    std::cout << "Output: ";
    printResult(result);

    // Example 3
    tree_list = {};
    root = createTree(tree_list);
    result = sol.levelOrder(root);
    std::cout << "Answser: []" << std::endl;

    std::cout << "Output: ";
    printResult(result);

    printTree(root);
}