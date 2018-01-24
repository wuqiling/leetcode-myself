#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*分别考虑4种情况，有多处if判断。此方法效率极好，战胜100% 提交者！！！*/

struct ListNode {
	int val;
	struct ListNode *next;
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
	struct ListNode *rootNode, *currentNode, *newNode;
	int tmp = 0;	//used for calculate numa and numb

	/**
	* check if l1==NULL or l2==NULL
	*/
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	}
	else if (l1 == NULL) {
		return l2;
	}
	else if (l2 == NULL) {
		return l1;
	}

	/**
	* calc l1+l2
	*/
	currentNode = rootNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (rootNode == NULL) {
		return NULL;
	}
	while (1) {
		if (l1 != NULL && l2 != NULL) {
			newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
			if (newNode == NULL)
				return NULL;
			tmp = tmp + l1->val + l2->val;

			/**
			* link root Node
			*/
			newNode->val = tmp % 10;
			newNode->next = NULL;
			currentNode->next = newNode;
			currentNode = newNode;
			/**
			* link l1 and l2
			*/
			l1 = l1->next;
			l2 = l2->next;
			tmp = tmp > 9 ? 1 : 0;
		}
		if (l1 == NULL && l2 != NULL) {
			if (tmp == 0) {
				currentNode->next = l2;
				break;
			}
			newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
			if (newNode == NULL)
				return NULL;
			tmp = tmp + l2->val;
			newNode->val = tmp % 10;
			newNode->next = NULL;
			currentNode->next = newNode;
			currentNode = newNode;
			l2 = l2->next;
			tmp = tmp > 9 ? 1 : 0;
		}
		if (l1 != NULL && l2 == NULL) {
			if (tmp == 0) {
				currentNode->next = l1;
				break;
			}
			newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
			if (newNode == NULL)
				return NULL;
			tmp = tmp + l1->val;
			newNode->val = tmp % 10;
			newNode->next = NULL;
			currentNode->next = newNode;
			currentNode = newNode;
			l1 = l1->next;
			tmp = tmp > 9 ? 1 : 0;
		}
		if (l1 == NULL && l2 == NULL) {
			if (tmp == 0) {
				break;
			}
			newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
			if (newNode == NULL)
				return NULL;
			newNode->val = tmp;
			newNode->next = NULL;
			currentNode->next = newNode;
			currentNode = newNode;
			break;
		}
	}
	return rootNode->next;
}