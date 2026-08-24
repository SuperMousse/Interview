/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 环外长度a, 环长b+c, slow指针入环后走了b与fast相遇
        // slow走过a+b
        // fast走过a+b+n(b+c)
        // 且fast=2*slow, a+b+n(b+c)=2(a+b) -> a = c + (n-1)(b+c)
        // 从相遇点继续走c可以到环起点，从初始点走c+(n-1)(b+c)可以到环起点
        // 从起点和相遇点的两个指针，一直走就会在相遇点相遇
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* pSlow = head;
        ListNode* pFast = head;
        ListNode* pTemp = nullptr;
        int flag = 0; // 用一个flag约束, 第一步的时候不进行判断
        while(pFast->next != nullptr && pFast->next->next != nullptr) {
            if(pSlow == pFast && flag > 0) {
                // 相遇了
                pTemp = head;
                while(pTemp != pSlow) {
                    pTemp = pTemp->next;
                    pSlow = pSlow->next;
                }
                return pTemp;
            }
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            flag = 1;
        }
        return nullptr;
    }
};
