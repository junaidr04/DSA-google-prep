// Problem: Daily Temperatures
// Platform: NeetCode
// Link: https://neetcode.io/problems/daily-temperatures
// time complexity: O(n); traverse the input array once, where n is the number of elements in the input array.
// space complexity: O(n); in the worst case, when all temperatures are in decreasing order, the stack will hold all n temperatures.


class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // indices store করার জন্য stack
        // value না, index রাখবো — পরে দূরত্ব বের করতে সুবিধা
        stack<int> st;
        int n = temperatures.size();
        // সব answer 0 দিয়ে initialize করো
        // warmer day না পেলে 0 থাকবে
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            // current temperature কি stack এর top এর চেয়ে বেশি?
            // মানে আজকের দিনটা stack এর top এর জন্য warmer day!
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                // কতদিন পরে warmer day পেলো = i - st.top()
                ans[st.top()] = i - st.top();

                // সেই index আর দরকার নেই → pop করো
                st.pop();
            }
            // current index stack এ রাখো
            // পরে কোনো warmer day আসলে এর answer update হবে
            st.push(i);
        }
        return ans;
    }
};