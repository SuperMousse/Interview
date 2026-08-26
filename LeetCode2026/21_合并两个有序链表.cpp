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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode* head = nullptr;
        ListNode* current = nullptr;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                if (head == nullptr) {
                    head = list1;
                    current = list1;
                } else {
                    current->next = list1;
                    current = current->next;
                }
                list1 = list1->next;
            } else {
                if(head == nullptr) {
                    head = list2;
                    current = list2;
                } else {
                    current->next = list2;
                    current = current->next;
                }
                list2 = list2->next;
            }
        }

        if (list1 != nullptr) {
            current->next = list1;
        }
        if (list2 != nullptr) {
            current->next = list2;
        }
        return head;
    }
};

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode* head;
        if (list1->val < list2->val) {
            head = list1;
            head->next = mergeTwoLists(list1->next, list2);
        } else {
            head = list2;
            head->next = mergeTwoLists(list1, list2->next);
        }
        return head;

    }
};
