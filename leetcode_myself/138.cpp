#include <iostream>
#include <unordered_map>
using std::unordered_map;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
   public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return copyRandomList_2(head);
    }

   private:
    // time O(N) space O(1)
    // runtime 44ms 39%
    RandomListNode *copyRandomList_1(RandomListNode *head) {
        if (!head) return NULL;
        // step 1
        // copy new node and insert
        RandomListNode *p = head, *q = NULL;
        while (p) {
            q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;  // insert node to old list
            p = q->next;
        }

        // step 2
        // copy random node
        p = head;
        while (p) {
            if (p->random) p->next->random = p->random->next;
            p = p->next->next;
        }

        // step 3
        // split list
        RandomListNode dummy(0);
        dummy.next = head->next;
        p = head, q = head->next;
        while (p) {
            p->next = q->next;
            p = p->next;
            if (p) {
                q->next = p->next;
                q = p->next;
            } else
                q->next = NULL;
        }
        return dummy.next;
    }

   private:
    // time O(N) space O(N)
    // runtime 36ms 52%
    RandomListNode *copyRandomList_2(RandomListNode *head) {
        if (!head) return NULL;
        unordered_map<RandomListNode *, RandomListNode *> h;//key=old node val=new node
        RandomListNode dummy(0);
        for (RandomListNode *l = head, *cur = &dummy; l; l = l->next) {
            if (!h.count(l)) h[l] = new RandomListNode(l->label);
            if (l->random) {
                if (!h.count(l->random))
                    h[l->random] = new RandomListNode(l->random->label);
                h[l]->random = h[l->random];
            }
            cur->next = h[l];
            cur = cur->next;
        }
        return dummy.next;
    }
};

int main() {
    RandomListNode l[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(l) / sizeof(l[0]) - 1; i++)
        l[i].next = &l[i + 1];
    l[0].random = &l[1];
    l[2].random = &l[3];

    Solution s;
    RandomListNode *ans = s.copyRandomList(l);
    return 0;
}