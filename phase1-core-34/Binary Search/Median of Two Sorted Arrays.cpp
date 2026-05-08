// Problem: Median of Two Sorted Arrays
// Platform: LeetCode
// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// time complexity: O(log(min(m,n)))
// space complexity: O(1)

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int left = 0, right = m;
        while (left <= right)
        {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            int left1, right1, left2, right2;
            // nums1 er left side er last value
            if (i == 0)
            {
                left1 = INT_MIN;
            }
            else
            {
                left1 = nums1[i - 1];
            }

            // nums1 er right side er first value
            if (i == m)
            {
                right1 = INT_MAX;
            }
            else
            {
                right1 = nums1[i];
            }

            // nums2 er left side er last value
            if (j == 0)
            {
                left2 = INT_MIN;
            }
            else
            {
                left2 = nums2[j - 1];
            }

            // nums2 er right side er first value
            if (j == n)
            {
                right2 = INT_MAX;
            }
            else
            {
                right2 = nums2[j];
            }
            if (left1 <= right2 && left2 <= right1)
            {
                // partition thik ache
                // total element even hole
                if ((m + n) % 2 == 0)
                {
                    int leftMax = max(left1, left2);
                    int rightMin = min(right1, right2);
                    return (leftMax + rightMin) / 2.0;
                }
                else
                {
                    // total element odd hole
                    return max(left1, left2);
                }
            }
            else if (left1 > right2)
            {
                // nums1 theke beshi element niye felsi
                // tai left e jete hobe
                right = i - 1;
            }
            else
            {
                // nums1 theke kom element niyesi
                // tai right e jete hobe
                left = i + 1;
            }
        }
        return 0.0;
    }
};