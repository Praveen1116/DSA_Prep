/* Problem:
   Return the Boundary Traversal of a binary tree in anti-clockwise order.

   The boundary consists of:
   1. Root node
   2. Left boundary (excluding leaf nodes)
   3. All leaf nodes (from left to right)
   4. Right boundary (excluding leaf nodes) in reverse order
*/

/* Intuition:
   The boundary of a binary tree can be divided into three independent parts.

   Instead of trying to traverse the entire boundary in one traversal, it is
   much simpler to solve each part separately:

   - Traverse the left boundary.
   - Traverse all the leaf nodes.
   - Traverse the right boundary in reverse order.

   Finally, combine all these parts to obtain the complete boundary traversal.
*/

/* Approach:
   1. If the tree is empty, return an empty result.

   2. Add the root node to the answer.

   3. Traverse the left boundary:
      - Start from root->left.
      - Add every non-leaf node.
      - Prefer moving to the left child.
      - If the left child doesn't exist, move to the right child.

   4. Traverse all leaf nodes:
      - Perform a DFS.
      - Whenever a leaf node is found, add it to the answer.
      - Traverse the left subtree first, then the right subtree to maintain
        left-to-right order.

   5. Traverse the right boundary:
      - Start from root->right.
      - Prefer moving to the right child.
      - If the right child doesn't exist, move to the left child.
      - Add nodes after the recursive call so they are stored in reverse
        order (bottom to top).

   6. Return the final result.

   Catching Point:
   Leaf nodes must not be included in either the left or right boundary
   traversal.

   Otherwise, they would appear twice:
   - Once during boundary traversal.
   - Again during leaf traversal.

   Also, notice that in the right boundary traversal, nodes are added after
   the recursive call:

         rightTraversal(child);
         ans.push_back(root->data);

   This naturally stores the right boundary in reverse order, eliminating the
   need to reverse it separately.

   Time Complexity: O(n)
   Space Complexity: O(h)

   where h is the height of the tree (recursive call stack).
*/

Question Link: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// Code:

/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void leftTraversal(Node* root, vector<int>& ans)
    {
        if(root == NULL || root->left == NULL && root->right == NULL) return;
        
        ans.push_back(root->data);
        if(root->left)
            leftTraversal(root->left, ans);
        
        else
            leftTraversal(root->right, ans);
    }
    
    void rightTraversal(Node* root, vector<int>& ans)
    {
        if(root == NULL || root->left == NULL && root->right == NULL) return;
        
        if(root->right) rightTraversal(root->right, ans);
        else rightTraversal(root->left, ans);
        
        ans.push_back(root->data);
    }
    
    void leafTraversal(Node* root, vector<int>& ans)
    {
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL)
            ans.push_back(root->data);
            
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> result;
        
        if(root == NULL) return result;
        
        result.push_back(root->data);
        
        leftTraversal(root->left, result);
        leafTraversal(root->left, result);
        leafTraversal(root->right, result);
        rightTraversal(root->right, result);
        
        return result;
    }
};