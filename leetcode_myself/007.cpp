#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int reverse(int x) {
    if (x <= (int)0x80000000 || x >= (int)0x7fffffff) return 0;
    if (x / 10 == 0) return x;
    int x_tmp = 0;
    int isNeg;
    if (x < 0) {
        x *= -1;
        isNeg = 1;
    } else {
        isNeg = 0;
    }
    while (x != 0) {
        x_tmp = x_tmp * 10 + x % 10;
        if (x_tmp > (int)0x7fffffff) return 0;
        x = x / 10;
    }
    return isNeg ? -1 * x_tmp : x_tmp;
}

int main() {
    int a = 123;
    cout << reverse(a);
    a = 0x80000000;
    cout << a << endl;
    return 0;
}