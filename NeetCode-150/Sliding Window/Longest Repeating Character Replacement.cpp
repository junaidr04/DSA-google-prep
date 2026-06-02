// Problem: Longest Repeating Character Replacement
// Platform: NeetCode
// Link: https://neetcode.io/problems/longest-repeating-character-replacement
// time complexity: O(n); single pass through the string
// space complexity: O(1); only 26 uppercase English letters



class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0;
        // এখন পর্যন্ত window এ সবচেয়ে বেশি বার আসা character এর count
        int maxFreq = 0;
        // সবচেয়ে বড় valid window এর length
        int maxLen = 0;
        // প্রতিটা character কতবার আছে window এ
        unordered_map<int, int> freq;
        for (int right = 0; right < s.size(); right++)
        {
            // current character window এ add করো
            freq[s[right]]++;
            // most frequent character এর count update করো
            maxFreq = max(maxFreq, freq[s[right]]);

            // window size = right - left + 1
            // right = window এর শেষ index
            // left = window এর শুরু index
            // উদাহরণ: left=2, right=5 → size = 5-2+1 = 4
            int windowSize = right - left + 1;
            // window invalid হওয়ার condition:
            // windowSize - maxFreq = replace করতে হবে এতগুলো character
            // এটা k এর বেশি হলে window আর valid না
            // উদাহরণ: window="AABBA", maxFreq=3(A), size=5
            // replace দরকার = 5-3 = 2, k=1 হলে invalid!
            if (windowSize - maxFreq > k)
            {
                // বাম থেকে একটা character সরাও
                freq[s[left]]--;
                left++;
            }
            // এই window টা কি এখন পর্যন্ত সবচেয়ে বড়?
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};