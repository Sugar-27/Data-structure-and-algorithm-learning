// 分治
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

private:
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (a == nullptr || b == nullptr)   return a ? a : b;
        // ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        ListNode* aPtr = a, * bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val <= bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            } else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = aPtr ? aPtr : bPtr;
        return head->next;
    }
};

// 使用优先队列构建小根堆
// 堆结点（key用于比较的关键码，listNode可以是任意的附带信息）
struct Node {
    int key;
    ListNode* listNode;
    Node(int key, ListNode* listNode)  : key(key), listNode(listNode) {}
};

// priority_queue通过小于号比较的
bool operator <(const Node& a, const Node& b) {
    // return a.key < b.key; // 大根堆
    return a.key > b.key; // 小根堆（欺骗总是取出max的priority_queue）
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node> q;
        for (ListNode* listNode : lists) {
            if (listNode != nullptr)
                q.push(Node(listNode->val, listNode));
        }
        ListNode head;
        ListNode* tail = &head;
        while (!q.empty()) {
            // 取出k个指针指向的最小元素
            Node node = q.top();
            q.pop();
            // 在答案链表的末尾插入
            tail->next = node.listNode;
            tail = tail->next;
            // 当最小被取出后，指针向后移动一位，可能需要插入新的元素
            ListNode* p = node.listNode->next;
            if (p != nullptr) {
                q.push(Node(p->val, p));
            }
        }
        return head.next;
    }
};

