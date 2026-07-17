/* Problem:
   Given an integer array, answer multiple range sum queries efficiently.

   For each query [left, right], return the sum of all elements from
   index left to right (both inclusive).
*/

/* Intuition:
   If we calculate the sum for every query by traversing the array, each
   query would take O(n) time.

   Since there can be many queries, we preprocess the array once by building
   a Prefix Sum array.

   This solution uses the Sentinel Prefix Sum approach.

   A sentinel value (0) is placed at the beginning of the prefix array, making
   its size n + 1. This eliminates special cases and allows every range sum
   to be calculated using the same formula.
*/

/* Approach:
   1. Create a prefix array of size n + 1.
      - prefix[0] = 0 (Sentinel value)

   2. Build the prefix array:
         prefix[i] = prefix[i - 1] + nums[i - 1]

      Here, prefix[i] stores the sum of the first i elements.

   3. To answer a query [left, right]:
      - prefix[right + 1] gives the sum from index 0 to right.
      - prefix[left] gives the sum from index 0 to left - 1.

      Therefore,

         Sum(left, right) =
             prefix[right + 1] - prefix[left]

   4. Since the prefix array is already built, every query can now be answered
      in constant time.

   Catching Point:
   This solution follows the Sentinel Prefix Sum approach.

   The extra 0 at the beginning shifts every prefix sum by one position,
   allowing us to use the same formula for every query:

         prefix[right + 1] - prefix[left]

   Without the sentinel, we would need additional conditions when
   left == 0, making the implementation more complicated.

   Time Complexity:
      Constructor: O(n)
      sumRange(): O(1)

   Space Complexity: O(n)
*/

Question Link : https://leetcode.com/problems/range-sum-query-immutable/

// Code:

class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n+1, 0);

        for(int i=1; i<n+1; i++)
        {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */