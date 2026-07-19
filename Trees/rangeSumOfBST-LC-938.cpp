/* Problem:
   Given the root of a Binary Search Tree (BST) and a range [low, high],
   return the sum of all node values that lie within this range (inclusive).
*/

/* Intuition:
   A normal Binary Tree would require visiting every node.

   However, since this is a BST, we can use its property:

        Left Subtree < Root < Right Subtree

   to avoid exploring unnecessary subtrees.

   - If the current node's value is smaller than low, then every node in its
     left subtree is also smaller than low, so we skip the left subtree.
   - If the current node's value is greater than high, then every node in its
     right subtree is also greater than high, so we skip the right subtree.

   This pruning makes the solution much more efficient.
*/

/* Approach:
   1. If the current node is NULL, return 0.

   2. If the current node's value lies within the range [low, high],
      add it to the sum.

   3. If root->val > low,
      recursively search the left subtree because it may still contain
      values within the required range.

   4. If root->val < high,
      recursively search the right subtree because it may also contain
      valid values.

   5. Return the total sum collected from the current node and the
      required subtrees.

   Catching Point:
   The biggest optimization comes from the BST property.

   - If root->val <= low, there is no need to search the left subtree
     because every value there will also be <= root->val < low.

   - If root->val >= high, there is no need to search the right subtree
     because every value there will also be >= root->val > high.

   Instead of visiting every node, we prune the unnecessary subtrees,
   making the solution much faster on a balanced BST.

   Time Complexity:
      - Average Case: O(log n + k)
      - Worst Case: O(n)

      where k is the number of nodes within the given range.

   Space Complexity:
      - Average Case: O(log n)
      - Worst Case: O(n)

   due to the recursion stack.
*/

Question Link: https://leetcode.com/problems/range-sum-of-bst/

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;

        if(root == NULL) return 0;

        if(root->val >= low && root->val <= high)
        {
            sum += root->val;
        }

        if(root->val > low)
        {
            sum += rangeSumBST(root->left, low, high);
        }

        if(root->val < high)
        {
            sum += rangeSumBST(root->right, low, high);
        }

        return sum;
    }
};