class Solution {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> value;
        if (head != NULL) {
            value.insert(value.begin(), head->val);
            while (head->next != NULL) {
                value.insert(value.begin(), head->next->val);
                head = head->next;
            }
        }
        return value;
    }
};