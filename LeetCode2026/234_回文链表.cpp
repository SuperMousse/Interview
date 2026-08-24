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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return true;
        }
        vector<int> array(1e5, 0);
        int count = 0;
        while(head != nullptr) {
            array[count] = head->val;
            head = head->next;
            count++;
        }
        int pre = 0;
        int last = count - 1;
        while(pre < last) {
            if(array[pre] != array[last]) {
                return false;
            }
            pre++;
            last--;
        }
        return true;
    }
};
