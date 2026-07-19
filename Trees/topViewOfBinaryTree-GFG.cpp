/* Problem:
   Return the Top View of a binary tree.

   The Top View contains the nodes that are visible when the tree is viewed
   from the top. If multiple nodes lie on the same vertical line, only the
   first (topmost) node should be included.
*/

/* Intuition:
   Every node has a Horizontal Distance (HD) from the root.

      Root           -> HD = 0
      Left Child     -> HD - 1
      Right Child    -> HD + 1

   We perform a Level Order Traversal (BFS) because BFS visits nodes from
   top to bottom.

   Therefore, the first node we encounter at a particular horizontal distance
   is always the topmost visible node. Once that horizontal distance is filled,
   we never replace its value.
*/

/* Approach:
   1. If the tree is empty, return an empty vector.

   2. Create a map:
         key   -> Horizontal Distance (HD)
         value -> First node present at that HD

   3. Perform BFS using a queue that stores:
         (Node*, Horizontal Distance)

      Start with:
         (root, 0)

   4. While the queue is not empty:
      - Remove the front node and its horizontal distance.
      - If this HD is not already present in the map,
        store the current node because it is the first
        (topmost) node at that HD.
      - Push the left child with HD - 1.
      - Push the right child with HD + 1.

   5. Since map stores keys in sorted order, iterate through it
      from leftmost HD to rightmost HD and add each node value
      to the answer.

   6. Return the final result.

   Catching Point:
   The key idea is using BFS instead of DFS.

   BFS processes nodes level by level, so the first node encountered for a
   particular horizontal distance is always the one visible from the top.

   Also, notice this condition:

         if(topNode.find(hd) == topNode.end())

   We insert a node only if that horizontal distance has not been seen before.
   This ensures that deeper nodes at the same HD do not overwrite the topmost
   node.

   Time Complexity: O(n log n)
   Space Complexity: O(n)
*/

Question Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Cde:

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> result;
        
        if(root == NULL) return result;
        
        // we will create a map to store first node at each horizontal distance
        // key -> horizontal distance hd, value -> node value
        map<int, int> topNode;
        
        // create a queue to store pair of nodes and hd
        queue<pair<Node*, int>> q;
        // start with root at hd = 0
        q.push(make_pair(root, 0));
        
        while(!q.empty())
        {
            pair<Node*, int> frontNode = q.front();
            q.pop();
            
            Node* node = frontNode.first;
            int hd = frontNode.second;
            
            if(topNode.find(hd) == topNode.end())
            {
                topNode[hd] = node->data;
            }
            
            if(node->left) q.push(make_pair(node->left, hd-1));
            if(node->right) q.push(make_pair(node->right, hd+1));
        }
        
        for(auto i : topNode)
        {
            result.push_back(i.second);
        }
        
        return result;
    }
};