/* Problem:
   Given the root of a binary tree, determine whether it is a valid
   Binary Search Tree (BST).

   A valid BST satisfies:
   - Every node in the left subtree is smaller than the current node.
   - Every node in the right subtree is greater than the current node.
   - Both left and right subtrees must also be valid BSTs.
*/

/* Intuition:
   Simply comparing a node with its immediate parent is not enough.

   Every node must satisfy a valid range of values inherited from all of
   its ancestors.

   For each node, we maintain:
      - min -> the smallest value the node is allowed to have.
      - max -> the largest value the node is allowed to have.

   If the node's value falls outside this range, the tree is not a valid BST.

   As we move down the tree:
   - The left child updates the upper bound.
   - The right child updates the lower bound.
*/

/* Approach:
   1. Start from the root with the widest possible range:
         min = LLONG_MIN
         max = LLONG_MAX

   2. For every node:
      - If the node is NULL, return true because an empty tree is valid.
      - If node->val <= min or node->val >= max,
        return false because the BST property is violated.

   3. Recursively validate:
      - Left subtree with range:
            (min, node->val)

      - Right subtree with range:
            (node->val, max)

   4. The tree is a valid BST only if both recursive calls return true.

   Catching Point:
   The biggest mistake is checking only the parent-child relationship.

   Example:

            10
           /  \
          5    15
              /  \
             6    20

   Here, 6 is smaller than 15, but it is also in the right subtree of 10,
   so it should be greater than 10.

   A simple parent-child comparison would incorrectly consider this tree
   valid. Maintaining a valid range for every node correctly detects such
   violations.

   Another important point is using:

         LLONG_MIN and LLONG_MAX

   instead of INT_MIN and INT_MAX.

   This safely handles edge cases where a node's value is INT_MIN or INT_MAX
   without causing incorrect comparisons.

   Time Complexity: O(n)

   Space Complexity:
      - Average Case: O(log n)
      - Worst Case: O(n)

   due to the recursion stack.
*/

Question Link: https://leetcode.com/problems/validate-binary-search-tree/

// Code:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool validate(TreeNode* node, long long min, long long max)
    {
        if(node == NULL) return true;

        if(node->val <= min || node->val >= max) return false;

        return validate(node->left, min, node->val)&&validate(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};