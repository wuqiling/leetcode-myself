#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

//////////////////////////////////////////////////////////////////////////

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL && l2 == NULL) return NULL;

    struct ListNode rootNode, *cur, *p;
    int tmp = 0;  // used for calculate numa and numb

    cur = &rootNode;
    while (1) {
        if (l1 != NULL && l2 != NULL) {
            p = (struct ListNode*)malloc(sizeof(struct ListNode));
            if (p == NULL) return NULL;
            tmp = tmp + l1->val + l2->val;
            p->val = tmp % 10;
            p->next = NULL;
            cur->next = p;
            cur = p;
            l1 = l1->next;
            l2 = l2->next;
            tmp = tmp > 9 ? 1 : 0;
        } else if (l1 == NULL && l2 != NULL) {
            p = (struct ListNode*)malloc(sizeof(struct ListNode));
            if (p == NULL) return NULL;
            tmp = tmp + l2->val;
            p->val = tmp % 10;
            p->next = NULL;
            cur->next = p;
            cur = p;
            l2 = l2->next;
            tmp = tmp > 9 ? 1 : 0;
        } else if (l1 != NULL && l2 == NULL) {
            p = (struct ListNode*)malloc(sizeof(struct ListNode));
            if (p == NULL) return NULL;
            tmp = tmp + l1->val;
            p->val = tmp % 10;
            p->next = NULL;
            cur->next = p;
            cur = p;
            l1 = l1->next;
            tmp = tmp > 9 ? 1 : 0;
        } else {  //(l1 == NULL && l2 == NULL)
            if (tmp == 0) break;

            p = (struct ListNode*)malloc(sizeof(struct ListNode));
            if (p == NULL) return NULL;
            p->val = tmp;
            p->next = NULL;
            cur->next = p;
            cur = p;
            break;
        }
    }
    return rootNode.next;
}