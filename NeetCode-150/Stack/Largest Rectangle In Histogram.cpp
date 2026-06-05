// Problem: Largest Rectangle In Histogram
// Platform: NeetCode
// Link: https://neetcode.io/problems/largest-rectangle-in-histogram
// time complexity: O(n); each element is pushed and popped from the stack at most once.
// space complexity: O(n); in the worst case, the stack will hold all n elements.



class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // {index, height} pair store করবে
        // index = এই bar কতদূর বাম পর্যন্ত extend করতে পারবে
        stack<pair<int, int>> st;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            // নতুন bar এর rectangle কোথা থেকে শুরু হবে
            // default = current index
            int start = i;

            // current bar আগেরটার চেয়ে ছোট?
            // তাহলে আগেরটা আর ডানে extend করতে পারবে না
            // pop করো আর area calculate করো
            while (!st.empty() && st.top().second > heights[i])
            {
                auto [idx, h] = st.top();
                st.pop();

                // area = height × width
                // width = current index - pop হওয়া bar এর index
                maxArea = max(maxArea, h * (i - idx));

                // pop হওয়া bar এর index থেকে current bar শুরু হতে পারবে
                // কারণ ওই জায়গা এখন available
                start = idx;
            }

            // current bar push করো
            // start = কতদূর বাম পর্যন্ত extend করতে পারবে
            st.push({start, heights[i]});
        }

        // loop শেষে stack এ যা বাকি আছে
        // এরা সবাই array এর শেষ পর্যন্ত extend করতে পারে
        while (!st.empty())
        {
            auto [idx, h] = st.top();
            st.pop();

            // width = array এর শেষ - bar এর index
            maxArea = max(maxArea, h * ((int)heights.size() - idx));
        }
        return maxArea;
    }
};
