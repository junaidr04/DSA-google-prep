// Problem: Container With Most Water
// Platform: NeetCode
// Link: https://neetcode.io/problems/max-water-container/question
// time complexity: O(n); only one traverse
// space complexity: O(1); Nothing extra space


class Solution
{
public:
    int maxArea(vector<int> &heights)
    {

        int l = 0, r = heights.size() - 1;
        // সবচেয়ে বেশি water track করবে
        int ans = 0;
        while (l < r)
        {
            // দুই pointer এর দূরত্ব = width
            int width = r - l;
            // ছোট height দিয়ে water নির্ধারিত হয়
            // কারণ বড় হলেও ছোটটা পর্যন্তই ধরবে
            int height = min(heights[l], heights[r]);
            // water = width × height
            int water = width * height;
            // এটা কি এখন পর্যন্ত সবচেয়ে বেশি?
            ans = max(ans, water);
            // ছোট height এর pointer এগাও
            // বড়টা রেখে দিলে chance আছে আরো বেশি water পাওয়ার
            if (heights[l] < heights[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};