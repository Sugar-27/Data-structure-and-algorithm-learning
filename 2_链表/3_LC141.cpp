/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//快慢指针，利用快指针套圈来检查是否有环，空间O(１)
class Solution {
   public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

//使用哈希表记录访问路径，访问过说明有环
class Solution {
   public:
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> mp;
        while (head != nullptr) {
            if (mp.find(head) != mp.end()) {
                return true;
            }
            mp[head]++;
            head = head->next;
        }
        return false;
    }
};