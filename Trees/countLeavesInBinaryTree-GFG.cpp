/* Problem:
   Count the total number of leaf nodes in a binary tree.
*/

/* Intuition:
   A leaf node is a node that has no left child and no right child.

   We traverse the entire tree using recursion. Whenever we reach a leaf node,
   we count it as 1. For every other node, we recursively count the leaf nodes
   present in its left and right subtrees and add those counts together.

   Since every subtree is itself a binary tree, the same logic can be applied
   recursively until we reach a NULL node.
*/

/* Approach:
   1. If the current node is NULL, return 0 since there are no leaf nodes.
   2. Recursively count the leaf nodes in the left subtree.
   3. Recursively count the leaf nodes in the right subtree.
   4. If the current node has no left child and no right child, it is a leaf
      node, so return 1.
   5. Otherwise, return the sum of the leaf nodes found in the left and right
      subtrees.

   Time Complexity: O(n)
   Space Complexity: O(h)

   where:
   n = number of nodes in the tree
   h = height of the tree (recursion stack)
*/

Question Link: https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1

// Code:

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        if(root == NULL) return 0;
        
        int x = countLeaves(root->left);
        int y = countLeaves(root->right);
        
        if(root->left == NULL &&  root->right == NULL) return 1;
        
        
        return x+y;
    }
};