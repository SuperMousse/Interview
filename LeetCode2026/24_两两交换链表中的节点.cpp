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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode dummy(0, head);
        ListNode* dummyHead = &dummy;
        ListNode* pCurr = dummyHead;
        while(pCurr->next != nullptr && pCurr->next->next != nullptr) {
            ListNode* pFirst = pCurr->next;
            ListNode* pSecond = pCurr->next->next;
            pCurr->next = pSecond;
            pFirst->next = pSecond->next;
            pSecond->next = pFirst;
            pCurr = pFirst;
        }
        return dummyHead->next;
    }
};
