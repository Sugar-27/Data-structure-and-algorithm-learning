/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 自己做的方法一，算法时间复杂度O(n),空间复杂度O(2n)
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> pre;
        while (head != nullptr) {
            pre.push_back(head->val);
            head = head->next;
        }
        vector<int> ans(pre.size(), 0);
        int index = 0;
        for (int i = pre.size() - 1; i >= 0; --i) {
            ans[index++] = pre[i];
        }
        return ans;
    }
};

// 题解，用栈来做，算法时间复杂度O(n),空间复杂度O(2n)
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> save;
        while (head != nullptr) {
            save.push(head->val);
            head = head->next;
        }
        vector<int> ans;
        while (!save.empty()) {
            ans.push_back(save.top());
            save.pop();
        }
        return ans;
    }
};

// 优秀题解，递归
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if (head == nullptr) {
            return {};
        }
        vector<int> ans = reversePrint(head->next);
        ans.push_back(head->val);
        return ans;
    }
};
