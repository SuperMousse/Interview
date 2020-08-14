// 方法一： 小顶堆

int findKthLargest(vector<int>& nums, int k) {
    if (nums.empty() || k < 1 || nums.size() < k) {
        return -1;
    }
    vector<int> heap;
    for (int i = 0; i < k; ++i) {
        heap.push_back(nums[i]);
    }
    make_heap(heap.begin(), heap.end(), greater<int>());

    for (int i = k; i < nums.size(); ++i) {
        int top = heap[0];
        if (nums[i] > top) {
            pop_heap(heap.begin(), heap.end(), greater<int>());
            heap.pop_back();
            heap.push_back(nums[i]);
            push_heap(heap.begin(), heap.end(), greater<int>());
        }
    }

    return heap[0];
}



// 方法二: multiset红黑树, 时间复杂度O(NlogK), 红黑树logK查找删除插入, N个节点
int findKthLargest(vector<int>& nums, int k) {
    if (nums.empty()) {
        return 0;
    }
    multiset<int, greater<int> > KSet;
    for(int num : nums) {
        if (KSet.size() < k) {
            KSet.insert(num);
        }
        else {
            multiset<int, greater<int> >::iterator it = --KSet.end(); // 从大到小
            if (num > *it) {
                KSet.erase(it);
                KSet.insert(num);
            }
        }
    }
    int result = *(--KSet.end());
    return result;

}

// 方法三: 二分+partition, 时间复杂度O(2n)
