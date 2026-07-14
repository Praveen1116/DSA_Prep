/* Problem:
   Check whether s2 contains any permutation of s1.
*/

/* Intuition:
   A permutation of s1 contains exactly the same characters with the same
   frequencies, only their order can be different.

   Instead of generating all possible permutations of s1, we can compare the
   frequency of characters. If any substring of s2 having length equal to s1
   has the same character frequencies as s1, then that substring is a
   permutation of s1.

   Since we need to check every substring of length s1.size(), a sliding window
   is the most efficient approach.
*/

/* Approach:
   1. Create a frequency array freq1 of size 26 to store the frequency of
      characters in s1.
      For every character, update its frequency using:
      freq1[s1[i] - 'a']++;

      Here, 'a' - 'a' = 0, 'b' - 'a' = 1, ..., 'z' - 'a' = 25, so each
      character is mapped to its corresponding index.

   2. Maintain another frequency array freq2 of size 26 for the current window
      in s2.

   3. Use two pointers, left and right, to create a sliding window of size
      s1.size().
      - Add the current character (right) into freq2.
      - If the window size becomes greater than s1.size(), remove the left
        character from freq2 and move left forward to keep the window size
        fixed.

   4. After every valid window of size s1.size(), compare freq1 and freq2.
      If both frequency arrays are equal, it means the current window is a
      permutation of s1, so return true.

   5. If no matching window is found after traversing s2, return false.

   6. We can do early checking also if s1.size() > s2.size() return false;

   Time Complexity: O(m + n) because building frequency costs O(m), sliding window O(n) with
                    26 comparisons so O(m + 26n) which means O(m+n) as 26 is constant
   Space Complexity: O(1) because only 26 spaces are being taken so O(26) is O(1) as 26 is 
                    constant
*/

/* Another approach is with hashmap but that will cost memory for storing key, value, hash,
    pointers, bucket information
    So the array approach does => address = base + index * sizeof(int) and
    in case of hashmap CPU has to compute hash, find buckets, traverse bucket(if collisions),
    locate node, update value */

Question Link: https://leetcode.com/problems/permutation-in-string/

// Code:

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(char c : s1)
        {
            freq1[c - 'a']++;
        }

        int left = 0, count = s1.size();
        for(int right=0; right<s2.size(); right++)
        {
            freq2[s2[right] - 'a']++;

            if((right-left+1) > s1.size())
            {
                freq2[s2[left] - 'a']--;
                left++;
            }

            if(freq1 == freq2) return true;
        }

        return false;
    }
};