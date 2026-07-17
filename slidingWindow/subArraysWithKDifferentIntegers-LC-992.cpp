/* Problem:
   Count the number of subarrays that contain exactly k distinct integers.
*/

/* Intuition:
   Finding subarrays with exactly k distinct elements directly is difficult.

   Instead, we use a simple observation:

      Exactly(k) = AtMost(k) - AtMost(k - 1)

   - AtMost(k) gives the number of subarrays having at most k distinct
     elements.
   - AtMost(k - 1) gives the number of subarrays having at most (k - 1)
     distinct elements.

   Subtracting them removes all subarrays having fewer than k distinct
   elements, leaving only those with exactly k distinct elements.

   To count subarrays with at most k distinct elements, we use a sliding
   window. We expand the window using the right pointer and keep track of
   the frequency of each element along with the number of distinct elements
   in the current window.
*/

/* Approach:
   1. Create a helper function atMost(nums, k).

   2. Maintain:
      - left -> starting index of the window.
      - right -> ending index of the window.
      - distinct -> number of distinct elements in the current window.
      - freq[] -> stores the frequency of every element.

   3. Traverse the array using the right pointer.
      - If the current element appears for the first time in the window,
        increment distinct.
      - Increase its frequency.

   4. If distinct becomes greater than k:
      - Shrink the window from the left.
      - Decrease the frequency of nums[left].
      - If its frequency becomes 0, decrement distinct.
      - Move left forward until the window becomes valid.

   5. Once the window is valid, every subarray ending at 'right' and starting
      anywhere between 'left' and 'right' is also valid.

      Therefore, the number of valid subarrays ending at right is:
            right - left + 1

      Add this value to the answer.

   6. Return the total count of subarrays having at most k distinct elements.

   7. Finally, calculate:
         atMost(k) - atMost(k - 1)

      to obtain the number of subarrays having exactly k distinct elements.

   Catching Point:
   The most important observation is:

         Exactly(k) = AtMost(k) - AtMost(k - 1)

   Instead of solving the "exactly k" problem directly, we solve two easier
   "at most" problems and subtract their answers.

   Another important observation is:
   Once the current window is valid, every subarray ending at 'right' and
   starting from any index between 'left' and 'right' is also valid.

   Hence, we can directly add:
         right - left + 1

   instead of checking every subarray individually.

   Time Complexity: O(n)
   Space Complexity: O(n)
*/

Question link: https://leetcode.com/problems/subarrays-with-k-different-integers/

// Code:

class Solution {
public:
    int atMost(vector<int>& nums, int k)
    {
        int count = 0;
        int left = 0;
        int distinct = 0;

        vector<int> freq(nums.size()+1, 0);
        for(int right=0; right<nums.size(); right++)
        {
            if(freq[nums[right]] == 0) distinct++;

            freq[nums[right]]++;

            while(distinct > k)
            {
                freq[nums[left]]--;

                if(freq[nums[left]] == 0)
                {
                    distinct--;
                }

                left++;
            }

            count += right-left+1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};

// Can you HashMap also for ease