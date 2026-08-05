// Problem: Find Median from Data Stream
// Platform: NeetCode
// Link: https://neetcode.io/problems/median-from-data-stream
// time complexity: O(log n); প্রতিটা push/pop O(1), r amra roughly n-bar এই operation করি
// space complexity: O(1); constant extra space (at most 26 tasks in the heap)


class MedianFinder
{
    priority_queue<int> maxHeap;                            // "choto half" - top e sobcheye boro
    priority_queue<int, vector<int>, greater<int>> minHeap; // "boro half" - top e sobcheye choto
public:
    MedianFinder() {}
    void addNum(int num)
    {
        // Kon heap e prothome push korবা:
        // jodি maxHeap khali, ba num maxHeap er top er theke choto/soman,
        // tahole eta "choto half" e jabe
        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        // Balance rule: maxHeap size, minHeap size er theke max 1 beshi hote pare
        // (kokhono choto hote parbe na, kokhono 2+ boro hote parbe na)
        if (maxHeap.size() > minHeap.size() + 1)
        {
            // maxHeap onek boro hoye gেছে, ekটা element minHeap e pathao
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (maxHeap.size() < minHeap.size())
        {
            // minHeap boro hoye gেছে, ekটা element maxHeap e pathao
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian()
    {
        // jodি maxHeap e extra ekটা element thাকে (odd total),
        // tার top i hocche median
        if (maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        else
        {
            // sizes soman (even total), duiটার top er average
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};