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
    // time O(N)
    // runtime 4ms 100%
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode res(0);
        ListNode* pres = &res;
        while (l1 || l2) {
            ListNode* newList = new ListNode(0);
            if ((l1 && l2 && l1->val < l2->val) || (l1 && !l2)) {
                newList->val = l1->val;
                l1 = l1->next;
            } else {
                newList->val = l2->val;
                l2 = l2->next;
            }
            pres->next = newList;
            pres = pres->next;
        }
        return res.next;
    }
};

int main() {
    ListNode l1[3] = {{1}, {2}, {4}};
    ListNode l2[3] = {{1}, {3}, {4}};
    l1[0].next = &l1[1];
    l1[1].next = &l1[2];
    l2[0].next = &l2[1];
    l2[1].next = &l2[2];

    Solution s;
    ListNode* ans = s.mergeTwoLists(&l1[0], &l2[0]);
    return 0;
}