/* Problem:
   Find the maximum number of consecutive 1's in the array if you are allowed
   to flip at most k zeros into ones.
*/

/* Intuition:
   We need the longest contiguous subarray that contains at most k zeros,
   because those zeros can be flipped into ones.

   Since we are looking for a contiguous subarray, a sliding window is the
   most suitable approach. We expand the window using the right pointer and
   keep track of how many zeros are present in the current window.

   As long as the number of zeros is less than or equal to k, the window is
   valid. If it becomes greater than k, the window becomes invalid, so we
   shrink it from the left until it becomes valid again.
*/

/* Approach:
   1. Initialize:
      - left = 0
      - count = 0 (stores the number of zeros in the current window)
      - maxOne = 0

   2. Traverse the array using the right pointer.
      - If nums[right] is 0, increment count.

   3. If count becomes greater than k:
      - The current window is invalid.
      - Before moving left, check whether nums[left] is 0.
        If yes, decrement count.
      - Move left forward by one position.

   4. After adjusting the window, calculate its length:
         right - left + 1
      and update the maximum length.

   5. Return the maximum window length found.

   Catching Point:
   Many solutions use a while loop to shrink the window until it becomes
   valid. However, in this optimized solution, we use only a single if
   statement.

   Why does this work?

   Once the window becomes invalid (count > k), we move the left pointer by
   exactly one position. In the next iteration, the right pointer also moves
   forward by one position.

   This ensures that the window size never grows while it is invalid. The
   window either becomes valid again or keeps sliding forward with the same
   size. Therefore, using an if statement is sufficient, and we still obtain
   the correct maximum window length.

   Time Complexity: O(n)
   Space Complexity: O(1)
*/

Question Link: https://leetcode.com/problems/max-consecutive-ones-iii/

// Code:

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxOne = 0;

        int left = 0;
        int count = 0;
        for(int right=0; right<nums.size(); right++)
        {
            if(nums[right] == 0) count++;

            if(count > k)
            {
                if(nums[left] == 0)
                    count--;
                left++;
            }

            maxOne = max(maxOne, right-left+1);
        }

        return maxOne;
    }
};