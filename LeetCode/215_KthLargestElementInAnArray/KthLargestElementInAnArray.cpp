// 方法一: multiset红黑树, 时间复杂度O(NlogK), 红黑树logK查找删除插入, N个节点
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

// 方法二: 二分+partition, 时间复杂度O(2n)
