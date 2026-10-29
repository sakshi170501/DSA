#include <queue>
#include <vector>

class MedianFinder {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Stores the larger half
    std::priority_queue<int> maxHeap; // Stores the smaller half

public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the sizes so they differ by at most 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() == 0 && maxHeap.size() == 0) {
            return 0;
        } 
        else if (minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        } 
        else if (minHeap.size() == maxHeap.size() + 1) {
            return minHeap.top();
        } 
        else if (minHeap.size() + 1 == maxHeap.size()) {
            return maxHeap.top();
        } 
        else {
            return -1;
        }
    }
};