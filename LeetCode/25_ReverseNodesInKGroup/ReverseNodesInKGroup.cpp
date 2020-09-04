// k个一组翻转链表
// 给定链表: 1->2->3->4->5
// 若k = 2, 2->1->4->3->5
// 若k = 3, 3->2->1->4->5

// 对链表插入dummyHead 0, 变成 0->1->2->3->4->5
// 0->1->2->3->4->5->6
// |           |
// begin       end

// reverse(begin, end)
// 0->3->2->1->4->5->6
//          |  |
//       begin end


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) {
            return head;
        }
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pBegin = dummyHead;
        ListNode* pCurrent = head;
        int count = 0;
        while (pCurrent != nullptr) {
            ++count;
            if (count % k == 0) {
                // end = pCurrent->next
                pBegin = reverse(pBegin, pCurrent->next);
                pCurrent = pBegin->next;
            }
            else {
                pCurrent = pCurrent->next;
            }
        }

        return dummyHead->next;
    }

    ListNode* reverse(ListNode* pBegin, ListNode* pEnd) {
        // 输入 0->1->2->3->4->5, beg=0, end=4
        ListNode* pPrev = pBegin;
        ListNode* pCurr = pBegin->next;
        ListNode* pNext = nullptr;
        ListNode* pFirstNode = pBegin->next;
        // 0<-1<-2<-3->4->5
        while (pCurr != pEnd) {
            pNext = pCurr->next;
            pCurr->next = pPrev;
            pPrev = pCurr;
            pCurr = pNext;
        }
        // 0->3->2->1->4->5
        pBegin->next = pPrev;
        pFirstNode->next = pCurr;
        return pFirstNode;
    }

};
