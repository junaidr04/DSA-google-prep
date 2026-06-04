// Problem: Evaluate Reverse Polish Notation
// Platform: NeetCode
// Link: https://neetcode.io/problems/evaluate-reverse-polish-notation
// time complexity: O(n); traverse the input array once, where n is the number of tokens in the input array.
// space complexity: O(n); in the worst case, when all tokens are operands, the stack will hold all n operands.

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (string t : tokens)
        {
            // token টা operator না হলে number
            // stoi() — string কে int এ convert করে
            if (t != "+" && t != "-" && t != "*" && t != "/")
            {
                st.push(stoi(t));
            }
            else
            {
                // operator আসলে দুইটা number pop করো
                // b আগে pop হয় কারণ এটা পরে push হয়েছিল
                // যেমন: ["2","3","-"] → a=2, b=3 → 2-3=-1
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                // operator দেখে calculate করো
                // result আবার stack এ push করো
                if (t == "+")
                    st.push(a + b);
                else if (t == "-")
                    st.push(a - b);
                else if (t == "*")
                    st.push(a * b);
                else
                    st.push(a / b);
            }
        }
        // শেষে stack এ একটাই number থাকবে — সেটাই answer
        return st.top();
    }
};
