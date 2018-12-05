#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;



class Solution {
public:
	//binary search
	//O(lg(max-min)*N*lgN)
	// runtime 32ms 57%
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int N = matrix.size();
		if (N == 0) return 0;
		int l = matrix[0][0], r = matrix[N - 1][N - 1];
		while (l < r) {
			int m = l + (r - l) / 2, cnt = 0;
			for (int i = 0; i < N; i++) {
				//binary search
				auto it = upper_bound(matrix[i].begin(), matrix[i].end(), m);
				cnt += it - matrix[i].begin();
			}
			if (cnt < k) l = m + 1;
			else r = m;
		}
		return l;
	}
};