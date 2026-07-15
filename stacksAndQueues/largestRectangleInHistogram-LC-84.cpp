/* Problem:
   Find the largest rectangular area that can be formed in a histogram.
*/

/* Intuition:
   Consider every bar as the height of a possible rectangle. To maximize the
   area for a particular bar, we need to know how far this bar can be extended
   to the left and right while all the bars remain at least as tall as the
   current bar.

   This means we need:
   - The Previous Smaller Element (PSE), which tells where the rectangle
     stops extending on the left.
   - The Next Smaller Element (NSE), which tells where the rectangle
     stops extending on the right.

   Once these boundaries are known, we can easily calculate the maximum width
   for every bar and hence its area. The largest among all such areas is the
   answer.
*/

/* Approach:
   1. Find the Previous Smaller Element (PSE) for every index using a
      monotonic increasing stack.
      - If no smaller element exists on the left, store -1.

   2. Find the Next Smaller Element (NSE) for every index using another
      monotonic increasing stack while traversing from right to left.
      - If no smaller element exists on the right, store n (array size).

   3. For every bar:
      - Width = NSE[i] - PSE[i] - 1
        We subtract 1 because both PSE and NSE point to the first smaller
        bars, which cannot be included in the rectangle.
      - Area = heights[i] * Width

   4. Keep updating the maximum area while traversing all the bars.

   5. Return the maximum area obtained.

   Time Complexity: O(n) + O(n) + O(n) for pse, nse, final loop to compute areas => O(n)
   Space Complexity: O(n) + O(n) as both array doesn't exist simultaneosly so O(n)
*/

Question Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

// Code:

class Solution {
public:
    vector<int> previousSmaller(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> pse(n);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();

            if(st.empty()) pse[i] = -1;

            else
            {
                pse[i] = st.top();
            }

            st.push(i);
        }

        return pse;
    }

    vector<int> nextSmaller(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> nse(n);

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();

            if(st.empty()) nse[i] = n;

            else
            {
                nse[i] = st.top();
            }

            st.push(i);
        }

        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = previousSmaller(heights);
        vector<int> nse = nextSmaller(heights);

        int maxArea = 0;

        for(int i=0; i<heights.size(); i++)
        {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// One more approach is there with some math computation and faster than this