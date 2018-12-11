#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    // 8ms 33%
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p = head, *q = head->next, *r = NULL;
        p->next = r;
        while (q) {
            r = p;
            p = q;
            q = q->next;
            p->next = r;
        }
        return p;
    }
};

int main() {
    ListNode l1[] = {{1}, {2}, {4}, {5}};
    for (int i = 0; i < sizeof(l1) / sizeof(l1[0]) - 1; i++)
        l1[i].next = &l1[i + 1];
    Solution s;
    ListNode* ans = s.reverseList(&l1[0]);
    return 0;
}