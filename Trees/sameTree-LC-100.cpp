/* Problem:
   Check whether two binary trees are identical.
*/

/* Intuition:
   Two binary trees are considered identical if:
      - both have the same structure, and
      - the value of every corresponding node is the same.

   We compare both trees simultaneously using recursion. At every step:
   - If both nodes are NULL, they match.
   - If only one node is NULL, the structures are different.
   - If both nodes exist, their values must be equal, and their left as well
     as right subtrees must also be identical.
*/

/* Approach:
   1. If both nodes are NULL, return true since both trees have ended at the
      same position.
   2. If only one node is NULL, return false because the tree structures are
      different.
   3. Compare the values of the current nodes.
      - If they are different, return false.
   4. Recursively compare:
      - the left subtree of both trees, and
      - the right subtree of both trees.
   5. Return true only if both recursive calls return true.

   Time Complexity: O(n)
   Space Complexity: O(h)

   where:
   n = number of nodes in the tree
   h = height of the tree (recursion stack)
*/

Question Link: https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;

        if(p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        return false;
    }
};