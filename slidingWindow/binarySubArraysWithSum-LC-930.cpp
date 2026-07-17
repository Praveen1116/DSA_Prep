/* Problem:
   Count the number of subarrays whose sum is exactly equal to the given goal.
*/

/* Intuition:
   Finding subarrays with exactly the given sum directly is not easy.

   Instead, we use the observation:

        Exactly(goal) = AtMost(goal) - AtMost(goal - 1)

   - AtMost(goal) counts all subarrays whose sum is less than or equal to goal.
   - AtMost(goal - 1) counts all subarrays whose sum is less than or equal to
     goal - 1.

   Subtracting these two values removes all subarrays having a smaller sum,
   leaving only those whose sum is exactly equal to the goal.

   Since the array contains only 0s and 1s, increasing the window increases
   the sum in a predictable way. This makes the sliding window approach
   possible.
*/

/* Approach:
   1. Create a helper function atMost(nums, goal).

   2. Maintain:
      - left  -> starting index of the window.
      - right -> ending index of the window.
      - sum   -> current window sum.

   3. Traverse the array using the right pointer.
      - Add nums[right] to the current window sum.

   4. If the sum becomes greater than goal:
      - Shrink the window from the left.
      - Subtract nums[left] from the sum.
      - Move left forward until the window becomes valid.

   5. Once the window is valid, every subarray ending at 'right' and starting
      anywhere between 'left' and 'right' is also valid.

      Therefore, the number of valid subarrays ending at right is:
            right - left + 1

      Add this value to the answer.

   6. Return the total number of subarrays having sum at most goal.

   7. Finally, calculate:
         atMost(goal) - atMost(goal - 1)

      to obtain the number of subarrays having sum exactly equal to goal.

   Catching Point:
   The key observation is:

         Exactly(goal) = AtMost(goal) - AtMost(goal - 1)

   Instead of solving the "exactly goal" problem directly, we solve two easier
   "at most" problems and subtract their answers.

   Another important observation is:
   Once the current window has sum <= goal, every subarray ending at 'right'
   and starting from any index between 'left' and 'right' will also have
   sum <= goal.

   Therefore, we can directly add:
         right - left + 1

   without checking every subarray individually.

   Also, notice this base case:

         if(goal < 0) return 0;

   Since the array contains only 0s and 1s, it is impossible for a subarray
   to have a negative sum.

   Time Complexity: O(n)
   Space Complexity: O(1)
*/

Question Link: https://leetcode.com/problems/binary-subarrays-with-sum/

// Code:

class Solution {
public:
    int atMost(vector<int>& nums, int goal)
    {
        if(goal < 0) return 0;
        long long sum = 0;
        int left = 0;
        int count = 0;

        for(int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];

            while(sum > goal)
            {
                sum -= nums[left];
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};