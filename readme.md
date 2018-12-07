# leetcode

leetcode code

## 使用 C/C++ 编程

---

|#|Title|  Notes | Complexity | Run time
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
|013|[Roman to Integer](./leetcode_myself/013.cpp)|注意题目意思|time O(N) space O(1)|20ms 100%
|014|[Longest Common Prefix](./leetcode_myself/014.cpp)|基础 string|time O(N*M) space O(1)| ~0 100%
|015|[3Sum](./leetcode_myself/015.cpp)|双指针|time:O(N^2) space:O(N)|91%
|017|[Letter Combinations of a Phone Number](./leetcode_myself/017.cpp)| dfs ||~0 100%
|019|[Remove Nth Node From End of List](./leetcode_myself/019.cpp)| 双指针解法, 注意删除head 节点的情况|time:O(N)|100%
|020|[Valid Parentheses](./leetcode_myself/020.cpp)| stack |time O(N) space O(N)|~0 100%
|022|[Generate Parentheses](./leetcode_myself/022.cpp)| dfs ||~0 100%
|028|Implement strStr()
||[028](./leetcode_myself/028.cpp)| brute force |time O(N*M) space O(1)|4ms 98%
||[028](./leetcode_myself/028.cpp)| KMP |time O(N+M) space O(M)|~0 100%
||[028](./leetcode_myself/028.cpp)| BM 比 kmp 快|time O(N)~worst O(N*M) space O(1)|~0 100%
||[028](./leetcode_myself/028.cpp)| Sunday 比 BM 快|time O(N)~worst O(M*N) space O(1)|~0 100%
|029|[Divide Two Integers](./leetcode_myself/029.cpp)|注意累加方式, 防止溢出| time:O(log(N)) space:O(1)|12ms 98%
|033|[Search in Rotated Sorted Array](./leetcode_myself/033.cpp)|注意边界条件|time:O(log(N)) space:O(1)|4ms 98%
|034|[Find First and Last Position of Element in Sorted Array](./leetcode_myself/034.cpp)|二分法一种变形使用|time:O(log(N)) space:O(1)|8ms 63%
|038|[Count and Say](./leetcode_myself/038.cpp)| string |time O(N) space O(N)|~0 100%
|049|[Group Anagrams](./leetcode_myself/049.cpp)| string hashtable stl|time N*M*lgM space N*M|16ms 99%
|055|[Jump Game](./leetcode_myself/055.cpp)|贪婪算法,从尾部向前求局部最优|time:O(N)|100%
|062|[Unique Paths](./leetcode_myself/062_dp.cpp)|动态规范|time:O(M*N) space:O(M *N)|100%
|069|[Sqrt(x)](./leetcode_myself/069.cpp)|使用二分查找|time:O(NlgN)| 98%
|091|Decode Ways
||[091_RecursionWithMemorization](./leetcode_myself/091_RecursionWithMemorization.cpp)|递归+内存共享|time O(N^2),space:O(N^2)|31%
||[091_dp](./leetcode_myself/091_dp.cpp)|动态规划|time:O(N) space:O(1)|100%
|105|[Construct Binary Tree from Preorder and Inorder Traversal](./leetcode_myself/105.cpp)|递归方法 ||100%
|125|[Valid Palindrome](./leetcode_myself/125.cpp)|string stl |time O(N) space O(N)|8ms 61%
|139|[Word Break](./leetcode_myself/139.cpp)|动态规划|time:O(N^2) space:O(N)|100%
|152|[Maximum Product Subarray](./leetcode_myself/152.cpp)|动态规划 |time:O(N) space:O(1)|100%
|162|[Find Peak Element](./leetcode_myself/162.cpp)|二分查找|time:O(logN) space:O(1)|4ms 99%
|207|Course Schedule
||[207_dfs](./leetcode_myself/207_dfs.cpp)|dfs 解法,二维 vector / map 采用邻接表存储图 |time:O(Node+Edge) |99%
||[207_bfs](./leetcode_myself/207_bfs.cpp)|bfs,使用 queue + vector 数据结构, 采用邻接表存储图|time:O(Node+Edge) | 99%
|230|[Kth Smallest Element in a BST](./leetcode_myself/230.cpp)|中序遍历+stack|time:O(N) space:O(N)| 8ms 99%
|227|[Basic Calculator II](./leetcode_myself/227.cpp)| stack |time O(N) space O(N)|4ms 100%
|240|Search a 2D Matrix II
||[240](./leetcode_myself/240.cpp)|brute force|time:O(N*M) space:O(1)| 964ms 1.4%
||[240](./leetcode_myself/240.cpp)|divide and conquer+ recursion|time:O(n^1.58)| 1284ms 0.3%
||[240](./leetcode_myself/240.cpp)| Smart alg|time O(M+N) space O(1)| 36ms 98%
|279|[Perfect Squares](./leetcode_myself/279.cpp)| 动态规划|time: O(N^2) space:O(N)|73%
|287|Find the Duplicate Number
||[287](./leetcode_myself/287.cpp)|brute force|time O(N^2) sapce O(1)| 452ms  3.2%
||[287](./leetcode_myself/287.cpp)|binary search|time O(NlgN) space O(1)| 12ms 35%
||[287](./leetcode_myself/287.cpp)|Floyd alg|time O(N) space O(1)| 4ms 100%
|300|Longest Increasing Subsequence
||[300](./leetcode_myself/300.cpp)|动态规划|time:O(N^2) space:O(N) |16ms 55%
||[300](./leetcode_myself/300.cpp)|dp+binary search|time:O(NlogN) space:O(N) |~0ms 100%
|322|[Coin Change](./leetcode_myself/322.cpp)|方法一:dp 方法二:dfs greedy|time:O(size_array*amount) space:O(amount)|4ms 99%
|344|[Reverse String](./leetcode_myself/344.cpp)|使用stl|time O(N) space O(N)|4ms 100%
|349|[Intersection of Two Arrays](./leetcode_myself/349.cpp)| 使用std::set|time:O(M+N) space:O(M+N)|4ms 100%
|350|Intersection of Two Arrays II
||[350](./leetcode_myself/350.cpp)|使用排序+双子针 | time: O(max(NlgN,MlgM)) space:O(max(N,M))|8ms 36%
||[350](./leetcode_myself/350.cpp)|使用 map | time:O(N+M) space:O(max(N,M))|4ms 100%
|378|[Kth Smallest Element in a Sorted Matrix](./leetcode_myself/378.cpp)|binary search|time O(lg(max-min)*N*lgN) space O(1)| 32ms 57%
|380|[Insert Delete GetRandom O(1)](./leetcode_myself/380.cpp)|使用哈希映射和数组 ||99%
|387|[First Unique Character in a String](./leetcode_myself/387.cpp)|使用哈希映射 |time O(N) space O(1)|24ms 98%
|454|[4Sum II](./leetcode_myself/454.cpp)|hashmap|time O(N^2) space O(N^2)|100 ms 94.50%
|593|[Valid Square](./leetcode_myself/593.cpp)|较直接的判断方式|| 100%


