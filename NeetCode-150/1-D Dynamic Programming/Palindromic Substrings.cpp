// Problem: Palindromic Substrings
// Platform: NeetCode
// Link: https://neetcode.io/problems/palindromic-substrings
// time complexity: O(n^2) Karon loop ekbar i=2 theke i=n-1 porjonto chole, mane total n-2 ≈ n iterations. Protita iteration e O(1) kaj hocche (shudhu addition and max), tai overall time complexity linear, O(n).
// space complexity: O(1) Karon amra kono extra space use korchi na, shudhu variables use korchi track korar jonno. Tai space complexity constant, O(1).

/*  
Problem Statement

Ekটা string s deya ache। Tomake বের করতে হবে koto গুলো palindromic substring ache totalে (mane koto গুলো substring ache jারা palindrome)।

Important: Same characters (jemon "aaa" e "a" tিনবার) different position e থাকলে সেগুলো আলাদা আলাদা count হবে, even যদি value same হয়।

Example:

s = "abc"
Output: 3

Explanation: "a", "b", "c" — এই ৩টাই palindrome (single character সবসময় palindrome)
s = "aaa"
Output: 6

Explanation: "a", "a", "a" (৩টা single char)
             "aa", "aa" (২টা — index 0-1, ar index 1-2)
             "aaa" (১টা পুরো string)
             Total = 3+2+1 = 6

Verify koro s = "aaa" diye:

Index: 0:a, 1:a, 2:a

i=0:

odd: countFromCenter(s,0,0) → left=0,right=0: match, count=1 → expand: left=-1,right=1, stop (left<0) → return 1
even: countFromCenter(s,0,1) → left=0,right=1: s[0]='a'==s[1]='a', match, count=1 → expand: left=-1,right=2, stop → return 1
total += 1+1 = 2 → total=2

i=1:

odd: countFromCenter(s,1,1) → left=1,right=1: match, count=1 → expand: left=0,right=2: s[0]='a'==s[2]='a', match, count=2 → expand: left=-1,right=3, stop → return 2
even: countFromCenter(s,1,2) → left=1,right=2: s[1]='a'==s[2]='a', match, count=1 → expand: left=0,right=3, stop (right=3 out of bounds) → return 1
total += 2+1 = 3 → total=5

i=2:

odd: countFromCenter(s,2,2) → left=2,right=2: match, count=1 → expand: left=1,right=3, stop (right out of bounds) → return 1
even: countFromCenter(s,2,3) → left=2,right=3: right=3 out of bounds immediately → return 0
total += 1+0 = 1 → total=6

Final: total = 6 ✅ Match kore expected output er sathe!
*/

class Solution
{
public:
    // Helper: ekটা center (left, right) theke expand kore,
    // koto গুলো valid palindrome পাওয়া গেলো সেটার count return kore
    int countFromCenter(string& s, int left, int right)
    {
        int count = 0;
        // jotokkhon boundary thik ache ar character match korche,
        // protিবার ekটা notun palindrome pাওয়া gেলো (tাi count++)
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
            count++;   // ekটা palindrome pাওয়া গেলো, count বাড়াও
        }
        return count;
    }
    
    int countSubstrings(string s)
    {
        int total = 0;
        for(int i = 0; i < s.size(); i++)
        {
            // odd length palindrome (center = single char i)
            int odd = countFromCenter(s, i, i);
            // even length palindrome (center = duটো char i, i+1 er মাঝে)
            int even = countFromCenter(s, i, i+1);
            // duটো theke pাওয়া count total e যোগ koro
            total += odd + even;
        }
        return total;
    }
};