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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* protect = new ListNode(0);
        protect->next = head;
        ListNode* pre = protect;
        while (head != nullptr) {
            if (head->val == val) {
                pre->next = head->next;
                break;
            }
            head = head->next;
            pre = pre->next;
        }
        return protect->next;
    }
};