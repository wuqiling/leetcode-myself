#include <iostream>
using std::pair;
using std::swap;
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
    ListNode* sortList(ListNode* head) { return sortList_1(head); }

   private:
    // merge sort - bottom - up
    // time O(NlgN) space O(1)
    // runtime 28ms 100%
    ListNode* sortList_1(ListNode* head) {
        if (!head || !head->next) return head;
        int len = 0;
        ListNode* rest = head;
        while (rest) len += 1, rest = rest->next;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *l, *r, *tail;
        for (int n = 1; n < len; n <<= 1) {
            rest = dummy.next;
            tail = &dummy;
            while (rest) {
                l = rest;
                r = split_1(l, n);
                rest = split_1(r, n);
                auto merged = merge_1(l, r);
                tail->next = merged.first;
                tail = merged.second;  // move to next tail
            }
        }
        return dummy.next;
    }

    // split the list int to two parts,n+rest
    ListNode* split_1(ListNode* head, int n) {
        while (head && --n) head = head->next;
        ListNode* rest = head ? head->next : NULL;
        if (head) head->next = NULL;  // split
        return rest;
    }

    // merge two list return the head and tail of the merged list
    pair<ListNode*, ListNode*> merge_1(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) swap(l1, l2);
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        cur->next = l1 ? l1 : l2;
        while (cur->next) cur = cur->next;
        return {dummy.next, cur};
    }

   private:
    // merge sort - top - bottom
    // time O(NlgN) space O(N)
    ListNode* sortList_2(ListNode* head) {
        if (!head || !head->next) return head;
        // split
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* r = slow->next;
        slow->next = NULL;
        return merge_2(sortList_2(head), sortList_2(r));
    }
    // merge time O(N) space O(1)
    ListNode* merge_2(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) swap(l1, l2);
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

int main() {
    ListNode l[] = {2, 1, 4, 5};
    for (int i = 0; i < sizeof(l) / sizeof(l[0]) - 1; i++)
        l[i].next = &l[i + 1];

    Solution1 s;
    ListNode* ans = s.sortList(l);
    return 0;
}