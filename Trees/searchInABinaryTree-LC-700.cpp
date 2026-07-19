/*
  Concept to remember
BST Property (Left < Root < Right)
Inorder Traversal gives sorted order
Search follows only one path
Minimum = Leftmost node
Maximum = Rightmost node
Successor = Next Greater
Predecessor = Previous Smaller
Three Deletion Cases
Balanced vs Skewed BST
Average O(log n) vs Worst O(n)
Height vs Depth vs Level
BST Invariant (property must always remain true)
*/


/* Problem:
   Given the root of a Binary Search Tree (BST) and a value, search for the
   node containing that value.

   If the node exists, return it. Otherwise, return NULL.
*/

/* Intuition:
   A Binary Search Tree follows a special property:

      Left Subtree  < Root < Right Subtree

   Because of this property, we never need to search the entire tree.

   - If the target value is smaller than the current node, it can only be
     present in the left subtree.
   - If the target value is greater than the current node, it can only be
     present in the right subtree.

   At every step, we discard half of the remaining search space, making the
   search much more efficient than a normal binary tree search.
*/

/* Approach:
   1. If the current node is NULL,
      the value is not present in the BST.
      Return NULL.

   2. If the current node's value equals the target,
      return the current node.

   3. If the target value is smaller than the current node,
      recursively search the left subtree.

   4. Otherwise,
      recursively search the right subtree.

   5. The recursive call eventually returns either:
      - The node containing the target value.
      - NULL if the value is not found.

   Catching Point:
   The key advantage comes from the BST property:

         Left < Root < Right

   Because of this, we only visit one subtree at each step instead of both.
   This reduces the search space significantly.

   Unlike a normal Binary Tree, where we may have to explore every node,
   a BST allows us to eliminate half of the tree after every comparison.

   Time Complexity:
      - Average Case: O(log n)
      - Worst Case: O(n)
        (when the BST becomes skewed)

   Space Complexity:
      - Average Case: O(log n)
      - Worst Case: O(n)

   due to the recursion stack.
*/

Question Link: https://leetcode.com/problems/search-in-a-binary-search-tree/

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return root;

        if(root->val == val) return root;

        else if(val < root->val)
        {
            return searchBST(root->left, val);
        }

        else
        {
            return searchBST(root->right, val);
        }

        return root;
    }
};