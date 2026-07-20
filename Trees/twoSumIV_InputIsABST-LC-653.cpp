/* Problem:
   Given the root of a Binary Search Tree (BST) and an integer k,
   determine whether there exist two different nodes whose values
   add up to k.
*/

/* Intuition:
   A BST has a very useful property:

        Inorder Traversal → Sorted Order

   We first perform an inorder traversal to store all node values in a
   sorted array.

   Once we have a sorted array, the problem becomes identical to the classic
   "Two Sum in a Sorted Array" problem, which can be solved efficiently using
   the Two Pointer technique.
*/

/* Approach:
   1. Perform an inorder traversal of the BST.
      - Store every node value in a vector.
      - Since it is a BST, the vector will be sorted.

   2. Initialize two pointers:
      - left = 0
      - right = last index of the vector

   3. While left < right:
      - Calculate:
            sum = ans[left] + ans[right]

      - If sum == k,
        return true.

      - If sum < k,
        move the left pointer forward to increase the sum.

      - Otherwise,
        move the right pointer backward to decrease the sum.

   4. If the pointers cross, no such pair exists.
      Return false.

   Catching Point:
   The key observation is that an inorder traversal of a BST always
   produces a sorted sequence.

   This allows us to apply the Two Pointer technique:

   - Moving the left pointer increases the sum.
   - Moving the right pointer decreases the sum.

   Without the BST property, we would first need to sort the elements or
   use a different approach such as a HashSet.

   Time Complexity: O(n)
      - O(n) for inorder traversal.
      - O(n) for the two-pointer search.

   Space Complexity: O(n)
      - O(n) for storing the inorder traversal.
*/

Question Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;

        inOrder(root, ans);
        int left = 0, right = ans.size()-1;

        while(left < right)
        {
            int sum = ans[left]+ans[right];

            if(sum == k)
            {
                return true;
            }

            else if(sum < k) left++;

            else right--;
        }

        return false;
    }
};