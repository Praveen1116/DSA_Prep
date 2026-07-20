/* Problem:
   Given the root of a Binary Search Tree (BST) and a value, insert the value
   into the BST while maintaining the BST property.

   Return the root of the updated BST.
*/

/* Intuition:
   A Binary Search Tree follows the property:

        Left Subtree < Root < Right Subtree

   To insert a new value, we compare it with the current node.

   - If the value is smaller, it must belong to the left subtree.
   - If the value is greater, it must belong to the right subtree.

   We keep moving in the appropriate direction until we reach a NULL node.
   That NULL position is exactly where the new node should be inserted.
*/

/* Approach:
   1. If the current node is NULL,
      create a new node with the given value and return it.

   2. Compare the value with the current node:
      - If val < root->val,
        recursively insert it into the left subtree.
      - Otherwise,
        recursively insert it into the right subtree.

   3. After the recursive call, connect the returned subtree back to the
      current node.

   4. Return the current root so that every recursive call rebuilds the
      original tree structure while including the newly inserted node.

   Catching Point:
   The most important step is:

         root->left = insertIntoBST(root->left, val);

   or

         root->right = insertIntoBST(root->right, val);

   We assign the returned subtree back to the corresponding child because
   the recursive call may create a new node when it reaches a NULL position.

   Returning 'root' from every recursive call reconnects the updated subtree
   to its parent, ensuring the entire BST remains intact.

   Time Complexity:
      - Average Case: O(log n)
      - Worst Case: O(n)

      (Worst case occurs when the BST is skewed.)

   Space Complexity:
      - Average Case: O(log n)
      - Worst Case: O(n)

      due to the recursion stack.
*/

Question Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);

        if(val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};