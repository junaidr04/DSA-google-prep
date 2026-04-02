// Problem: Minimum Window Substring
// Platform: LeetCode
// Link: https://leetcode.com/problems/minimum-window-substring/
// time complexity: O(n+m) where n is the length of s and m is the length of t, using sliding window approach
// space complexity: O(k) where k is the number of unique characters in t, using hash map to store character counts

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() && t.empty())
        return "";
        // t এর প্রতিটা character কয়বার লাগবে → সেটা store করবো
        unordered_map<char, int> targ;
        // t string ঘুরে character count নিচ্ছি
        for (char c : t)
        {
            targ[c]++; // যেমন: t = "AABC" → A=2, B=1, C=1
        }
        // current window (s এর ভিতরে) character count রাখবো
        unordered_map<char, int> windowCount;
        // left pointer = window এর start
        int left = 0;
        // minimum length track করার জন্য (initially বড় রাখছি)
        int minLen = INT_MAX;
        // minimum window কোথা থেকে শুরু হবে
        int minStart = 0;
        // কতগুলো character already match হয়েছে (valid হয়েছে)
        int formed = 0;
        // right pointer দিয়ে পুরো string traverse করবো
        for (int right = 0; right < s.size(); right++)
        {
            // current character window এ add করছি
            windowCount[s[right]]++;
            // যদি এই character t তে থাকে AND required count match করে
            if (targ.count(s[right]) && windowCount[s[right]] == targ[s[right]])
            {
                formed++; // একটা character fully satisfied
            }
            // যতক্ষণ সব character satisfy (valid window)
            while (formed == targ.size())
            {
                // current window size check করছি
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1; // নতুন ছোট window পেলাম
                    minStart = left;           // কোথা থেকে শুরু remember রাখলাম
                }
                // এখন window ছোট করার চেষ্টা করবো (left move করবো)
                char d = s[left];
                windowCount[d]--; // left character remove করলাম
                // যদি remove করার পরে condition break হয়
                if (targ.count(d) && windowCount[d] < targ[d])
                {
                    formed--; // আর valid না → formed কমে গেল
                }
                left++; // window shrink
            }
        }
        // যদি কোনো valid window না পাই
        if (minLen == INT_MAX)
            return "";
        // না হলে minimum window substring return
        else
            return s.substr(minStart, minLen);
    }
};