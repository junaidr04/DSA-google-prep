// Problem: Search in Rotated Sorted Array
// Platform: NeetCode
// Link: https://neetcode.io/problems/find-target-in-rotated-sorted-array/question
// time complexity: O(log n); binary search on the rotated array
// space complexity: O(1); only a few variables are used


class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            // target পাওয়া গেছে
            if (nums[mid] == target)
                return mid;

            // বাম অর্ধেক sorted কি না check করো
            // nums[l] <= nums[mid] হলে বাম অর্ধেক sorted
            if (nums[l] <= nums[mid])
            {
                // target কি বাম sorted অর্ধেকে আছে?
                // target < nums[mid] এবং target >= nums[l] হলে বামে
                if (nums[mid] > target && target >= nums[l])
                {
                    r = mid - 1; // বাম অর্ধেকে যাও
                }
                else
                {
                    l = mid + 1; // ডান অর্ধেকে যাও
                }
            }
            else
            {
                // ডান অর্ধেক sorted
                // target কি ডান sorted অর্ধেকে আছে?
                // target > nums[mid] এবং target <= nums[r] হলে ডানে
                if (nums[mid] < target && target <= nums[r])
                {
                    l = mid + 1; // ডান অর্ধেকে যাও
                }
                else
                {
                    r = mid - 1; // বাম অর্ধেকে যাও
                }
            }
        }
        return -1;
    }
};