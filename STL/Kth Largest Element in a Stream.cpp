// Problem link ---->
https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

// Solution ---->
class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

    KthLargest(int k, vector<int>& nums) {
        size = k;

        for (auto& val: nums) {
            add(val);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > size) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */