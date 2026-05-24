// Problem: Longest Consecutive Sequence
// Platform: Neetcode
// Link: https://neetcode.io/problems/longest-consecutive-sequence/question
// time complexity: O(n) ;  Each element enters the while loop only once.
// space complexity: O(n) ; hashset


class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // সব elements HashSet এ রাখো → O(1) lookup এর জন্য
        unordered_set<int> st(nums.begin(), nums.end());
        // সবচেয়ে বড় sequence এর length track করবে
        int ans = 0;
        for (int num : nums)
        {
            // num-1 set এ নেই মানে এটাই sequence এর শুরু
            // যেমন: 1 এর আগে 0 নেই → 1 থেকে শুরু
            // কিন্তু 3 এর আগে 2 আছে → 3 শুরু না, skip
            if (st.find(num - 1) == st.end())
            {
                int curr = num; // current position
                int count = 1;  // sequence এর length, কমপক্ষে 1
                // পরের element set এ আছে কি না check করো
                // থাকলে এগিয়ে যাও
                while (st.find(curr + 1) != st.end())
                {
                    curr++;  // পরের element এ যাও
                    count++; // length বাড়াও
                }
                // এই sequence টা কি এখন পর্যন্ত সবচেয়ে বড়?
                ans = max(count, ans);
            }
        }
        return ans;
    }
};