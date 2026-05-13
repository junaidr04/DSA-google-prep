// Problem: Find Median from Data Stream
// Platform: LeetCode
// Link: https://leetcode.com/problems/find-median-from-data-stream/description/
// time complexity: O(logn)
// space complexity: O(n)

class MedianFinder
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        else
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */