/* Problem:
   Given two arrays, nums1 and nums2, find the Next Greater Element for every
   element in nums1 based on its position in nums2.
*/

/* Intuition:
   Since the Next Greater Element always lies on the right side of an element,
   we first process nums2 from right to left. The last element of nums2 will
   always have -1 as its answer because there are no elements to its right.

   Instead of finding the Next Greater Element for each element of nums1
   separately, we first compute the Next Greater Element for every element
   in nums2 using a stack and store the result in a hash map. Then, for each
   element in nums1, we can directly retrieve its answer from the map in O(1)
   time.
*/

/* Approach:
   1. Traverse nums2 from right to left.
   2. While the stack is not empty and the current element is greater than or
      equal to the top of the stack, remove the top element since it cannot
      be the Next Greater Element.
   3. If the stack becomes empty, store -1 for the current element in the map.
      Otherwise, store stack.top() as its Next Greater Element.
   4. Push the current element onto the stack.
   5. After processing nums2, iterate through nums1 and use the hash map to
      directly find the Next Greater Element for each of its elements.

   Time Complexity: O(n + m)
   Space Complexity: O(n)

   where:
   n = size of nums2
   m = size of nums1
*/

Question Link: https://leetcode.com/problems/next-greater-element-i/description/

// Code:

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nge;

        for(int i=nums2.size()-1; i>=0; i--)
        {
            while(!st.empty() && nums2[i] >= st.top())
            {
                st.pop();
            }

            // if(st.empty())
            // {
            //     nge[nums2[i]] = -1;
            // }

            // else
            // {
            //     nge[nums2[i]] = st.top();
            // }

            nge[nums2[i]] = st.empty() ? -1 : st.top();

            st.push(nums2[i]);
        }

        vector<int> res;
        for(int num : nums1)
        {
            res.push_back(nge[num]);
        }

        return res;
    }
};