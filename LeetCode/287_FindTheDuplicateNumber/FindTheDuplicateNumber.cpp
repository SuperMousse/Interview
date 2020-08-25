// 使用数字本身的值来构建一个链表, 重复数值实际上就是链表中的环的入口
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

// 解法二: 简化解法, 证明
/*
When they meet, assume slow tag move s steps, fast tag move 2s steps, the circle length is c.
There must be:
2s = s + n*c  => s = n*c....(1)
Then, assume the length from start point to entry point is x, and the length from the entry
point to the meet point is a.
There must be: s = x+a....(2)
So, from (1) and (2)
x+a = s = n*c  => x+a = n*c => x+a = (n-1)*c+c => x = (n-1)*c+c-a
c-a means the length from the meetpoint to the entry point.
LHS means: the new tag from start point move x steps.
RHS means: the slow tag moves (n-1) cycles plus the length from the meetpoint to the entry point.
So, we can get the entry point when the new tag meet the slow tag.
*/
int findDuplicate(vector<int>& nums) {
    if (nums.empty()) {
        return -1;
    }
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    fast = 0;
    while (fast != slow)
    {
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}
