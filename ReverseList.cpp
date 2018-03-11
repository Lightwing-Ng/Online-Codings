class Solution {
public:
    ListNode *ReverseList(ListNode *pHead) {
        if (!pHead || !pHead->next)
            return pHead;
        ListNode *p = pHead;
        ListNode *q = pHead->next;
        ListNode *temp;
        p->next = NULL;
        while (q->next) {
            temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        q->next = p;
        return q;
    }
};