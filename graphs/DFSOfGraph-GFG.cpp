/* Problem:
   Given an adjacency list of a graph, perform a Depth First Search (DFS)
   traversal starting from vertex 0 and return the order of traversal.
*/

/* Intuition:
   DFS explores a graph by going as deep as possible along one path before
   backtracking.

   Starting from the source node, we visit one unvisited neighbour and keep
   moving deeper until no further unvisited neighbours are available. Then,
   recursion automatically backtracks to explore the remaining paths.

   A visited array is used to ensure that each node is visited only once,
   preventing infinite recursion in graphs containing cycles.
*/

/* Approach:
   1. Create:
      - A visited array to keep track of visited nodes.
      - A result vector to store the DFS traversal.

   2. Start DFS from vertex 0.

   3. In the recursive function:
      - Mark the current node as visited.
      - Add the current node to the result.

   4. Traverse all neighbours of the current node:
      - If a neighbour has not been visited,
        recursively perform DFS on that neighbour.

   5. When a node has no unvisited neighbours,
      recursion automatically backtracks to its parent.

   6. Continue until all reachable nodes are visited.

   7. Return the DFS traversal.

   Catching Point:
   The most important step is marking a node as visited
   before making recursive calls.

         visited[node] = true;

   If we delay marking the node until after recursion, graphs containing
   cycles can cause infinite recursive calls.

   Another important concept is backtracking.

   Once DFS reaches a node with no unvisited neighbours, recursion returns
   to the previous node and continues exploring any remaining neighbours.

   Time Complexity: O(V + E)

      where:
      V = Number of Vertices
      E = Number of Edges

      Every vertex is visited once, and every edge is explored once.

   Space Complexity: O(V)

      - O(V) for the visited array.
      - O(V) recursion stack in the worst case.
*/

Question Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// Code:

class Solution {
  public:
    void solve(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans)
    {
        visited[node] = true;
        ans.push_back(node);
        
        for(int neigh : adj[node])
        {
            if(!visited[neigh])
            {
                solve(neigh, adj, visited, ans);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        vector<bool> visited(adj.size(), false);
        
        solve(0, adj, visited, ans);
        
        return ans;
    }
};