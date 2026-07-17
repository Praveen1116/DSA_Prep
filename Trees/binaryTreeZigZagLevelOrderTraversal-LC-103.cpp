/* Problem:
   Return the Zigzag Level Order Traversal of a binary tree.

   The nodes of the first level are traversed from left to right, the second
   level from right to left, the third level from left to right, and so on.
*/

/* Intuition:
   We traverse the tree level by level using Breadth First Search (BFS), since
   we need to process one level at a time.

   The only difference from a normal level order traversal is the order in
   which we store the nodes of each level.

   Instead of reversing every alternate level after traversing it, we directly
   place each node at its correct position while processing the level. This
   avoids the extra O(n) reversal operation.
*/

/* Approach:
   1. If the tree is empty, return an empty result.

   2. Push the root node into a queue.

   3. Maintain a boolean variable zigZag.
      - true  -> store nodes from left to right.
      - false -> store nodes from right to left.

   4. While the queue is not empty:
      - Store the current queue size, which represents the number of nodes
        in the current level.
      - Create a vector of size 'size' to store the current level.

   5. Process all nodes of the current level:
      - Remove the front node from the queue.
      - Find the correct index:
            If zigZag is true:
                index = i
            Otherwise:
                index = size - 1 - i
      - Store the node value at level[index].
      - Push the left and right children into the queue.

   6. After processing the level:
      - Toggle zigZag.
      - Add the current level to the final result.

   7. Return the result.

   Catching Point:
   A common approach is to perform a normal level order traversal and reverse
   every alternate level.

   In this optimized solution, we avoid reversing the vector. Instead, while
   processing the current level, we directly calculate the correct position
   using:

         index = zigZag ? i : size - 1 - i;

   This stores every node in its final position, eliminating the extra reverse
   operation.

   Time Complexity: O(n)
   Space Complexity: O(n)
*/

Question Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        bool zigZag = true;

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level(size);

            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                int index = zigZag ? i : size - 1 - i;

                level[index] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            zigZag = !zigZag;
            result.push_back(level);
        }

        return result;
    }
};