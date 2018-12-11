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
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		ListNode *n = node->next;
		node->next = node->next->next;
		delete node->next;
	}
};

int main() {
	ListNode l1[] = { { 1 },{ 2 },{ 4 },{ 5 } };
	for (int i = 0; i < sizeof(l1) / sizeof(l1[0]) - 1; i++)
		l1[i].next = &l1[i + 1];
	Solution s;
	s.deleteNode(&l1[1]);
	return 0;
}