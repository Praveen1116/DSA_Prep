/* Problem:
   Given a sorted array of integers and a target value, return the index of
   the target if it exists. Otherwise, return -1.

   The solution must run in O(log n) time.
*/

/* Intuition:
   Since the array is already sorted, we do not need to search every element.

   We can repeatedly divide the search space into two halves using Binary
   Search.

   - If the middle element is the target, return its index.
   - If the target is greater than the middle element, it can only be present
     in the right half.
   - Otherwise, it can only be present in the left half.

   By discarding half of the search space after every comparison, the search
   becomes much faster than a linear scan.
*/

/* Approach:
   1. Initialize two pointers:
      - low = 0
      - high = n - 1

   2. While low <= high:
      - Calculate the middle index safely:
            mid = low + (high - low) / 2

   3. Compare nums[mid] with the target:
      - If they are equal, return mid.
      - If nums[mid] < target, search the right half by setting:
            low = mid + 1
      - Otherwise, search the left half by setting:
            high = mid - 1

   4. If the loop ends, the target is not present in the array.
      Return -1.

   Catching Point:
   Instead of calculating the middle as:

         (low + high) / 2

   we use:

         low + (high - low) / 2

   This avoids integer overflow when low and high are very large.

   Also, after each comparison, we discard half of the remaining search
   space, which is why Binary Search runs in logarithmic time.

   Time Complexity: O(log n)
   Space Complexity: O(1)
*/

Question Link: https://leetcode.com/problems/binary-search/

// Code:

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;

            else if(nums[mid] < target)
                low = mid+1;

            else high = mid-1;
        }

        return -1;
    }
};