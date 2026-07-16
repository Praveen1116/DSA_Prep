/* Problem:
   Find the sum of all left leaf nodes in a binary tree.
*/

/* Intuition:
   A left leaf is a node that:
      - is the left child of its parent, and
      - has no left child and no right child.

   While traversing the tree, whenever we find such a node, we add its value
   to the answer. Since left leaves can exist anywhere in the tree, we must
   recursively explore both the left and right subtrees.
*/

/* Approach:
   1. If the current node is NULL, return 0.
   2. Check whether the current node has a left child and whether that left
      child is a leaf node.
      - If yes, add its value to the current sum.
   3. Recursively calculate the sum of left leaves in the left subtree.
   4. Recursively calculate the sum of left leaves in the right subtree.
   5. Return:
         currentSum + leftSum + rightSum

   Time Complexity: O(n)
   Space Complexity: O(h)

   where:
   n = number of nodes in the tree
   h = height of the tree (recursion stack)
*/

Question Link: https://leetcode.com/problems/sum-of-left-leaves/

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;

        int sum = 0;

        if(root->left && root->left->left == NULL && root->left->right == NULL)
        {
            sum += root->left->val;
        }

        int l = sumOfLeftLeaves(root->left);
        int r = sumOfLeftLeaves(root->right);

        return sum+l+r;
    }
};