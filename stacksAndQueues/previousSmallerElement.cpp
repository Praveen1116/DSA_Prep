/* Problem:
   Find the Previous Smaller Element (PSE) for every element in the array.
*/

/* Intuition:
   The Previous Smaller Element always lies on the left side of the current
   element. Since the first element has no elements to its left, its answer
   will always be -1. This means we should traverse the array from left to
   right.

   While moving forward, we need a way to quickly find the nearest smaller
   element on the left. A stack helps us maintain only those elements that
   can be the Previous Smaller Element for the upcoming elements.
*/

/* Approach:
   1. Traverse the array from left to right.
   2. While the stack is not empty and the current element is smaller than or
      equal to the top of the stack, remove the top element since it cannot
      be the Previous Smaller Element for the current or any future element.
   3. If the stack becomes empty, no smaller element exists on the left, so
      store -1 in the answer.
   4. Otherwise, the top of the stack is the Previous Smaller Element, so
      store it in the answer.
   5. Push the current element onto the stack so it can be considered for
      the elements on its right.

   Time Complexity: O(n)
   Space Complexity: O(n)
*/

Question Link: https://www.geeksforgeeks.org/problems/previous-smaller-element/1

// Code:

class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int> st;
        
        vector<int> res(n);
        
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && st.top() >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty()) res[i] = -1;
            
            else
            {
                res[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        
        return res;
    }
};