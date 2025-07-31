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

class SolutionDfs
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> result;

        // Travers all the nodes in the tree
        helper(root, 0, result);

        return result;
    }

    void helper(TreeNode *node_ptr, int level, std::vector<std::vector<int>> &result)
    {
        // Get the node level i
        // root -> 0
        // node -> i
        // left and right child -> i + 1

        // Check root is nullptr
        if (node_ptr == nullptr)
            return;

        // 3        level 0
        // 9 20     level 1
        // If result size is equal to level, it shows it's the first time to go to this level
        // Create result element and add it in the result
        int size = result.size();

        if (size == level)
        {
            std::vector<int> result_element;
            result.push_back(result_element);
        }

        // Add node value to result[level] vector
        result[level].push_back(node_ptr->val);

        // Do the recursion to the left node and right node
        helper(node_ptr->left, level + 1, result);
        helper(node_ptr->right, level + 1, result);
    }
};

class SolutionBfs
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

// This solution is also using BFS
//      But the condition to check whether the queue is empty for the same level is way more complicated
//      Compared to SolutionBfs
class SolutionBfsSlow
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        // 3
        // 9 20
        // null null 15 7

        // Initialize?
        std::vector<std::vector<int>> result;
        std::queue<TreeNode *> queue;

        // Check root is nullptr
        if (root == nullptr)
            return result;

        // Add root value to the vector 1 as the level 1
        std::vector<int> result_element = {root->val};
        // Add root ptr to queue (level 1)
        queue.push(root);

        // queue
        // 3
        // 9 20     pop 9 20 first and save them
        // 15 7     push 15 7

        do
        {
            // If not add it to the result and start another iteration
            result.push_back(result_element);
            result_element = {};

            std::vector<TreeNode *> nodes_in_same_level;

            while (!queue.empty())
            {
                // Pop queue one by one
                // Save node ptr to the list
                // Until the queue is empty

                TreeNode *node_ptr = queue.front();
                queue.pop();
                nodes_in_same_level.push_back(node_ptr);
            }

            for (const auto &node: nodes_in_same_level)
            {
                // Add its left and right nodes to the vector 2 as the level 2
                // Add their node ptr to queue (level 2)
                if (node->left != nullptr)
                {
                    result_element.push_back(node->left->val);
                    queue.push(node->left);
                }

                if (node->right != nullptr)
                {
                    result_element.push_back(node->right->val);
                    queue.push(node->right);
                }
            }

        }
        while (!queue.empty());

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
    SolutionBfs sol;
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