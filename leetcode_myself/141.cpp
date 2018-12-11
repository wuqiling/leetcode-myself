#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
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
    // time O(N) space O(1)
    // 4ms 100%
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *pslow = head, *pfast = head;
        do {
            pslow = pslow->next;
            if (pfast->next && pfast->next->next)
                pfast = pfast->next->next;
            else
                return false;
        } while (pslow != pfast);
        return true;
    }
};