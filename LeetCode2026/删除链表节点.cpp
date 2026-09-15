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
    void deleteNode(ListNode* node) {
        // 弱智题，出错了，其实是要删除node的next节点
        ListNode* tmp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete tmp; // 回收一下
    }
};
