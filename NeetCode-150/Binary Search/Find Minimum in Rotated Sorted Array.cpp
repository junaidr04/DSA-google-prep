// Problem: Find Minimum in Rotated Sorted Array
// Platform: NeetCode
// Link: https://neetcode.io/problems/find-minimum-in-rotated-sorted-array/question
// time complexity: O(log n); binary search on the rotated array
// space complexity: O(1); only a few variables are used


class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        // boundary search — loop শেষে l == minimum এর index
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            // nums[mid] > nums[r] মানে drop টা ডানে আছে
            // যেমন: [4,5,6,7,0,1,2] এ mid=7, r=2 → 7>2 → drop ডানে
            // তাই minimum ডানে → l এগাও
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                // nums[mid] <= nums[r] মানে drop বামে বা mid তেই
                // যেমন: [4,5,6,7,0,1,2] এ mid=0, r=2 → 0<2 → drop বামে
                // mid টাই minimum হতে পারে → r=mid (mid বাদ দিও না)
                r = mid;
            }
        }
        // l == minimum element এর index
        return nums[l];
    }
};