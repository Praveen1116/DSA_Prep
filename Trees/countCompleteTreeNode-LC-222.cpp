/* Problem:
   Count the total number of nodes present in a binary tree.
*/

/* Intuition:
   Every node contributes exactly one to the total count. Therefore, for any
   node, the total number of nodes in its subtree is equal to:
      - the current node itself (1),
      - the number of nodes in its left subtree,
      - the number of nodes in its right subtree.

   Since the left and right subtrees are themselves binary trees, the same
   logic can be applied recursively until we reach a NULL node.
*/

/* Approach:
   1. If the current node is NULL, return 0 since there are no nodes to count.
   2. Recursively count the nodes in the left subtree.
   3. Recursively count the nodes in the right subtree.
   4. Add 1 for the current node and return:
         1 + leftCount + rightCount
   5. The recursive call made on the root returns the total number of nodes
      in the entire binary tree.

   Time Complexity: O(n)
   Space Complexity: O(h)

   where:
   n = number of nodes in the tree
   h = height of the tree (recursion stack)
*/

Question Link: https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};