/* Intuition:
   We need to find the longest substring that contains only unique characters.

   Since a substring is contiguous, a sliding window is the best approach.
   We maintain a window using two pointers, left and right.

   To quickly know whether a character is already present in the current
   window, we use an array of size 128 (ASCII characters). The array stores
   the frequency of every character inside the current window.

   If a character appears more than once, it means the current window is no
   longer valid. So, we keep shrinking the window from the left until every
   character becomes unique again.
*/

/* Approach:
   1. Create a frequency array of size 128 and initialize it with 0.

   2. Maintain a sliding window using two pointers:
      - left  -> starting index of the window.
      - right -> ending index of the window.

   3. Traverse the string using the right pointer.
      - Add the current character to the frequency array.

   4. If the frequency of the current character becomes greater than 1,
      it means a duplicate character exists in the window.
      - Remove characters from the left side.
      - Decrease their frequencies.
      - Move left forward until the duplicate is removed.

   5. Once the window becomes valid again (all characters are unique),
      calculate its length:
            right - left + 1
      and update the maximum length.

   6. Return the maximum length found.

   Time Complexity: O(n)
   Space Complexity: O(1)
*/


Question Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Code:

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        vector<int> freq(256, 0);

        int left = 0;
        for(int right=0; right<s.size(); right++)
        {
            freq[s[right]]++;

            while(freq[s[right]] > 1)
            {
                freq[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right-left+1);
        }

        return maxLength;
    }
};


/* **************************************************************************** */

// Approach 2: Most optimized

/* Intuition:
   We again use a sliding window because we need a contiguous substring.

   Instead of storing the frequency of every character, we store the last
   index where each character was seen.

   This gives us one extra piece of information: we know exactly where the
   duplicate character appeared previously.

   So instead of removing characters one by one from the left, we can directly
   jump the left pointer to the position after the previous occurrence of that
   duplicate character.
*/

/* Approach:
   1. Create an array lastSeen of size 128 and initialize every element to -1.
      lastSeen[ch] stores the last index where character 'ch' appeared.

   2. Maintain a sliding window using two pointers:
      - left  -> starting index of the current window.
      - right -> ending index of the current window.

   3. Traverse the string using the right pointer.

   4. If the current character has been seen before, move the left pointer to:
         max(left, lastSeen[currentCharacter] + 1)

      The max() ensures that left never moves backwards.

   5. Update the last seen index of the current character.

   6. Calculate the current window length:
         right - left + 1
      and update the maximum length.

   7. Return the maximum length.

   Catching Point:
   In the frequency-array approach, when a duplicate is found, we remove
   characters one by one until the duplicate disappears.

   In this optimized approach, we already know the exact index where the
   duplicate last appeared. Therefore, instead of traversing the window again,
   we directly jump the left pointer to:
         lastSeen[currentCharacter] + 1

   This avoids unnecessary operations while still maintaining an overall
   O(n) time complexity.

   Time Complexity: O(n)
   Space Complexity: O(1)
*/

// Code:

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        vector<int> lastSeen(128, -1);

        int left = 0;
        for(int right=0; right<s.size(); right++)
        {
            if(lastSeen[s[right]] != -1)
            {
                left = max(left, lastSeen[s[right]] + 1);
            }

            lastSeen[s[right]] = right;

            maxLength = max(maxLength, right-left+1);
        }

        return maxLength;
    }
};