#include <iostream>
#include <vector>
using std::vector;
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
    // time O(N) space O(1)
    // runtime 8ms 100%
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* evenHead = head->next;
        ListNode *odd = head, *even = head->next;
        while (odd && even) {
            if (even->next) {
                odd->next = even->next;
                odd = odd->next;
            } else
                break;
            if (odd) {
                even->next = odd->next;
                even = even->next;
            } else
                even->next = NULL;
        }
        odd->next = evenHead;
        return head;
    }
};

int main() {
    vector<ListNode> l{1, 2, 3, 4, 5, 6};
    for (int i = 0; i < l.size() - 1; i++) l[i].next = &l[i + 1];

    Solution s;
    ListNode* ans = s.oddEvenList(&l[0]);
    return 0;
}