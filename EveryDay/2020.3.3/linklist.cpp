// 链表拆分奇偶节点
ListNode* oddEvenList(ListNode* head) {
            if (head == nullptr || head->next == nullptr) {
                return head;
            }
            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* evenHead = even;
            while (even != nullptr && even->next != nullptr) {
                odd->next = odd->next->next;
                even->next = even->next->next;
                odd = odd->next;
                even = even->next;
            }
            odd->next = evenHead;
            return head;
        }



// 链表平均分成k份
vector<ListNode*> splitListToParts(ListNode* root, int k) {
    if (root == nullptr) {
        return vector<ListNode*>(k, nullptr);
    }
    ListNode* pNode = root;
    int listNum = 0;
    while (pNode != nullptr) {
        ++listNum;
        pNode = pNode->next;
    }
    int split = listNum / k; // 大部分整除
    int rest = listNum % k; // 剩余部分平均分配到前rest个里面
    vector<ListNode*> result(k, nullptr);
    pNode = root;
    ListNode* pPrev = nullptr;
    for (int i = 0; i < k && pNode != nullptr; ++i, --rest) {
        result[i] = pNode;
        int segment = split + (rest > 0 ? 1 : 0);
        for (int j = 0; j < segment; ++j) {
            pPrev = pNode;
            pNode = pNode->next;
        }
        pPrev->next = nullptr;
    }
    return result;
}
