// Problem: Time Based Key-Value Store
// Platform: NeetCode
// Link: https://neetcode.io/problems/time-based-key-value-store/question
// time complexity: O(log m) per get operation, where m is the number of timestamps for a key; O(1) for set operation
// space complexity: O(n) for storing all key-timestamp-value entries, where n is the total number of set operations



class TimeMap
{
    // key → [(timestamp, value)] sorted by timestamp
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        // timestamp সবসময় increasing আসে
        // তাই push করলেই sorted থাকবে
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        // key না থাকলে empty return করো
        if (mp.find(key) == mp.end())
            return "";

        auto &v = mp[key];
        int l = 0, r = v.size() - 1;

        // সবচেয়ে recent valid value
        string ans = "";

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            // এই timestamp টা given timestamp এর মধ্যে?
            // হলে এটা valid → save করো, আরো ডানে দেখো
            // কারণ আরো recent valid value থাকতে পারে
            if (v[mid].first <= timestamp)
            {
                ans = v[mid].second;
                l = mid + 1;
            }
            else
            {
                // timestamp বড় → বামে যাও
                r = mid - 1;
            }
        }
        return ans;
    }
};