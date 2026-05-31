// Problem: Min Stack
// Platform: NeetCode
// Link: https://neetcode.io/problems/min-stack
// time complexity: O(1) for all operations
// space complexity: O(n) for the stack and O(n) for the min stack in the worst case when all elements are in decreasing order.


class MinStack
{
    stack<int> st;
    stack<int> minSt;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        if (minSt.empty())
        {
            minSt.push(val);
        }
        else
        {
            minSt.push(min(val, minSt.top()));
        }
    }

    void pop()
    {
        st.pop();
        minSt.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};