// Problem: Kth Largest Element in an Array
// Platform: NeetCode
// Link: https://neetcode.io/problems/kth-largest-element-in-an-array/question
// time complexity: O(n log k); প্রতিটা push/pop O(log k), r amra roughly n-bar এই operation করি
// space complexity: O(k); min-heap e shob number store korte hobe na, sudhu k-ta largest number rakhbo


class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // min-heap, size k e restrict rakhbo
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int val : nums)
        {
            minHeap.push(val);
            // size k theke boro hoye gele, sobcheye chota ta felay dao
            // eivabe heap e shob shomoy "top k largest" thake
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        // heap er top (min) mane oi k-ta largest er modhe sobcheye chota
        // eta i exactly kth largest element
        return minHeap.top();
    }
};