#include <iostream>
using std::cout;
using std::endl;

int mySqrt(int x) {
    if (x == 0)
        return 0;
    else if (x == 1)
        return 1;
    long long i = 0;
    long long j = x / 2 + 1;
    while (i < j) {
        long long mid = (i + j) / 2;
        long long sq = mid * mid;
        if (sq < x)
            i = mid;
        else if (sq > x)
            j = mid;
        else
            return mid;
        if (i + 1 == j) return i;
    }
    return j;
}

int main() {
    int b = 4;
    int a = mySqrt(b);
    cout << a << endl;
    return 0;
}