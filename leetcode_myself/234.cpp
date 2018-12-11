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
    // runtime 8ms 99%
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
		
        ListNode* rhead = reverseList(slow);

        ListNode *p = head, *q = rhead;
        while (q && p) {
            if (p->val != q->val) {
                reverseList(rhead);
                return false;
            }
            q = q->next;
            p = p->next;
        }
        reverseList(rhead);
        return true;
    }

   private:
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
    ListNode l[] = {1, 2, 3, 3, 2, 1};
    for (int i = 0; i < sizeof(l) / sizeof(l[0]) - 1; i++)
        l[i].next = &l[i + 1];

    Solution s;
    s.isPalindrome(l);
    return 0;
}