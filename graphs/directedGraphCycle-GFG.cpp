/* Problem:
   Given a directed graph, determine whether it contains a cycle.

   Return true if a cycle exists; otherwise, return false.
*/

/* Intuition:
   We use Depth First Search (DFS) to explore the graph.

   Unlike an undirected graph, keeping track of the parent is not enough for
   detecting cycles in a directed graph.

   Instead, we maintain two arrays:

   1. visited[]
      - Indicates whether a node has been visited before.

   2. rec[]
      - Indicates whether a node is currently present in the recursion stack
        (the current DFS path).

   If during DFS we reach a node that is already present in the recursion
   stack, it means we have found a back edge, which forms a cycle.
*/

/* Approach:
   1. Convert the edge list into an adjacency list.

   2. Create:
      - visited[] to avoid revisiting nodes.
      - rec[] to keep track of nodes in the current DFS path.

   3. Start DFS from every vertex because the graph may be disconnected.

   4. In the DFS function:
      - Mark the current node as visited.
      - Mark it as part of the recursion stack.

   5. Traverse all neighbours:
      - If the neighbour is not visited,
        recursively perform DFS.
        If recursion detects a cycle, return true.

      - If the neighbour is already in the recursion stack,
        a back edge exists, so return true.

   6. After processing all neighbours,
      remove the current node from the recursion stack
      before returning.

   7. If every DFS finishes without finding a cycle,
      return false.

   Catching Point:
   The most important condition is:

         else if(rec[neighbour])

   A visited node does NOT always indicate a cycle.

   A cycle exists only when we revisit a node that is still present in the
   current recursion path.

   Example:

         0 → 1 → 2
             ↑   ↓
             └───┘

   While exploring node 2, reaching node 1 again means node 1 is already
   in the recursion stack, so a cycle exists.

   Another important step is:

         rec[node] = false;

   Before returning, we remove the node from the recursion stack because
   its DFS traversal has finished. Otherwise, future DFS calls would
   incorrectly detect cycles.

   Time Complexity: O(V + E)

      where:
      V = Number of Vertices
      E = Number of Edges

      Every vertex is visited once, and every edge is explored once.

   Space Complexity: O(V)

      - O(V) for the visited array.
      - O(V) for the recursion stack array.
      - O(V) recursion stack in the worst case.
*/

Question Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Code:

class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& rec)
    {
        visited[node] = true;
        rec[node] = true;
        
        for(auto neighbour : adj[node])
        {
            if(!visited[neighbour])
            {
                if(dfs(neighbour, adj, visited, rec)) return true;
            }
            else if(rec[neighbour]) return true;
        }
        
        rec[node] = false;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        vector<bool> rec(V, false);
        
        for(int i=0; i<V; i++)
        {
            if(dfs(i, adj, visited, rec)) return true;
        }
        
        return false;
    }
};