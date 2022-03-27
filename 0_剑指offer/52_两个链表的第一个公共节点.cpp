// 两个指针分别遍历A和B
// 先遍历完的去遍历另外一个链，这样本质上就是让两个指针把两条链走一遍，结束的条件是两个指针指的节点相同
// 不论怎么结束，他们走过的距离都是相等的
// 如果没有公共节点，则两个指针最后都指向nullptr
// 如果有公共节点，则两个指针指向那个公共节点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA, * b = headB;
        while (a != b) {
            a = a == nullptr ? headB : a->next;
            b = b == nullptr ? headA : b->next;
        }
        return a;
    }
};