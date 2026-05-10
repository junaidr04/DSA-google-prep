// Problem: Valid Parentheses
// Platform: LeetCode
// Link: https://leetcode.com/problems/valid-parentheses/description/
// time complexity: O(n)
// space complexity: O(n)

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;
                char top = st.top();
                if ((c == ')' && top == '(') || (c == ']' && top == '[') ||
                    (c == '}' && top == '{'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
