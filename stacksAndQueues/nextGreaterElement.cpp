/* Problem:
   Find the Next Greater Element (NGE) for every element in the array.
*/

/* Intuition:
   The Next Greater Element must always lie on the right side of the current
   element. Since the last element has no elements to its right, its answer
   will always be -1. This observation suggests that instead of traversing
   from left to right, we should process the array from right to left.

   While moving left, we need a way to quickly find the nearest greater element
   on the right. A stack is ideal for this because it stores only the useful
   candidates that can act as the Next Greater Element for the upcoming elements.
*/

/* Approach:
   1. Traverse the array from right to left.
   2. While the stack is not empty and the current element is greater than or
      equal to the top of the stack, remove the top element since it can never
      be the Next Greater Element for the current or any previous element.
   3. If the stack becomes empty, no greater element exists on the right, so
      store -1 in the answer.
   4. Otherwise, the top of the stack is the Next Greater Element, so store it
      in the answer.
   5. Push the current element onto the stack so it can be considered for the
      elements on its left.

   Time Complexity: O(n)
   Space Complexity: O(n)
*/

Question Link: https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// Code:

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        
        vector<int> res(n);
        
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[i] >= st.top())
            {
                st.pop();
            }
            
            if(st.empty())
            {
                res[i] = -1;
            }
            else
            {
                res[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        
        return res;
        
    }
};