// 查找中间节点模版题
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, * fast = head;
        // 条件设置为fast->next && fast->next->next
        // 查找中间左节点，即[1,2,3,4,5,6]中的3
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, * fast = head;
        // 条件设置为fast && fast->next
        // 查找中间右节点，即[1,2,3,4,5,6]中的4
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};