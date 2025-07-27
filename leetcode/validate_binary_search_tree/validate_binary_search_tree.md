# Validate Binary Search Tree
- Medium

## Description
- Given the root of a binary tree, determine if it is a valid binary search tree (BST).

- A valid BST is defined as follows:
    - The left subtree of a node contains only nodes with keys less than the node's key.
    - The right subtree of a node contains only nodes with keys greater than the node's key.
    - Both the left and right subtrees must also be binary search trees.

## Example
### Example 1:

![](./images/validate_binary_search_tree.jpg)

- Input: root = [2,1,3]
- Output: true

### Example 2:

![](./images/validate_binary_search_tree_2.jpg)
- Input: root = [5,1,4,null,null,3,6]
- Output: false
- Explanation: The root node's value is 5 but its right child's value is 4.

### Example 3:
- Input: root = [5,4,6,null,null,3,7]
- Output: false

### Example 4:
- Input: root = [1,null,1]
- Output: false
 
## Constraints:
- The number of nodes in the tree is in the range [1, 104].
- `-231 <= Node.val <= 231 - 1`