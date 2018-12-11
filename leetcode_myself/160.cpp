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
    // 16ms 99%
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		return getIntersectionNode_2(headA, headB);
	}

   private:
    // time O(N) space O(1)
    // 16ms 99%
    ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *rheadA = reverseList(headA);

        ListNode *p = headB;
        while (p) {
            if (p == headA) break;
            if (p->next == NULL) {
                reverseList(rheadA);
                return NULL;
            }
            p = p->next;
        }

        headA->next = headB;

        ListNode dumy(INT_MAX);
        dumy.next = rheadA;
        ListNode *fast = &dumy, *slow = &dumy;
        do {
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);

        fast = &dumy;
        do {
            fast = fast->next;
            slow = slow->next;
        } while (fast != slow);

        headA->next = NULL;
        reverseList(rheadA);
        return fast;
    }

   private:
    ListNode *reverseList(ListNode *head) {
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

	// time O(N) space O(1)
	// 24ms 87%
    ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *a = headA, *b = headB;
        while (a != b) {
			a = a ? a->next : headB;
			b = b ? b->next : headA;
        }
        return a;
    }
};

int main() {
    ListNode l1[] = {1, 2};
    ListNode l2[] = {2};
    for (int i = 0; i < sizeof(l1) / sizeof(l1[0]) - 1; i++)
        l1[i].next = &l1[i + 1];
    for (int i = 0; i < sizeof(l2) / sizeof(l2[0]) - 1; i++)
        l2[i].next = &l2[i + 1];
    l2[0].next = &l1[1];

    Solution s;
    ListNode *ans = s.getIntersectionNode(l1, l2);
    return 0;
}