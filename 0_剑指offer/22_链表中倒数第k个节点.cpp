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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        vector<ListNode*> record;
        while (head != nullptr) {
            record.push_back(head);
            head = head->next;
        }
        return record[record.size() - k];
    }
};