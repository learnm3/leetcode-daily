// LeetCode 206. 反转链表
// 思路：三指针 prev/cur/nxt 原地掉头，先存 nxt 再改 cur->next。O(n) 时间 / O(1) 空间
// 易错：先掉头再存 nxt 会断链；空链表/单节点直接返回
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* nxt = cur->next;   // ① 先保存下一个（防断链）
            cur->next = prev;            // ② 掉头
            prev = cur;                  // ③ prev 前进
            cur = nxt;                   // ④ cur 前进
        }
        return prev;                     // 原链表尾 = 新链表头
    }
};
