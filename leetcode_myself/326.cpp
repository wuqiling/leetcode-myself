#include <iostream>
#include <algorithm>

class Solution {
public:
	/*
	pow(3,19) is the max int which is less than INT_MAX.
	3^m % n == 0 which can be described by 3^m == n * k (exists such a number of k)

	3 is a prime, which means that 3^m can be factored 3 * 3 * 3 *... * 3 (count of m), so n should be and can only be 3 * 3 * 3*...*3, which means that n is a pow of 3.

	if we want to find a pow of 4, we can not use this method because 4 is not a prime.
	4^m can be factored 2* 2 * 2 * ... * 2 (count of 2m), so n can be any one of 2*2*2*..*2(any count is ok).
	*/
	// Runtime: 76 ms, faster than 51.68%
	bool isPowerOfThree(int n) {
		return (n > 0) && ((int)(pow(3, 19)) % n == 0);
	}
};