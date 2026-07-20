/* Problem:
   Given a sorted array of distinct integers and a target value,
   return the index if the target is found.

   If it is not found, return the index where it should be inserted
   so that the array remains sorted.
*/

/* Intuition:
   We are not just searching for the target.

   Instead, we are looking for the first position where the element is
   greater than or equal to the target.

   This is exactly the concept of Lower Bound.

   During Binary Search, whenever we find an element that is greater than
   or equal to the target, it becomes a possible answer. However, there
   might be another valid position further to the left, so we continue
   searching in the left half.
*/

/* Approach:
   1. Initialize:
      - low = 0
      - high = n - 1
      - ans = n
        (Default answer if every element is smaller than the target.)

   2. While low <= high:
      - Calculate the middle index safely.

   3. If nums[mid] >= target:
      - Store mid as a possible answer.
      - Continue searching in the left half by setting:
            high = mid - 1

   4. Otherwise:
      - The target can only be inserted in the right half.
      - Move:
            low = mid + 1

   5. After the loop ends, ans stores the first index where
      nums[index] >= target.

   6. Return ans.

   Catching Point:
   This is a Lower Bound problem, not a normal Binary Search.

   The key observation is:

         nums[mid] >= target

   Whenever this condition is true:
   - mid is a valid insertion position.
   - But there may be another valid position further left.

   Therefore, we:
      - Store the current answer.
      - Continue searching on the left.

   Also, notice:

         ans = nums.size()

   If every element in the array is smaller than the target,
   the correct insertion position is at the end of the array.

   Time Complexity: O(log n)

   Space Complexity: O(1)
*/

Question Link: https://leetcode.com/problems/search-insert-position/

// Code:

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int ans = nums.size();

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] >= target)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return ans;
    }
};