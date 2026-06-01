// Problem: Longest Substring Without Repeating Characters
// Platform: NeetCode
// Link: https://neetcode.io/problems/longest-substring-without-repeating-characters
// time complexity: O(n); single pass through the string
// space complexity: O(min(m,n)); m is the size of the character set


class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // duplicate track করার জন্য HashSet
        unordered_set<char> st;
        // left = window এর শুরু
        int left = 0;
        // সবচেয়ে বড় window এর length
        int maxLen = 0;
        // right = window এর শেষ, এগাতে থাকো
        for (int right = 0; right < s.size(); right++)
        {
            // s[right] কি already window এ আছে?
            // থাকলে duplicate — window shrink করো
            while (st.count(s[right]))
            {
                // বাম থেকে character সরাও
                st.erase(s[left]);
                left++;
            }

            // current character window এ add করো
            st.insert(s[right]);

            // এই window টা কি এখন পর্যন্ত সবচেয়ে বড়?
            // window size = right - left + 1
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};