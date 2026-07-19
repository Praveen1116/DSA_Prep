/* Problem:
   Given the root of a binary tree and two nodes p and q, find their
   Lowest Common Ancestor (LCA).

   The Lowest Common Ancestor is the lowest node in the tree that has both
   p and q as descendants (where a node can be a descendant of itself).
*/

/* Intuition:
   We search for both nodes using recursion.

   While returning from the recursive calls:

   - If both the left and right subtrees return a non-null node, it means
     one target node was found in the left subtree and the other was found
     in the right subtree. Therefore, the current node is their Lowest
     Common Ancestor.

   - If only one subtree returns a non-null node, both target nodes lie in
     that subtree, so we simply propagate that node upward.

   This allows us to find the LCA without storing paths from the root.
*/

/* Approach:
   1. If the current node is NULL, return NULL.

   2. If the current node is either p or q,
      return the current node.

   3. Recursively search for p and q in:
      - Left subtree
      - Right subtree

   4. After both recursive calls:
      - If both leftLCA and rightLCA are not NULL,
        the current node is the Lowest Common Ancestor.
        Return the current node.

      - If only leftLCA is not NULL,
        return leftLCA.

      - Otherwise,
        return rightLCA.

   5. The returned node eventually reaches the initial function call,
      which gives the final Lowest Common Ancestor.

   Catching Point:
   The most important observation is:

   - If both recursive calls return a node,
     the current node is the first point where the paths to p and q meet.

   - If only one recursive call returns a node,
     both target nodes are present in that same subtree, so we continue
     returning that result upward.

   Another important base case is:

         if(root == p || root == q)
             return root;

   This handles the case where one of the target nodes is itself the Lowest
   Common Ancestor.

   Time Complexity: O(n)
   Space Complexity: O(h)

   where h is the height of the tree due to the recursion stack.
*/

Question Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// Code:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root == p || root == q) return root;

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA && rightLCA)
        {
            return root;
        }

        else if(leftLCA != NULL) return leftLCA;

        else return rightLCA;
    }
};