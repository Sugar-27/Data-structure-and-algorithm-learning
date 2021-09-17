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
    ListNode* reverseList(ListNode* head) {
        // 新建一个节点用来记录上一个节点
        ListNode* lastNode = nullptr;
        // 要改每条边，所以需要访问链表
        // 访问链表模板：
        // while (head != nullptr)  head = head->next;
        while (head != nullptr) {
            //因为要修改head->next，因此需要一个临时节点来存储head->next
            ListNode* temp = head->next;
            //修改head->next
            head->next = lastNode;
            //后移lastNode
            lastNode = head;
            head = temp;
        }
        return lastNode;
    }
};