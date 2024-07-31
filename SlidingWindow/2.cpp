#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

// Function to balance the heaps
void balanceHeaps(priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap)
{
    if (maxHeap.size() > minHeap.size() + 1)
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if (minHeap.size() > maxHeap.size())
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

// Function to remove an element from maxHeap
void removeElement(priority_queue<int> &heap, int element)
{
    priority_queue<int> tempHeap;
    while (!heap.empty())
    {
        if (heap.top() == element)
        {
            heap.pop();
            break;
        }
        else
        {
            tempHeap.push(heap.top());
            heap.pop();
        }
    }
    while (!tempHeap.empty())
    {
        heap.push(tempHeap.top());
        tempHeap.pop();
    }
}

// Function to remove an element from minHeap
void removeElement(priority_queue<int, vector<int>, greater<int>> &heap, int element)
{
    priority_queue<int, vector<int>, greater<int>> tempHeap;
    while (!heap.empty())
    {
        if (heap.top() == element)
        {
            heap.pop();
            break;
        }
        else
        {
            tempHeap.push(heap.top());
            heap.pop();
        }
    }
    while (!tempHeap.empty())
    {
        heap.push(tempHeap.top());
        tempHeap.pop();
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    priority_queue<int> maxHeap;                            // Max heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for the larger half

    vector<int> result;

    for (int i = 0; i < n; ++i)
    {
        if (maxHeap.empty() || arr[i] <= maxHeap.top())
        {
            maxHeap.push(arr[i]);
        }
        else
        {
            minHeap.push(arr[i]);
        }

        balanceHeaps(maxHeap, minHeap);

        if (i >= k)
        {
            if (arr[i - k] <= maxHeap.top())
            {
                removeElement(maxHeap, arr[i - k]);
            }
            else
            {
                removeElement(minHeap, arr[i - k]);
            }
            balanceHeaps(maxHeap, minHeap);
        }

        if (i >= k - 1)
        {
            result.push_back(maxHeap.top());
        }
    }

    for (int i = 0; i < result.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
