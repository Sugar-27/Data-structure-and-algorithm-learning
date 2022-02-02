// 简单做法，双指针，时间复杂度O(n)，空间复杂度O(n)
class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        int n = nums.size() - 1;
        for (int i = 0; i <= n; ++i) {
            if (i >= n - i)
                break;
            if (nums[i] != nums[n - i])
                return false;
        }
        return true;
    }
};

// 设计列表翻转与快慢指针，时间复杂度O(n)，空间复杂度O(1)
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
    bool isPalindrome(ListNode* head) {
        // 将链表一分为二，然后将后一组的链表进行翻转
        ListNode* firstEnd = getEnd(head);
        ListNode* secondStart = reverseList(firstEnd->next);

        bool result = true;
        ListNode *ptr1 = head, *ptr2 = secondStart;
        while (result && ptr2) {
            if (ptr1->val != ptr2->val)
                result = false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // 对链表进行复原，不复原不影响结果
        firstEnd->next = reverseList(secondStart);

        return result;
    }

   private:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            ListNode* temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
    ListNode* getEnd(ListNode* head) {
        // 快慢指针法，初始值设为相同的head，这样子会使得第一组的链表长度 >=
        // 第二组的链表长度
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};