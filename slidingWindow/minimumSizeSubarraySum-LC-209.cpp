/* Problem:
   Find the minimum length of a contiguous subarray whose sum is greater than
   or equal to the given target. If no such subarray exists, return 0.
*/

/* Intuition:
   We need a contiguous subarray, so instead of checking all possible
   subarrays (which would take O(n²)), we can use a sliding window.

   As we expand the window by moving the right pointer, the sum of the window
   increases. Whenever the sum becomes greater than or equal to the target,
   we have found a valid subarray.

   However, this may not be the minimum length. So, we try to shrink the
   window from the left while the sum is still greater than or equal to the
   target. This helps us find the smallest possible valid window ending at
   the current right pointer.
*/

/* Approach:
   1. Initialize:
      - left = 0
      - sum = 0
      - minLength = INT_MAX

   2. Traverse the array using the right pointer.
      - Add nums[right] to the current window sum.

   3. While the window sum is greater than or equal to the target:
      - Update the minimum length using:
            right - left + 1
      - Remove nums[left] from the sum.
      - Move left forward to shrink the window.

   4. Continue this process until the entire array is traversed.

   5. If minLength was never updated, no valid subarray exists, so return 0.
      Otherwise, return minLength.

   Time Complexity: O(n)
   Space Complexity: O(1)
*/

Question Link: https://leetcode.com/problems/minimum-size-subarray-sum/

// Code:

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        int sum = 0;

        int left = 0;
        for(int right = 0; right<nums.size(); right++)
        {
            sum += nums[right];

            while(sum >= target)
            {
                minLength = min(minLength, right-left+1);

                sum -= nums[left];
                left++;
            }
        }

        

        return minLength == INT_MAX ? 0 : minLength;
    }
};