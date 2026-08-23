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
    // 两个链表相交，A链表长 a + c， c之后为相交部分；B链表长 b + c
    // 若a = b，则双指针同时到达相交位置
    // 若a != b，则会有一个指针先遍历完，若A先遍历完，则A移动 a + c + b次后；与B移动了 b + c + a次相交
    // 若不相交，则最终A+B都会到达尾部，最后都是nullptr
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == NULL) {
            return nullptr;
        }
        ListNode* pointerA = headA;
        ListNode* pointerB = headB;
        while(pointerA != pointerB) {
            // pA
            if (pointerA == nullptr) {
                pointerA = headB;
            } else {
                pointerA = pointerA->next;
            }
            // pB
            if (pointerB == nullptr) {
                pointerB = headA;
            } else {
                pointerB = pointerB->next;
            }
        }
        return pointerA;
    }
};
