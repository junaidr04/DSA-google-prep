// Problem: Minimum Window Substring
// Platform: NeetCode
// Link: https://neetcode.io/problems/minimum-window-with-characters/question
// time complexity: O(n); single pass through the string
// space complexity: O(1); only 26 uppercase English letters

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int left = 0;
        // have = window এ এখন কতগুলো required character আছে
        int have = 0;
        // t এর প্রতিটা character এর frequency — fixed
        unordered_map<char, int> freq_t;
        // current window এর প্রতিটা character এর frequency
        unordered_map<char, int> freq_s;
        // result এর length আর starting index
        int resLen = INT_MAX, resL = 0;
        // t এর frequency map বানাও
        for (char c : t)
        {
            freq_t[c]++;
        }
        // need = কতগুলো unique character দরকার
        // যেমন t="ABC" → need=3
        int need = freq_t.size();
        for (int right = 0; right < s.size(); right++)
        {
            // current character window এ add করো
            freq_s[s[right]]++;
            // এই character কি t তে দরকার?
            // আর window এ এর count t এর count এর সমান হলে
            // একটা required character পূরণ হয়েছে
            if (freq_t.count(s[right]) && freq_s[s[right]] == freq_t[s[right]])
            {
                have++;
            }
            // have == need মানে valid window পাওয়া গেছে
            // এখন window shrink করে minimum খোঁজো
            while (have == need)
            {
                // এই window টা কি এখন পর্যন্ত সবচেয়ে ছোট?
                if (right - left + 1 < resLen)
                {
                    resLen = right - left + 1;
                    resL = left; // result এর শুরু index save করো
                }
                // বাম থেকে character সরাও
                freq_s[s[left]]--;
                // এই character t তে দরকার ছিল?
                // আর count কমে যাওয়ায় requirement পূরণ হচ্ছে না?
                // তাহলে have কমাও — window আর valid না
                if (freq_t.count(s[left]) && freq_s[s[left]] < freq_t[s[left]])
                {
                    have--;
                }
                left++;
            }
        }
        // কোনো valid window পাওয়া যায়নি
        if (resLen == INT_MAX)
            return "";
        // minimum window substring return করো
        // substr(শুরু index, length)
        return s.substr(resL, resLen);
    }
};