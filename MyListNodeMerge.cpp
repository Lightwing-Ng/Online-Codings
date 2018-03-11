class Solution {
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        ListNode *p1, *p2, *p;
        if (!pHead1)
            return pHead2;
        else if (!pHead2)
            return pHead1;
        p1 = pHead1->val < pHead2->val ? pHead1 : pHead2;
        p = p1;
        p2 = p1 == pHead1 ? pHead2 : pHead1;
        ListNode *temp;
        while (p2) {
            while (p1->next && p1->next->val < p2->val)
                p1 = p1->next;
            temp = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = temp;
        }
        return p;
    }
};