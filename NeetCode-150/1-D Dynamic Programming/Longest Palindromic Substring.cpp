// Problem: Longest Palindromic Substring
// Platform: NeetCode
// Link: https://neetcode.io/problems/longest-palindromic-substring
// time complexity: O(n^2) Karon loop ekbar i=2 theke i=n-1 porjonto chole, mane total n-2 ≈ n iterations. Protita iteration e O(1) kaj hocche (shudhu addition and max), tai overall time complexity linear, O(n).
// space complexity: O(1) Karon amra kono extra space use korchi na, shudhu variables use korchi track korar jonno. Tai space complexity constant, O(1).


/*
 Problem Statement

Ekটা string s deya ache। Tomake shob theke lamba palindromic substring ber korte hবে (substring mane consecutive characters, subsequence na)।
Palindrome মনে koro: Ekটা string jeta samne theke pоড়লে আর pিছন theke pоড়লে same hয় (jemon "aba", "racecar")।

Example:

s = "babad"
Output: "bab"  (অথবা "aba" ও valid, দুটোই length 3)
s = "cbbd"
Output: "bb"
Approach: Expand Around Center (eta most common ar efficient approach interview e)

Key Insight: Ekটা palindrome er ekটা center থাকে। Center theke duদিকে (left, right) expand korলে palindrome বাড়ে, jotokkhon না duদিকের character mismatch hচ্ছে।

Duটো ধরনের center হতে পারে:

Odd length palindrome (jemon "aba") — center ekটা single character
Even length palindrome (jemon "abba") — center duটো character এর মাঝখানে

Algorithm:

Protিটা index i ke center dhore, duদিকে (odd ar even duটো case) expand koro
Jotokkhon s[left] == s[right] হচ্ছে, ততক্ষণ expand koro (left--, right++)
Protিবার maximum length palindrome track koro
Nijeke jiggasha koro
Helper function lagবে — jেটা ekটা center (left, right) niয়ে expand kore ar palindrome এর length/indices return kore
Main loop e — protিটা index i ke center dhore duটো call koro:
Odd case: expand(s, i, i)
Even case: expand(s, i, i+1)
Track korতে হবে — এখন পর্যন্ত shob theke lamba palindrome এর start index ar length
*/

class Solution
{
public:
    // Helper function: ekটা "center" (left, right) theke duদিকে expand kore
    // return kore shob theke বড় palindrome এর start ar end index
    pair<int,int> expandFromCenter(string& s, int left, int right)
    {
        // Jotokkhon:
        //   1) left index valid (0 er niche na jay)
        //   2) right index valid (string er size er baire na jay)
        //   3) left ar right position er character same hয়
        // ততক্ষণ duদিকে expand korতে থাকো
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;   // left dিকে ekটা step pিছিয়ে jাও
            right++;  // right dিকে ekটা step এগিয়ে jাও
        }
        
        // Loop যখন বন্ধ হয়, তখন left/right "এক ধাপ বেশি" চলে গেছে
        // (mismatch হয়েছে বলে বা boundary পেরিয়ে গেছে বলে)
        // তাই আসল palindrome এর সঠিক boundary পেতে ekটা step পিছনে আসতে হবে
        left += 1;   // left ke এক ধাপ ডানে (mane আসল palindrome এর শুরুতে) আনো
        right -= 1;  // right ke এক ধাপ বামে (mane আসল palindrome এর শেষে) আনো
        
        // এখন left ar right হলো actual palindrome এর start ar end index
        return {left, right};
    }
    
    string longestPalindrome(string s)
    {
        // start = এখন পর্যন্ত পাওয়া best palindrome এর শুরুর index
        // maxLen = এখন পর্যন্ত পাওয়া best palindrome এর length
        // Default: প্রতিটা string এ কমপক্ষে 1 character এর palindrome তো থাকবেই
        int start = 0, maxLen = 1;
        
        // প্রতিটা index কে "center" ধরে expand করবো
        for(int i = 0; i < s.size(); i++)
        {
            // ---- ODD LENGTH palindrome check (jemon "aba", center = single char) ----
            // center হলো একটাই index (i, i) - দুই পাশে সমান দূরত্বে expand হবে
            auto odd = expandFromCenter(s, i, i);
            
            // length বের করা: end - start + 1 (indices count করার formula)
            int oddLen = odd.second - odd.first + 1;
            
            // যদি এই palindrome আগের best থেকে বড় হয়, তাহলে update করো
            if(oddLen > maxLen)
            {
                maxLen = oddLen;
                start = odd.first;
            }
            
            // ---- EVEN LENGTH palindrome check (jemon "abba", center = duটো char এর মাঝে) ----
            // center হলো (i, i+1) - দুটো adjacent index
            auto even = expandFromCenter(s, i, i+1);
            int evenLen = even.second - even.first + 1;
            
            if(evenLen > maxLen)
            {
                maxLen = evenLen;
                start = even.first;
            }
        }
        
        // start theke maxLen দৈর্ঘ্যের substring কেটে নিয়ে return korো - এটাই answer
        return s.substr(start, maxLen);
    }
};

/*
Index:

0: b
1: a
2: b
3: a
4: d
i = 0 ('b')

Odd check: expandFromCenter(s, 0, 0)

left=0, right=0: s[0]==s[0] ('b'=='b') -> match! expand: left=-1, right=1
left=-1, right=1: left<0, loop condition FALSE, stop
Adjust: left = -1+1 = 0, right = 1-1 = 0
Return: {0, 0}  -> length = 0-0+1 = 1

oddLen=1, eta maxLen(1) theke বড় না, tাi কোনো update নেই।

Even check: expandFromCenter(s, 0, 1)

left=0, right=1: s[0]='b', s[1]='a' -> mismatch! loop condition FALSE immediately
Adjust: left=0+1=1, right=1-1=0
Return: {1, 0}  -> length = 0-1+1 = 0

evenLen=0 (invalid palindrome, karon end < start), কোনো update নেই।

i = 1 ('a')

Odd check: expandFromCenter(s, 1, 1)

left=1, right=1: s[1]==s[1] ('a'=='a') -> match! expand: left=0, right=2
left=0, right=2: s[0]='b', s[2]='b' -> match! expand: left=-1, right=3
left=-1, right=3: left<0, stop
Adjust: left=-1+1=0, right=3-1=2
Return: {0, 2}  -> length = 2-0+1 = 3  ("bab")

oddLen=3 > maxLen(1) → update! maxLen=3, start=0

Even check: expandFromCenter(s, 1, 2)

left=1, right=2: s[1]='a', s[2]='b' -> mismatch, stop immediately
Adjust: left=2, right=1
Return: {2,1} -> length = 1-2+1 = 0

কোনো update নেই।

i = 2 ('b')

Odd check: expandFromCenter(s, 2, 2)

left=2,right=2: match ('b'=='b') -> expand: left=1,right=3
left=1,right=3: s[1]='a', s[3]='a' -> match! expand: left=0,right=4
left=0,right=4: s[0]='b', s[4]='d' -> mismatch, stop
Adjust: left=1, right=3
Return: {1,3} -> length=3-1+1=3  ("aba")

oddLen=3, kিন্তু maxLen already 3 — strictly বড় না হলে update হবে না, tাi update নেই (start আগের মতোই 0 থাকবে, "bab")।

Even check: mismatch hবে, kono update na।

i = 3, 4 — এগুলোও check হবে, kিন্তু কোনো বড় palindrome পাওয়া যাবে না (তুমি নিজে dry-run করে verify korতে পারো practice হিসেবে)।
Final Result
start = 0, maxLen = 3
s.substr(0, 3) = "bab"

Output: "bab" ✅ (matches expected)

Kano এই approach কাজ করে (intuition)

Ekটা palindrome সবসময় একটা "center" থেকে symmetric হয়। তাই যদি তুমি প্রতিটা সম্ভাব্য center থেকে বাইরের দিকে expand করো (যতক্ষণ দুই পাশের character মিলছে), তাহলে সেই center-ভিত্তিক সবচেয়ে বড় palindrome তুমি পেয়ে যাবে। যেহেতু palindrome এর length odd (single center) অথবা even (দুই center) দুটোই হতে পারে, তাই দুই ধরনের center-ই check করতে হয়।
*/