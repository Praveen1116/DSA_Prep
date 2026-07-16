/* Problem:
   Return the level order traversal of a binary tree.
*/

/* Intuition:
   In level order traversal, we visit the tree one level at a time, starting
   from the root.

   A queue is the best data structure for this because it follows the
   First In First Out (FIFO) principle. We first process all the nodes of the
   current level, then their children become the next level to process.

   To know where one level ends and the next level begins, we store the
   current size of the queue before processing that level.
*/

/* Approach:
   1. If the tree is empty, return an empty result.
   2. Push the root node into a queue.
   3. While the queue is not empty:
      - Store the current queue size. This represents the number of nodes
        present at the current level.
      - Create a vector to store all the node values of this level.
      - Process exactly 'size' nodes:
          * Remove the front node from the queue.
          * Store its value in the current level.
          * If the node has a left child, push it into the queue.
          * If the node has a right child, push it into the queue.
      - After processing all nodes of the current level, add the level
        vector to the final result.
   4. Return the result containing all levels of the tree.

   Time Complexity: O(n)
   Space Complexity: O(n)

   where:
   n = number of nodes in the tree
*/

Question Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(level);
        }

        return result;
    }
};