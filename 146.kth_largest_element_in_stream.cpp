#include <bits/stdc++.h>
using namespace std;

/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order,
not the kth distinct element.

Implement KthLargest class:
KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

*/

class KthLargest
{
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int> &nums)
    {
        for (auto it : nums)
        {
            pq.push(it);
            if (pq.size() > k)
                pq.pop();
        }
        this->k = k;
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};

int main()
{

    return 0;
}