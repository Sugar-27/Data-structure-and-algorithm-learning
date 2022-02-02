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
    ListNode* sortList(ListNode* head) {
        ListNode* protect = new ListNode(-1, head);

        // 计数，查看有多少个节点
        int n = 0;
        ListNode* cnt = head;
        while (cnt) {
            cnt = cnt->next;
            ++n;
        }

        // 开始分割子链表，从长度为1开始，逐次翻倍，直到len长度为总长度
        ListNode *l, *mid, *r;
        for (int len = 1; len < n; len <<= 1) {
            l = protect;
            // 每一次合并需要将它与之前的连接到一起，所以要保存一下pre节点
            // 每一次合并的区间为[l, mid), [mid, r)
            // 每一层循环的任务为找到l, mid, r
            // 同时保证r < n;
            int i;
            for (i = 0; i + 2 * len < n; i += 2 * len) {
                mid = l->next;
                for (int j = 0; j < len; ++j)
                    mid = mid->next;  // 实际上mid下一个才是mid
                r = mid;
                for (int j = 0; j < len; ++j)
                    r = r->next;  // r下一个才是r
                l = merge(l, l->next, mid, r);
            }
            if (n - i > len) {
                mid = l->next;
                for (int j = 0; j < len; ++j)
                    mid = mid->next;
                r = mid;
                for (int j = 0; j < n - i - len; ++j)
                    r = r->next;  // 不同之处，最后一组的数量达不到len的要求
                l = merge(l, l->next, mid, r);
            }
        }
        return protect->next;
    }

   private:
    ListNode* merge(ListNode* protect,
                    ListNode* l,
                    ListNode* mid,
                    ListNode* r) {
        // 合并两个有序链表[l, mid), [mid,
        // r)，然后返回r前一个作为下一次合并的保护节点
        ListNode *ptr1 = l, *ptr2 = mid;
        ListNode* pre = protect;
        while (ptr1 != mid && ptr2 != r) {
            if (ptr1->val < ptr2->val) {
                pre->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                pre->next = ptr2;
                ptr2 = ptr2->next;
            }
            pre = pre->next;
        }
        if (ptr1 != mid) {
            pre->next = ptr1;
            while (ptr1->next != mid)
                ptr1 = ptr1->next;
            ptr1->next = r;
            return ptr1;
        } else {
            pre->next = ptr2;
            while (ptr2->next != r)
                ptr2 = ptr2->next;
            return ptr2;
        }
    }
};