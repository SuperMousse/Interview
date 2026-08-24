/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* pHead = nullptr;
        ListNode* pCurrent = head;
        ListNode* pPre = nullptr;
        ListNode* pNext = nullptr;
        while(pCurrent != nullptr) {
            pNext = pCurrent->next;
            if (pNext == nullptr) {
                pHead = pCurrent;
            }
            pCurrent->next = pPre;
            pPre = pCurrent;
            pCurrent = pNext;
        }
        return pHead;
    }
};
