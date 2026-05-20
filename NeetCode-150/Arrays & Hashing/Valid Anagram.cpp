// Problem: Valid Anagram
// Platform: LeetCode
// Link: https://neetcode.io/problems/is-anagram/question
// time complexity: O(n)
// space complexity: O(n) ;  n = length of s and t; freq stores up to n distinct character counts.


class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        // frequency map — character -> count
        unordered_map<int, int> freq;
        // s এর প্রতিটা character এর count বাড়াও
        for (int n : s)
        {
            freq[n]++;
        }
        // t এর প্রতিটা character এর count কমাও
        // anagram হলে s আর t এর same characters থাকবে.. তাই সব value 0 হয়ে যাবে
        for (int n : t)
        {
            freq[n]--;
        }
        //প্রতিটা element হলো {key, value} pair।
        //first=key, second=value..
        for (auto it : freq)
        {
            if (it.second != 0)
            {
                return false;
            }
        }
        // সব value 0 → anagram confirmed
        return true;
    }
};
