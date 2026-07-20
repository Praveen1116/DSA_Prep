/* Problem:
   Given a sorted array of integers, find the first and last position of a
   target value.

   If the target is not present, return [-1, -1].

   The solution must run in O(log n) time.
*/

/* Intuition:
   A normal Binary Search stops as soon as it finds the target.

   However, the target may appear multiple times.

   Therefore, we perform Binary Search twice:

   1. First Binary Search:
      Find the leftmost (first) occurrence.

   2. Second Binary Search:
      Find the rightmost (last) occurrence.

   This guarantees that both boundaries of the target are found efficiently.
*/

/* Approach:
   1. Find the First Occurrence:
      - Perform Binary Search.
      - Whenever nums[mid] == target:
            - Store mid as a possible answer.
            - Continue searching in the left half because an earlier
              occurrence may exist.

   2. Find the Last Occurrence:
      - Perform Binary Search again.
      - Whenever nums[mid] == target:
            - Store mid as a possible answer.
            - Continue searching in the right half because a later
              occurrence may exist.

   3. Return:
         {firstOccurrence, lastOccurrence}

   Catching Point:
   The only difference between the two Binary Searches is the direction
   after finding the target.

   For the First Occurrence:

         if(nums[mid] == target)
         {
             ans = mid;
             high = mid - 1;
         }

   We move left to search for an earlier occurrence.

   For the Last Occurrence:

         if(nums[mid] == target)
         {
             ans = mid;
             low = mid + 1;
         }

   We move right to search for a later occurrence.

   Even after finding the target, we do NOT stop because there may be
   another occurrence further left or right.

   Time Complexity: O(log n)
      - First Binary Search: O(log n)
      - Second Binary Search: O(log n)

      Overall: O(log n)

   Space Complexity: O(1)
*/

Question Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Code:

class Solution {
public:
    int firstIdx(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size()-1;
        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
            {
                ans = mid;
                high = mid-1;
            }

            else if(nums[mid] < target)
            {
                low = mid+1;
            }

            else high = mid-1;
        }

        return ans;
    }

    int secondIdx(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size()-1;
        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
            {
                ans = mid;
                low = mid+1;
            }

            else if(nums[mid] < target)
            {
                low = mid+1;
            }

            else high = mid-1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstIdx(nums, target), secondIdx(nums, target)};
    }
};