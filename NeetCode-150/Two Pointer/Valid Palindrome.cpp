// Problem: Valid Palindrome
// Platform: LeetCode
// Link: https://neetcode.io/problems/is-palindrome/question
// time complexity: O(n)
// space complexity: O(1)


class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            // বাম থেকে alphanumeric না হলে skip করো
            // যেমন space, comma, colon → skip\
            //C++ এ isalnum(c) দিয়ে alphanumeric check করা যায়
            if (!isalnum(s[l]))
            {
                l++;
            }
            // ডান থেকে alphanumeric না হলে skip করো
            else if (!isalnum(s[r]))
            {
                r--;
            }
            // দুইটাই valid — এখন compare করো
            // tolower() দিয়ে case ignore করো
            // 'A' আর 'a' কে same ধরো
            else if (tolower(s[l]) != tolower(s[r]))
            {
                // মিলছে না → palindrome না
                return false;
            }
            else
            {
                // মিলেছে → দুইটাই ভেতরে আনো
                l++;
                r--;
            }
        }
        return true;
    }
};