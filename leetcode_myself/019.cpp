#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    assert(head != NULL && n >= 0);
    struct ListNode *first = head;
    for (int i = 1; i < n; i++) {
        if (first != NULL)
            first = first->next;
        else
            return head;  // invalid input
    }

    // case:delete the head
    if (first->next == NULL) {
        if (head->next == NULL) {
            free(head);
            return NULL;
        } else {
            struct ListNode *next = head->next;
            free(head);
            return next;
        }
    }

    //....->p->q(to delete)->....->first->NULL
    struct ListNode *p = head;
    struct ListNode *q = head->next;
    first = first->next;  // sync to q
    while (first->next != NULL) {
        first = first->next;
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

int main() {
    // make list
    struct ListNode *head = NULL, *p = NULL;
    for (int i = 1; i < 4; i++) {
        struct ListNode *tmp =
            (struct ListNode *)malloc(sizeof(struct ListNode));
        assert(tmp != NULL);
        tmp->val = i;
        tmp->next = NULL;
        if (i == 1)
            head = p = tmp;
        else {
            p->next = tmp;
            p = tmp;
        }
    }

    head = removeNthFromEnd(head, 3);
    // delete list
    p = head;
    while (p != NULL) {
        struct ListNode *tmp = p->next;
        free(p);
        p = tmp;
    }
    return 0;
}