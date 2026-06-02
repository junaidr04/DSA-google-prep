// Permutation মানে same characters, same frequency — শুধু order আলাদা। তাহলে s2 তে s1.size() এর fixed window রেখে check করো — window এর frequency কি s1 এর frequency এর সমান?


// Problem: Permutation in String
// Platform: NeetCode
// Link: https://neetcode.io/problems/permutation-string/question
// time complexity: O(n); single pass through the string
// space complexity: O(1); only 26 uppercase English letters


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        // s1 এর প্রতিটা character এর frequency
        // এটা fixed — কখনো change হবে না
        unordered_map<int, int> freq1;
        // current window এর প্রতিটা character এর frequency
        unordered_map<int, int> freq2;
        // s1 s2 এর চেয়ে বড় হলে permutation থাকা সম্ভব না
        if (s1.size() > s2.size())
            return false;
        // s1 এর frequency map আগেই বানিয়ে নাও
        for (char c : s1)
        {
            freq1[c]++;
        }
        for (int right = 0; right < s2.size(); right++)
        {
            // current character window এ add করো
            freq2[s2[right]]++;
            // window size s1 এর চেয়ে বড় হলে shrink করো
            if (right - left + 1 > s1.size())
            {
                // বাম থেকে character এর count কমাও
                freq2[s2[left]]--;
                // count 0 হলে map থেকে সরিয়ে দাও
                // না সরালে freq1 == freq2 compare এ fail করবে
                // কারণ freq2 তে extra 0 value key থাকবে
                if (freq2[s2[left]] == 0)
                freq2.erase(s2[left]);
                left++;
            }
            if (freq1 == freq2)
            {
                return true;
            }
        }
        return false;
    }
};
