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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        // 快慢指针，如果有环最终慢指针会被快指针追上
        ListNode* pSlow = head;
        ListNode* pFast = head->next;
        while(pFast->next != nullptr && pFast->next->next != nullptr) {
            if (pSlow == pFast) {
                return true;
            }
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }
        return false;
    }
};
