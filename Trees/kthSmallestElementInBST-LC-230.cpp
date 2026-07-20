/* Problem:
   Given the root of a Binary Search Tree (BST) and an integer k,
   return the kth smallest element in the BST.
*/

/* Intuition:
   A Binary Search Tree has a special property:

        Inorder Traversal → Sorted Order

   When we perform an inorder traversal (Left → Root → Right),
   the node values are visited in ascending order.

   Therefore, after storing the inorder traversal in a vector,
   the kth smallest element will be present at index (k - 1).
*/

/* Approach:
   1. Perform an inorder traversal of the BST.
      - Traverse the left subtree.
      - Store the current node's value.
      - Traverse the right subtree.

   2. Store all visited node values in a vector.

   3. Since the vector is sorted in ascending order,
      return:

            ans[k - 1]

      because vectors use 0-based indexing while k is 1-based.

   Catching Point:
   The most important observation is:

         Inorder Traversal of a BST = Sorted Order

   This property allows us to directly access the kth smallest element
   without performing any additional sorting.

   Another important point is:

         k is 1-based
         vector indexing is 0-based

   Therefore, the kth smallest element is stored at:

         ans[k - 1]

   Time Complexity: O(n)
      - O(n) for inorder traversal.

   Space Complexity: O(n)
      - O(n) for storing the inorder traversal.
*/

Question Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    void inOrder(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL) return;

        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;

        inOrder(root, ans);

        return ans[k-1];
    }
};