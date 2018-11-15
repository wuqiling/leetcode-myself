# leetcode
leetcode code

## 使用 C/C++ 编程
---

|#|文件名|  解法笔记 | 复杂度 | 百分比
--|-----|-------|--------|--
|001|Two Sum
||001|暴力搜索,使用两次迭代|O(N^2)|10%
||001_hashmap |使用哈希表|时间:O(N),空间O(N) |70%
||001_binarySearch|先记住数组下标,后排序,后用二分查找|时间:O(NlgN)+O(N)  空间:O(N) | 99%
|002|Add Two Numbers|分别考虑4种情况,有4处if判断 ||100%
|003|Longest Substring Without Repeating Characters
||003|暴力搜索|O(N^2)| 51%
||003_hashmap|使用字符值建立哈希表| O(N^2)  |51%
||003_hashtable_twopointer|建立哈希表，并使用双指针求解,每个字符最多遍历2次| O(N) |100%
|004|Median of Two Sorted Arrays 004_BinarySearch|二分查找|O(log(min(m+n)))|99%
|005|Longest Palindromic Substring
||005|使用3层迭代,| O(N^3)| 23%
||005_dp|使用动态规划,使用一个二维数组标记回文,减少一层循环|O(N^2) |48%
|007|Reverse Integer|考察整数最值表示与转换| |98%
|008|String to Integer (atoi)|主要考察字符串处理|| 100%
|010|Regular Expression Matching|动态规划|时间:O(M*N) 空间:O(M *N)|72%
|011|Container With Most Water
||011|暴力解法|时间:O(N^2)| 40%
||011_twoPointer| 双指针解法| 时间:O(N) |100%
|019|Remove Nth Node From End of List| 双指针解法, 注意删除head 节点的情况|时间:O(N)|100%
|055|Jump Game|贪婪算法,从尾部向前求局部最优||100%
|062|Unique Paths|动态规范|时间:O(M*N) 空间:O(M *N)|100%
|069|Sqrt(x)|使用二分查找|时间:O(NlgN)| 98%
|091|Decode Ways
||091_RecursionWithMemorization|递归+内存共享|时间 O(N^2),空间O(N^2)|31%
||091_dp|动态规划|时间:O(N) 空间O(1)|100%
|105|Construct Binary Tree from Preorder and Inorder Traversal|递归方法 ||100%
|139|Word Break|动态规划|时间O(N^2) 空间O(N)|100%
|207|Course Schedule
||207_dfs|dfs 解法,二维 vector / map 采用邻接表存储图 |时间:O(Node+Edge) |99%
||207_bfs|bfs,使用 queue + vector 数据结构, 采用邻接表存储图|时间:O(Node+Edge) | 99%
|380|Insert Delete GetRandom O(1)|使用哈希表和数组 ||99%
|593|Valid Square|较直接的判断方式,第一时间不一定能想到|| 100%

