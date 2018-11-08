#include <assert.h>
#include <iostream>
using std::cout;
using std::endl;

void printArr(const int *num, int len) {
    assert(num != NULL && len >= 0);
    for (int i = 0; i < len; i++) cout << i << " :" << num[i] << ", ";
    cout << ",len:" << len << endl;
}

bool canJump(const int *nums, int numsSize) {
    // printArr(nums, numsSize);
    if (nums == NULL || numsSize <= 0)
        return false;
    else if (numsSize == 1 || nums[0] >= numsSize - 1)
        return true;
    else if (numsSize == 2) {
        if (nums[0] > 0)
            return true;
        else
            return false;
    }
    for (int i = numsSize - 3; i >= 0; i--) {
        // cout << "i:" << i << " num i:" << nums[i] << " num i+1:" << nums[i +
        // 1] << " jump :" << numsSize - i - 2 << endl;
        if (nums[i] > nums[i + 1]) {
            continue;
        } else if (nums[i + 1] >= numsSize - i - 2) {
            return canJump(nums, i + 2);
        }
    }
    return false;
}

int main() {
    int arr[] = {0, 0, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    if (canJump(arr, len))
        cout << "\n T rue";
    else
        cout << "\n F alse";
    return 0;
}
