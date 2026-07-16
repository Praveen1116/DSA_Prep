/* Problem:
   Find the length of the longest substring that can be made of the same
   character by replacing at most k characters.
*/

/* Intuition:
   We need the longest contiguous substring that can become all the same
   character after performing at most k replacements.

   A sliding window is the best choice because we are looking for a contiguous
   substring.

   For every window, we keep track of the frequency of each character and also
   store the frequency of the most frequent character (maxFreq).

   If the most frequent character appears maxFreq times, then all the remaining
   characters in the window must be replaced to make the entire window consist
   of the same character.

   Therefore, the number of replacements needed is:
         Window Size - maxFreq

   If this value is less than or equal to k, the window is valid.
   Otherwise, we shrink the window from the left.
*/

/* Approach:
   1. Create a frequency array of size 26 to store the frequency of each
      uppercase character.

   2. Maintain a sliding window using two pointers:
      - left  -> starting index of the window.
      - right -> ending index of the window.

   3. Expand the window by moving the right pointer.
      - Increase the frequency of the current character.
      - Update maxFreq if the current character becomes the most frequent
        character in the window.

   4. Check whether the current window is valid.
      - Replacements needed =
            (right - left + 1) - maxFreq
      - If this value becomes greater than k, shrink the window by:
          * Decreasing the frequency of s[left].
          * Moving left forward.

   5. After every valid window, update the maximum window length.

   6. Return the maximum length found.

   Catching Point:
   The key observation is that we never decrease maxFreq while shrinking
   the window.

   Although the actual maximum frequency inside the current window may become
   smaller, keeping an older (possibly larger) value of maxFreq never affects
   the correctness of the answer.

   A larger maxFreq may temporarily make an invalid window appear valid, but
   it never causes us to miss the correct maximum length. As the right pointer
   keeps moving, the window will eventually become valid naturally.

   Because of this, we avoid recalculating the maximum frequency after every
   shrink, reducing the complexity from O(26 × n) to O(n).

   Time Complexity: O(n)
   Space Complexity: O(1)
*/

Question Link: https://leetcode.com/problems/longest-repeating-character-replacement/

// Code:

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int left = 0, right = 0;
        int maxFreq = 0;

        vector<int> freq(26, 0);

        while(right < s.size())
        {
            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            if((right-left+1) - maxFreq > k)
            {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};