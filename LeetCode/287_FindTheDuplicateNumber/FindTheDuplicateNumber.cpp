/ 使用数字本身的值来构建一个链表, 重复数值实际上就是链表中的环的入口
// index: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
// value: 1, 3, 7, 6, 8, 8, 10, 2, 4, 5, 9

// link : 1->3->6->10->9->5->8->4->
//                           |<----|

int findDuplicate(vector<int>& nums) {
    if (nums.empty()) {
        return -1;
    }
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    int lenOfCycle = 1;
    fast = nums[fast];
    while (slow != fast) {
        ++lenOfCycle;
        fast = nums[fast];
    }

    slow = nums[0];
    fast = nums[nums[0]];
    --lenOfCycle;
    while(lenOfCycle > 0) {
        fast = nums[fast];
        --lenOfCycle;
    }

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
