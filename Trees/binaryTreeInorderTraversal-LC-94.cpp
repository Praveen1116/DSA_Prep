/* Problem:
   Return the inorder traversal of a binary tree.
*/

/* Intuition:
   In an inorder traversal, every node is visited in the order:
      Left Subtree → Root → Right Subtree

   Since every node may have its own left and right subtrees, the same process
   must be repeated for each subtree. This naturally fits the concept of
   recursion, where we recursively traverse the left subtree, process the
   current node, and then recursively traverse the right subtree.
*/

/* Approach:
   1. Create a recursive function inOrder(root, res).
   2. If the current node is NULL, simply return since there is nothing to
      traverse.
   3. Recursively traverse the left subtree.
   4. Visit the current node by storing its value in the result vector.
   5. Recursively traverse the right subtree.
   6. Call the recursive function starting from the root and return the
      result vector containing the inorder traversal.

   Time Complexity: O(n)
   Space Complexity: O(h)

   where:
   n = number of nodes in the tree
   h = height of the tree (recursion stack)
*/

Question Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    void inOrder(TreeNode* root, vector<int>& res)
    {
        if(root == NULL) return;

        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);

        return res;
    }
};


// Same logic goes for Preorder and Postorder just little bit of change in recursion(function calling)