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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n <= 0) {
            return head;
        }
        // 当要删除的是头节点时，需要head前面还有一个节点，此时需要dummy
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        for (int i = 0; i < n; i++) {
            if(fast == nullptr) {
                return head;
            }
            fast = fast->next;
        }
        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* next = slow->next;
        slow->next = slow->next->next;
        return dummy.next;
    }
};
