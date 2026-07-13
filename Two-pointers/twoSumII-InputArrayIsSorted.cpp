/* The problem is asking about the indices of two element that sums to target 
    if no such sum exists return empty array but on the leetcode it says that
    there is solution*/

/* Approach: If we have to do it in linear time then we have to think about two-indices
    means if we have two pointers over the array then we can check if those two pointer's
    element sum to target or not so we traverse only once over the array which makes it
    O(n). So initialize two pointers over the array one at the left boundary and another
    at the right boundary beacuse array is sorted means if the sum of arr[left] and arr[right]
    == target then we return from there (remember to return with +1 index as it is 1 indexed)
    else if sum < target then we move the left pointer because moving left to next index 
    will always increase the sum as it is sorted so next element will be greater than 
    before for sure and same goes with right but when sum > target right moves backward 
    as it will decrease the sum because backward element to the right will always smaller 
    than right element 
    
    So the conditions become very simple loop while left < right then check
    if(sum == target) then return {left+1, right+1}
    else if(sum < target) left++;
    else right-- */ 

Question link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

// Code:

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;

        while(l < r)
        {
            if(numbers[l] + numbers[r] == target)
            {
                return {l+1, r+1};
            }

            else if(numbers[l] + numbers[r] < target) l++;

            else r--;
        }

        return {};
    }
};