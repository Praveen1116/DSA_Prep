/* Problem:
   Given an undirected graph, determine whether it contains a cycle.

   Return true if a cycle exists; otherwise, return false.
*/

/* Intuition:
   We use Breadth First Search (BFS) to traverse the graph.

   In an undirected graph, every edge is present in both directions.
   Therefore, while exploring a node, we will always encounter its parent
   again. This should NOT be considered a cycle.

   A cycle is detected only when we reach a node that has already been
   visited and is NOT the parent of the current node.

   To distinguish between a parent edge and a back edge, we maintain the
   parent of every visited node.
*/

/* Approach:
   1. Convert the edge list into an adjacency list.

   2. Create:
      - A visited array to track visited vertices.
      - A parent map to store the parent of every node during BFS.

   3. Since the graph may be disconnected,
      start BFS from every unvisited vertex.

   4. For each BFS:
      - Mark the starting node as visited.
      - Set its parent to -1.
      - Push it into the queue.

   5. While the queue is not empty:
      - Remove the front node.
      - Traverse all of its neighbours.

      If a neighbour is not visited:
         - Mark it as visited.
         - Store the current node as its parent.
         - Push it into the queue.

      Otherwise,
         if the neighbour is already visited and is NOT the parent of the
         current node, a cycle is found.
         Return true.

   6. If every connected component is processed without finding a cycle,
      return false.

   Catching Point:
   The most important condition is:

         else if(parent[frontNode] != neighbour)

   In an undirected graph, every node naturally sees its parent again
   because edges exist in both directions.

   Example:

         0 ----- 1

   While visiting node 1, neighbour 0 is already visited.
   This is NOT a cycle because 0 is the parent of 1.

   A cycle exists only if we encounter a previously visited node that is
   different from the parent.

   Another important point is iterating through all vertices:

         for(int i = 0; i < V; i++)

   This ensures that disconnected graphs are also completely checked.

   Time Complexity: O(V + E)

      where:
      V = Number of Vertices
      E = Number of Edges

      Every vertex is visited once, and every edge is explored once.

   Space Complexity: O(V)

      - O(V) for the visited array.
      - O(V) for the parent map.
      - O(V) for the queue.
*/

Question Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Code:

class Solution {
  public:
    bool bfsHelper(int startNode, vector<vector<int>>& adj, vector<bool>& visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;
        
        visited[startNode] = true;
        q.push(startNode);
        parent[startNode] = -1;
        
        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            
            for(int neighbour : adj[frontNode])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                    
                    parent[neighbour] = frontNode;
                }
                
                else if(parent[frontNode] != neighbour)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                // bfs
                if(bfsHelper(i, adj, visited))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};