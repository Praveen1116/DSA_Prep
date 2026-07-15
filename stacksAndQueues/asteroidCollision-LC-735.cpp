/* Problem:
   Given a list of asteroids moving in a straight line, determine the state
   of the asteroids after all possible collisions.

   - A positive value means the asteroid is moving to the right.
   - A negative value means the asteroid is moving to the left.
*/

/* Intuition:
   A collision can only happen when a right-moving asteroid is already present
   and the current asteroid is moving to the left. In all other cases, the
   asteroids are moving away from each other, so no collision is possible.

   We use a stack to keep track of the asteroids that have survived so far.
   Whenever a possible collision occurs, we compare the sizes (absolute values)
   of the two asteroids:
   - The smaller asteroid gets destroyed.
   - If both have the same size, both are destroyed.
   - The larger asteroid survives.

   This process continues until the current asteroid is destroyed or no more
   collisions are possible.
*/

/* Approach:
   1. Traverse the asteroid array from left to right.
   2. For each asteroid, check whether a collision is possible.
      A collision occurs only when:
      - the stack is not empty,
      - the top asteroid is moving right (positive), and
      - the current asteroid is moving left (negative).

   3. While a collision is possible:
      - If the current asteroid is larger, remove the top asteroid and
        continue checking for more collisions.
      - If the top asteroid is larger, the current asteroid is destroyed,
        so stop processing it.
      - If both have the same size, remove the top asteroid and mark the
        current asteroid as destroyed.

   4. If the current asteroid survives all collisions, push it onto the stack.

   5. After processing all asteroids, the stack contains the final surviving
      asteroids. Copy them into the answer array in the correct order and
      return it.

   Time Complexity: O(n)
   Space Complexity: O(n)
*/

Question Link: https://leetcode.com/problems/asteroid-collision/

// Code:

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i=0; i<asteroids.size(); i++)
        {
            bool destroyed = false;
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0)
            {
                int topVal = st.top();

                if(abs(topVal) < abs(asteroids[i])) st.pop();

                else if(abs(topVal) > abs(asteroids[i])) {
                    destroyed = true;
                    break;
                }

                else
                {
                    st.pop();
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) st.push(asteroids[i]);
        }

        vector<int> ans(st.size());
        for(int i=st.size()-1; i>=0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};