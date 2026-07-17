/* Problem:
   Count the number of subarrays that contain exactly k odd numbers.
*/

/* Intuition:
   Finding subarrays with exactly k odd numbers directly is difficult.

   Instead, we use the observation:

        Exactly(k) = AtMost(k) - AtMost(k - 1)

   - AtMost(k) counts all subarrays having at most k odd numbers.
   - AtMost(k - 1) counts all subarrays having at most (k - 1) odd numbers.

   Subtracting these two values removes all subarrays having fewer than k odd
   numbers, leaving only those with exactly k odd numbers.

   We use a sliding window to count subarrays having at most k odd numbers.
   While traversing the array, we simply keep track of how many odd numbers
   are present in the current window.
*/

/* Approach:
   1. Create a helper function atMost(nums, k).

   2. Maintain:
      - left  -> starting index of the window.
      - right -> ending index of the window.
      - count -> number of odd elements in the current window.

   3. Traverse the array using the right pointer.
      - If nums[right] is odd, increment count.

   4. If the number of odd elements becomes greater than k:
      - Shrink the window from the left.
      - If nums[left] is odd, decrement count.
      - Move left forward until the window becomes valid.

   5. Once the window becomes valid, every subarray ending at 'right' and
      starting anywhere between 'left' and 'right' is also valid.

      Therefore, the number of valid subarrays ending at right is:
            right - left + 1

      Add this value to the answer.

   6. Return the total number of subarrays having at most k odd numbers.

   7. Finally, calculate:
         atMost(k) - atMost(k - 1)

      to obtain the number of subarrays having exactly k odd numbers.

   Catching Point:
   The most important observation is:

         Exactly(k) = AtMost(k) - AtMost(k - 1)

   Instead of solving the "exactly k" problem directly, we solve two easier
   "at most" problems and subtract their answers.

   Another important observation is:
   Once the current window contains at most k odd numbers, every subarray
   ending at 'right' and starting from any index between 'left' and 'right'
   will also contain at most k odd numbers.

   Therefore, we can directly add:
         right - left + 1

   instead of checking every subarray individually.

   Time Complexity: O(n)
   Space Complexity: O(1)
*/

Question Link: https://leetcode.com/problems/count-number-of-nice-subarrays/

// Code:

class Solution {
public:
    int atMost(vector<int>& nums, int k)
    {
        int count = 0;
        int left = 0;
        int subArray = 0;

        for(int right = 0; right < nums.size(); right++)
        {
            if(nums[right] % 2 != 0)
            {
                count++;
            }

            while(count > k)
            {
                if(nums[left] % 2 != 0) count--;

                left++;
            }

            subArray += right-left+1;
        }

        return subArray;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};