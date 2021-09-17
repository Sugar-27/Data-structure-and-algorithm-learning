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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 建立一个保护节点
        ListNode* protect = new ListNode(0);
        protect->next = head;

        // 分组（找到每一组的开始和结尾），按组遍历
        // last = 上一组结尾
        ListNode* lastNode = protect;
        while (head != nullptr) {
            ListNode* end = getEnd(head, k);
            if (end == nullptr)
                break;

            // 反转head-end之间的链表，反转之后head成为新表的尾，end成为新表的头
            ListNode* nextGroupNode = end->next;
            reverseList(head, end);
            head->next = nextGroupNode;
            lastNode->next = end;

            // last和head分别后移，为下一组反转做准备
            lastNode = head;
            head = head->next;
        }
        return protect->next;
    }

    ListNode* getEnd(ListNode* head, int k) {
        while (head != nullptr) {
            k--;
            if (k == 0)
                break;
            head = head->next;
        }
        return head;
    }

    void reverseList(ListNode* head, ListNode* end) {
        if (head == end)
            return;
        ListNode* lastNode = head;
        head = head->next;
        while (head != end) {
            ListNode* nextHead = head->next;
            head->next = lastNode;
            lastNode = head;
            head = nextHead;
        }
        head->next = lastNode;  // head == end时退出循环，最后一条边还没有反转
    }
};