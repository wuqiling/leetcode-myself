# leetcode

leetcode code

## 使用 C/C++ 编程

---

|#|文件名|  解法笔记 | 复杂度 | 时间/百分比
--|-----|-------|--------|--
|001|Two Sum
||[001](./leetcode_myself/001.cpp)|暴力搜索,使用两次迭代|O(N^2)|10%
||[001_hashmap](./leetcode_myself/001_hashmap.cpp) |使用哈希表|time:O(N),space:O(N) |70%
||[001_binarySearch](./leetcode_myself/001_binarySearch.cpp)|先记住数组下标,后排序,后用二分查找|time:O(NlgN)+O(N)  space:O(N) | 99%
|002|[Add Two Numbers](./leetcode_myself/002.cpp)|分别考虑4种情况,有4处if判断 ||100%
|003|Longest Substring Without Repeating Characters
||[003](./leetcode_myself/003.cpp)|暴力搜索|O(N^2)| 51%
||[003_hashmap](./leetcode_myself/003_hashmap.cpp)|使用字符值建立哈希表| O(N^2)  |51%
||[003_hashtable_twopointer](./leetcode_myself/003_hashtable_twopointer.cpp)|建立哈希表，并使用双指针求解,每个字符最多遍历2次| O(N) |100%
|004|[Median of Two Sorted Arrays 004_BinarySearch](./leetcode_myself/004_BinarySearch.cpp)|二分查找|O(log(min(m+n)))|99%
|005|Longest Palindromic Substring
||[005](./leetcode_myself/005.cpp)|使用3层迭代,| O(N^3)| 23%
||[005_dp](./leetcode_myself/005_dp.cpp)|使用动态规划,使用一个二维数组标记回文,减少一层循环|O(N^2) |48%
|007|[Reverse Integer](./leetcode_myself/007.cpp)|考察整数最值表示与转换| |98%
|008|[String to Integer (atoi)](./leetcode_myself/008.cpp) |主要考察字符串处理|| 100%
|010|[Regular Expression Matching](./leetcode_myself/010_dp.cpp)|动态规划|time:O(M*N) space:O(M *N)|72%
|011|Container With Most Water
||[011](./leetcode_myself/011.cpp)|暴力解法|time:O(N^2)| 40%
||[011_twoPointer](./leetcode_myself/011_twoPointer.cpp)| 双指针解法| time:O(N) |100%
|015|[3Sum](./leetcode_myself/015.cpp)|双指针|time:O(N^2) space:O(N)|91%
|019|[Remove Nth Node From End of List](./leetcode_myself/019.cpp)| 双指针解法, 注意删除head 节点的情况|time:O(N)|100%
|055|[Jump Game](./leetcode_myself/055.cpp)|贪婪算法,从尾部向前求局部最优|time:O(N)|100%
|062|[Unique Paths](./leetcode_myself/062_dp.cpp)|动态规范|time:O(M*N) space:O(M *N)|100%
|069|[Sqrt(x)](./leetcode_myself/069.cpp)|使用二分查找|time:O(NlgN)| 98%
|091|Decode Ways
||[091_RecursionWithMemorization](./leetcode_myself/091_RecursionWithMemorization.cpp)|递归+内存共享|time O(N^2),空间O(N^2)|31%
||[091_dp](./leetcode_myself/091_dp.cpp)|动态规划|time:O(N) 空间O(1)|100%
|105|[Construct Binary Tree from Preorder and Inorder Traversal](./leetcode_myself/105.cpp)|递归方法 ||100%
|139|[Word Break](./leetcode_myself/139.cpp)|动态规划|时间O(N^2) 空间O(N)|100%
|152|[Maximum Product Subarray](./leetcode_myself/152.cpp)|动态规划 |time:O(N) space:O(1)|100%
|207|Course Schedule
||[207_dfs](./leetcode_myself/207_dfs.cpp)|dfs 解法,二维 vector / map 采用邻接表存储图 |time:O(Node+Edge) |99%
||[207_bfs](./leetcode_myself/207_bfs.cpp)|bfs,使用 queue + vector 数据结构, 采用邻接表存储图|time:O(Node+Edge) | 99%
|279|[Perfect Squares](./leetcode_myself/279.cpp)| 动态规划|time: O(N^2) space:O(N)|73%
|300|Longest Increasing Subsequence
||[300](./leetcode_myself/300.cpp)|动态规划|time:O(N^2) space:O(N) |16ms 55%
||[300](./leetcode_myself/300.cpp)|dp+binary search|time:O(NlogN) space:O(N) |~0ms 100%
|322|[Coin Change](./leetcode_myself/322.cpp)|方法一:dp 方法二:dfs greedy|time:O(size_array*amount) space:O(amount)|4ms 99%
|380|[Insert Delete GetRandom O(1)](./leetcode_myself/380.cpp)|使用哈希映射和数组 ||99%
|593|[Valid Square](./leetcode_myself/593.cpp)|较直接的判断方式|| 100%


