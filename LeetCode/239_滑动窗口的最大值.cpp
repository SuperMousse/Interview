class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.size() < k) {
            return result; 
        }
        deque<int> intQueue; // 存储了k个窗口内最大值的index，存index是为了方便滑窗索引，如果只存值，不方便找到窗口
        int currentNum = 0;
        int maxNum = INT_MIN;
        // 前k个，如果新扫描的值比队尾的大，那么就应该把历史的int都退出去，从而保证队列里面是最大的值
        for (int i = 0; i < k; i++) {
            while(!intQueue.empty() && nums[i] >= nums[intQueue.back()]) {
                intQueue.pop_back();
            }
            intQueue.push_back(i); // push索引进去
        }
        result.push_back(nums[intQueue.front()]);
        // k个以后
        for(int i = k; i < nums.size(); i++) {
            while(!intQueue.empty() && nums[i] >= nums[intQueue.back()]) {
                intQueue.pop_back();
            }
            intQueue.push_back(i); // push索引进去
            // 把超出窗口k的都pop出去
            while(intQueue.front() <= i - k) {
                intQueue.pop_front();
            }
            result.push_back(nums[intQueue.front()]);
        }
        return result;
    }
};
