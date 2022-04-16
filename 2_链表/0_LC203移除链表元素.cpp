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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* protect = new ListNode(0, head);
        ListNode* pre = protect;
        while (head) {
            if (head->val == val) {
                pre->next = head->next;
            } else {
                pre = pre->next;
            }
            head = head->next;
        }
        return protect->next;
    }
};