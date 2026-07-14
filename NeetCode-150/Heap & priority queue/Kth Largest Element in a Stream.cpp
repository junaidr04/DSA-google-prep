// Problem: Kth Largest Element in a Stream
// Platform: NeetCode
// Link: https://neetcode.io/problems/kth-largest-element-in-a-stream
// time complexity: O(log k) for each insertion into the min-heap, where k is the number of elements in the heap (the size of the stream). The overall time complexity for processing n elements is O(n log k).
// space complexity: O(k) for storing the k largest elements in the min-heap.


class KthLargest
{
public:
    int k; // amra kotota "largest" chai seta store kore rakhtesi (jemon 3rd largest)
    // min-heap banailam - mane heap er sobcheye upore (top e) always sobcheye choto value thakbe
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int> &nums)
    {
        // "this->k" mane class er member variable k
        // r "k" (right side ta) mane function er parameter
        // dutar naam same bole eivabe explicitly bole dite hoy kon ta kake assign hocche
        this->k = k;
        
        // shuru te diye deya shob number heap e ekta ekta kore push kortesi
        for (int x : nums)
        {
            pq.push(x); // notun value heap e dhukailam

            // heap er size jodi k er theke boro hoye jay,
            // tahole sobcheye chota ta (top) felay dao
            if (pq.size() > k)
            {
                pq.pop(); // min-heap er top mane sobcheye chota - eta felaide
            }
        }
    }

    int add(int val)
    {
        pq.push(val); // notun value ashlo stream theke, heap e dhukailam

        // abar check koro size k er theke boro hoye gelo kina
        if (pq.size() > k)
        {
            pq.pop(); // hole, sobcheye chota ta felay dao
        }

        // heap er top mane ekhon je "k" ta largest number ache heap e,
        // tar modhe je sobcheye choto - shei i amader current kth largest
        return pq.top();
    }
};