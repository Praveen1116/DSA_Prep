/* Problem:
   Given the root of a Binary Search Tree (BST) and a key, find its
   Inorder Predecessor and Inorder Successor.

   - Predecessor: The largest node smaller than the key.
   - Successor: The smallest node greater than the key.
*/

/* Intuition:
   We make use of the BST property:

        Left Subtree < Root < Right Subtree

   While searching for the key:

   - If the current node is smaller than the key, it is a possible
     predecessor because it is smaller than the key. We store it and move
     to the right to look for a larger predecessor.

   - If the current node is greater than the key, it is a possible
     successor because it is greater than the key. We store it and move
     to the left to look for a smaller successor.

   Once we find the key:
   - The predecessor is the rightmost node in its left subtree.
   - The successor is the leftmost node in its right subtree.
*/

/* Approach:
   1. Create two helper functions:
      - predecessor(root): returns the rightmost node of a subtree.
      - successor(root): returns the leftmost node of a subtree.

   2. Traverse the BST recursively.

   3. If the current node matches the key:
      - Find the predecessor by searching the left subtree.
      - Find the successor by searching the right subtree.
      - Return.

   4. If root->data < key:
      - The current node can be a possible predecessor.
      - Store it in 'pre'.
      - Move to the right subtree.

   5. If root->data > key:
      - The current node can be a possible successor.
      - Store it in 'succ'.
      - Move to the left subtree.

   6. Return the final predecessor and successor.

   Catching Point:
   There are two cases for finding the predecessor and successor.

   Case 1: The key exists in the BST.
      - Predecessor = Rightmost node of the left subtree.
      - Successor   = Leftmost node of the right subtree.

   Case 2: The key is not present.
      - While searching, keep updating:
          * pre whenever moving right.
          * succ whenever moving left.

      These stored candidates become the final predecessor and successor.

   This allows the algorithm to work whether or not the key exists in
   the BST.

   Time Complexity:
      - Average Case: O(log n)
      - Worst Case: O(n)

   Space Complexity:
      - Average Case: O(log n)
      - Worst Case: O(n)

   due to the recursion stack.
*/

/*
This problem can also be solved iteratively without recursion.

Hint:

Start from the root.
While traversing:
If root->data < key:
Update pre = root.
Move to root->right.
If root->data > key:
Update succ = root.
Move to root->left.
If root->data == key:
Find the rightmost node in the left subtree (predecessor).
Find the leftmost node in the right subtree (successor).
Stop.

This iterative solution has the same time complexity but uses O(1) auxiliary space (ignoring the traversal inside the left/right subtree)
*/

Question Link: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

// Code:

/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* preDecessor(Node* root)
    {
        if(root == NULL) return NULL;
        
        while(root->right != NULL)
        {
            root = root->right;
        }
        
        return root;
    }
    
    Node* successor(Node* root)
    {
        if(root == NULL) return NULL;
        
        while(root->left != NULL)
        {
            root = root->left;
        }
        
        return root;
    }
    
    void solve(Node* root, Node*& pre, Node*& succ, int key)
    {
        if(root == NULL) return;
        
        if(root->data == key)
        {
            Node* temp = preDecessor(root->left);
            if(temp) pre = temp;
            
            
            temp = successor(root->right);
            if(temp) succ = temp;
            
            return;
        }
        
        else if(root->data < key)
        {
            pre = root;
            solve(root->right, pre, succ, key);
        }
        
        else
        {
            succ = root;
            solve(root->left, pre, succ, key);
        }
    }
  
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = NULL;
        Node* succ = NULL;
        
        
        solve(root, pre, succ, key);
        
        return {pre, succ};
        
    }
};