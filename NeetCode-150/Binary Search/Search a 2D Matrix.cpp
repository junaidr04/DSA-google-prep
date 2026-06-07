// Problem: Search a 2D Matrix
// Platform: NeetCode
// Link: https://neetcode.io/practice/search-a-2d-matrix
// time complexity: O(log(m*n)); binary search on the entire matrix, treating it as a sorted array
// space complexity: O(1); only a few variables are used


class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();    // মোট row সংখ্যা
        int col = matrix[0].size(); // মোট column সংখ্যা

        // পুরো matrix কে একটা 1D sorted array মনে করো
        // L = প্রথম element, R = শেষ element
        int l = 0, r = row * col - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            // mid index থেকে actual matrix value বের করো
            // mid/col = কোন row তে আছে
            // mid%col = কোন column তে আছে
            // যেমন: 4x4 matrix এ mid=6 → row=6/4=1, col=6%4=2
            int val = matrix[mid / col][mid % col];
            if (val == target)
            {
                return true;
            }
            else if (val < target)
            {
                // target ডানে আছে → L এগাও
                l = mid + 1;
            }
            else
            {
                // target বামে আছে → R কমাও
                r = mid - 1;
            }
        }
        return false;
    }
};