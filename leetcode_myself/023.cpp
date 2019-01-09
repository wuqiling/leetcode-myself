#include <iostream>
#include <queue>
#include <vector>

using std::deque;
using std::swap;
using std::vector;
using std::priority_queue;

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
	   ListNode *mergeKLists(vector<ListNode *> &lists) {
		   return mergeKLists_1(lists);
	   }

private:
    // time O(lgM*N) space O(M)  M:number of lists N:avg of lists length
    // runtime 24ms 58%
    ListNode *mergeKLists_1(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        deque<ListNode *> res(lists.begin(), lists.end());
        while (res.size() > 1) {
            ListNode *l1 = res.front(); res.pop_front();
            ListNode *l2 = res.front(); res.pop_front();
            res.push_back(merge(l1, l2));
        }
        return res.front();
    }

	// time O(lgM*N) space O(M)
	//not use queue
	//runtime 20ms 70%
	ListNode *mergeKLists_2(vector<ListNode *> &lists) {
		if (!lists.size()) return NULL;
		return mergeSort(lists, 0, lists.size()-1);
	}
	//devide
	ListNode*mergeSort(vector<ListNode *> &lists, int lo, int hi) {
		if (lo >= hi) return lists[lo];
		int m = lo + (hi - lo) / 2;
		ListNode *l1 = mergeSort(lists, lo, m);
		ListNode *l2 = mergeSort(lists, m + 1, hi);
		return merge(l1, l2);
	}
private:
	// time O(N) space O(1)
	ListNode *merge(ListNode *l1, ListNode *l2) {
		ListNode dummy(0);
		ListNode *cur = &dummy;
		while (l1 && l2) {
			if (l1->val > l2->val) swap(l1, l2);
			cur->next = l1;
			cur = cur->next;
			l1 = l1->next;
		}
		cur->next = l1 ? l1 : l2;
		return dummy.next;
	}

private:
    // time O(lgM*N) space O(M)  heap(priority_queue)
    // runtime 16ms 99%
    ListNode *mergeKLists_3(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        priority_queue<ListNode *, vector<ListNode *>, compare> heap;
        for (const auto &p : lists)
            if (p) heap.push(p);
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (!heap.empty()) {
            cur->next = heap.top();
            cur = cur->next;
            heap.pop();
            if (cur->next) heap.push(cur->next);  // lgM
        }
        return dummy.next;
    }
    struct compare {
        bool operator()(const ListNode *l, const ListNode *r) {
            return l->val > r->val;  // if return ture : swap
        }
    };
};

int main() {
    vector<ListNode> l1{1, 2, 4, 5};
    for (int i = 0; i < l1.size() - 1; i++) l1[i].next = &l1[i + 1];
    vector<ListNode> l2{1, 3, 4, 5};
    for (int i = 0; i < l2.size() - 1; i++) l2[i].next = &l2[i + 1];
    vector<ListNode *> l{&l1[0], &l2[0]};

    Solution s;
    ListNode *ans = s.mergeKLists(l);
    return 0;
}