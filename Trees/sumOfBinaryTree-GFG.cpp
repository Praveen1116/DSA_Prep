/* Problem:
   Find the sum of all the nodes in a binary tree.
*/

/* Intuition:
   Every node contributes its value exactly once to the total sum.

   For any node, the total sum of its subtree is equal to:
      - the sum of all nodes in its left subtree,
      - the sum of all nodes in its right subtree,
      - the value of the current node.

   Since the left and right subtrees are themselves binary trees, we can apply
   the same logic recursively until we reach a NULL node.
*/

/* Approach:
   1. If the current node is NULL, return 0 since it contributes nothing to
      the sum.
   2. Recursively calculate the sum of the left subtree.
   3. Recursively calculate the sum of the right subtree.
   4. Return:
         leftSum + rightSum + root->data
   5. The recursive call made on the root returns the sum of all nodes in the
      binary tree.

   Time Complexity: O(n)
   Space Complexity: O(h)

   where:
   n = number of nodes in the tree
   h = height of the tree (recursion stack)
*/

Question Link: https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1

// Code:

/* Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int sumBT(Node* root) {
        // code here
        if(root == NULL) return 0;
        
        return sumBT(root->left)+sumBT(root->right)+root->data;
    }
};