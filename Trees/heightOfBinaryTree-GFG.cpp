/* Problem:
   Find the height of a binary tree.
*/

/* Intuition:
   The height of a node is the number of edges in the longest path from that
   node to any leaf node.

   For any node, its height depends on the heights of its left and right
   subtrees. Therefore, we recursively calculate the height of both subtrees,
   take the maximum of the two, and add 1 for the current edge.

   We return -1 for a NULL node so that a leaf node gets a height of 0:
      max(-1, -1) + 1 = 0
*/

/* Approach:
   1. If the current node is NULL, return -1.
   2. Recursively calculate the height of the left subtree.
   3. Recursively calculate the height of the right subtree.
   4. The height of the current node is:
         max(leftHeight, rightHeight) + 1
   5. The recursive call made on the root returns the height of the entire
      binary tree.

   Time Complexity: O(n)
   Space Complexity: O(h)

   where:
   n = number of nodes in the tree
   h = height of the tree (recursion stack)
*/

Question Link: https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

// Code:

/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        // code here
        if(root == NULL) return -1;
        
        int l = height(root->left);
        int r = height(root->right);
        
        return max(l, r) + 1;
    }
};