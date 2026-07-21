/* Problem:
   Given an adjacency list of a graph, perform a Breadth First Search (BFS)
   traversal starting from vertex 0 and return the order of traversal.
*/

/* Intuition:
   BFS explores the graph level by level.

   Starting from the source node, it first visits all of its immediate
   neighbours, then the neighbours of those nodes, and so on.

   A queue is used because it follows the FIFO (First In, First Out)
   principle, ensuring that nodes are processed in the same order in which
   they are discovered.

   We also maintain a visited array so that each node is visited only once,
   preventing duplicate processing and infinite loops in graphs containing
   cycles.
*/

/* Approach:
   1. Create:
      - A queue for BFS traversal.
      - A visited array to keep track of visited nodes.
      - A result vector to store the traversal.

   2. Start BFS from vertex 0:
      - Push 0 into the queue.
      - Mark it as visited.

   3. While the queue is not empty:
      - Remove the front node from the queue.
      - Add it to the result.

   4. Traverse all neighbours of the current node:
      - If a neighbour has not been visited:
          - Mark it as visited.
          - Push it into the queue.

   5. Continue until the queue becomes empty.

   6. Return the BFS traversal.

   Catching Point:
   The most important step is marking a node as visited
   before pushing it into the queue.

         visited[neighbour] = true;
         q.push(neighbour);

   If we mark it after popping, the same node may get inserted into the queue
   multiple times through different neighbours, leading to unnecessary work.

   Also, remember that BFS always explores nodes level by level because the
   queue processes nodes in FIFO order.

   Time Complexity: O(V + E)

      where:
      V = Number of Vertices
      E = Number of Edges

      Every vertex is visited once, and every edge is explored once.

   Space Complexity: O(V)

      - O(V) for the visited array.
      - O(V) for the queue in the worst case.
*/

Question Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// Code:

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> ans;
        vector<bool> visited(adj.size(), false);
        queue<int> q;
        
        q.push(0);
        visited[0] = true;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(int neighbours : adj[node])
            {
                if(!visited[neighbours])
                {
                    visited[neighbours] = true;
                    q.push(neighbours);
                }
            }
        }
        
        return ans;
    }
};