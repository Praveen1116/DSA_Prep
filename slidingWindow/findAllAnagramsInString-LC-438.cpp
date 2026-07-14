/* Problem:
   Find all starting indices of the substrings in s that are anagrams of p.
*/

/* Intuition:
   An anagram contains the same characters with the same frequencies as the
   original string, only the order of characters is different.

   Instead of checking every substring by sorting or generating permutations,
   we can compare the frequency of characters. If a substring of s having
   length equal to p has the same character frequencies as p, then that
   substring is an anagram.

   Since every substring we need to check has the same fixed length
   (p.size()), a sliding window is the most efficient approach.
*/

/* Approach:
   1. Create a frequency array freq1 of size 26 to store the frequency of
      characters in p.

   2. Create another frequency array freq2 of size 26 to store the frequency
      of characters in the current sliding window of s.

   3. Use two pointers, left and right, to maintain a window of size p.size().
      - Add the current character (right) into freq2.
      - If the window size becomes greater than p.size(), remove the left
        character from freq2 and move left forward to maintain the fixed
        window size.

   4. After every valid window of size p.size(), compare freq1 and freq2.
      If both frequency arrays are equal, the current window is an anagram
      of p, so store left (the starting index of the window) in the result.

   5. Continue until the entire string s is processed and return the list
      of starting indices.

   Time Complexity: O(m+n), O(m) for building freq1 of m=p.size() and O(n) for sliding window
   Space Complexity: O(1) as O(26 + 26) = O(1) constant
*/

// This question is same as Leetcode 567 but we have to return here indices of anagrams

Question Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

// Code:

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(char c : p) freq1[c - 'a']++;

        int count = p.size();
        int left = 0;
        for(int right=0; right<s.size(); right++)
        {
            freq2[s[right] - 'a']++;

            if(right-left+1 > p.size())
            {
                freq2[s[left] - 'a']--;
                left++;
            }

            if(freq1 == freq2)
            {
                res.push_back(left);
            }
        }

        return res;
    }
};