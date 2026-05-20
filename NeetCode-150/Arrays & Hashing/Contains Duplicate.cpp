// Problem: Contains Duplicate
// Platform: LeetCode
// Link: https://neetcode.io/problems/duplicate-integer/question
// time complexity: O(n^2)
// space complexity: O(1)

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        // eikhne ekta loop cholbe 0 theke, arekta loop cholbe tar porer index theke(i+1).. duita chk korbe same kina...
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};


// Better approach..
//  TC: O(n)
//  SC: O(n)

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        // hashSet a element rekhe dewa hoi.. porer element ashle chk kore element already ase kina...
        unordered_set<int> Set;
        for (int n : nums)
        {
            if (Set.count(n))
            {
                return true;
            }
            // jodi element ta set a na thake thle insert korte hbe...
            Set.insert(n);
        }
        return false;
    }
};


// TC: O(nlogn)
// SC: O(1)

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 1; i++) //(int) cast করলে 0-1 = -1 হবে, loop ই শুরু হবে না। i < nums.size() রাখলে আর -1 লাগবে না, কিন্তু তাহলে nums[i+1] আবার out of bounds হবে শেষ element এ।
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return false;
    }
};

// Time এর দিক থেকে → HashSet সবচেয়ে fast। Space এর দিক থেকে → Sort সবচেয়ে efficient। Google interview তে "most optimal" বললে generally HashSet — কারণ time complexity কে বেশি priority দেওয়া হয়। Space সাধারণত cheap, time expensive। কিন্তু interviewer যদি "O(1) space এ করো" বলে — তখন Sort।