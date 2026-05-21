// Problem: Group Anagrams
// Platform: NeetCode
// Link: https://neetcode.io/problems/anagram-groups/question
// time complexity: O(n·k log k); There are n strings..Sorting each string takes k log k time, where k is the length of the string.
// space complexity: O(n); All strings are stored inside the map.


class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // sorted string -> [anagram group] store korbe
        unordered_map<string, vector<string>> mp;
        // প্রতিটা string এর জন্য
        for (string n : strs)
        {
            // original string er copy banao
            // karon sort korle original change hoe jabe
            string s = n;
            // copy ta sort koro — ei ta hobe key
            // "eat" -> "aet", "tea" -> "aet", "ate" -> "aet"
            // same anagram er same key hobe
            sort(s.begin(), s.end());
            // original string ta tar key er group e add koro
            mp[s].push_back(n);
        }
        vector<vector<string>> ans;
        // map er protekta entry theke
        // value (vector<string>) ta result e add koro
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};