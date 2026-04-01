// Problem: Longest Substring Without Repeating Characters
// Platform: LeetCode
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// time complexity: O(n) using sliding window approach
// space complexity: O(n) using hash set to store characters in the current window

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0, maxLen = 0;
        unordered_set<char> n;
        while (right < s.size())
        {
            if (n.find(s[right]) == n.end())
            {
                n.insert(s[right]);
                maxLen = max(maxLen, (int)n.size());
                right++;
            }
            else
            {
                n.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};


// time complexity: O(n) using sliding window approach
// space complexity: O(1) using fixed-size array to store characters in the current window

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0, maxLen = 0; // left = window start, right = window end, maxLen = answer store
        vector<int> freq(256, 0);            // ASCII character count store korar jonno fixed array (O(1) space)
        while (right < s.size()) // jotokkhon right pointer string er moddhe ase
        {
            freq[s[right]]++; // current character er count 1 barai
            while (freq[s[right]] > 1) // jodi duplicate hoy (count > 1)
            {
                freq[s[left]]--; // left character remove kori (count komai)
                left++;          // window shrink korar jonno left aage nei
            }
            maxLen = max(maxLen, right - left + 1); // current valid window length diye max update
            right++;                                // window expand korar jonno right aage nei
        }
        return maxLen; 
    }
};