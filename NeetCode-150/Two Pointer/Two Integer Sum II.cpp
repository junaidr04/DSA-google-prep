// Problem: Two Integer Sum II
// Platform: LeetCode
// Link: https://neetcode.io/problems/two-integer-sum-ii/question
// time complexity: O(n)
// space complexity: O(1)


class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;
        while (l < r)
        {
            if (numbers[l] + numbers[r] == target)
            {
                return {l + 1, r + 1};
            }
            else if (numbers[l] + numbers[r] < target)
            {
                l++;
            }
            else if (numbers[l] + numbers[r] > target)
            {
                r--;
            }
        }
    }
};
