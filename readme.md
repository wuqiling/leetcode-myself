# leetcode

leetcode code

## 使用 C/C++ 编程

---

|#|Title|  Notes | Complexity | Run time
--|-----|-------|--------|--
|001|Two Sum
||[001](./leetcode_myself/001.cpp)|暴力搜索,使用两次迭代|O(N^2)|10%
||[001_hashmap](./leetcode_myself/001_hashmap.cpp) |使用哈希表|time:O(N),space:O(N) |70%
||[001_binarySearch](./leetcode_myself/001_binarySearch.cpp)|先记住数组下标,后排序,后用二分查找|time:O(NlogN)+O(N)  space:O(N) | 99%
|002|[Add Two Numbers](./leetcode_myself/002.cpp)|分别考虑4种情况,有4处if判断 ||100%
|003|Longest Substring Without Repeating Characters
||[003](./leetcode_myself/003.cpp)|暴力搜索|O(N^2)| 51%
||[003_hashmap](./leetcode_myself/003_hashmap.cpp)|使用字符值建立哈希表| O(N^2)  |51%
||[003_hashtable_twopointer](./leetcode_myself/003_hashtable_twopointer.cpp)|建立哈希表，并使用双指针求解,每个字符最多遍历2次| O(N) |100%
|004|[Median of Two Sorted Arrays 004_BinarySearch](./leetcode_myself/004_BinarySearch.cpp)|二分查找|O(log(min(m+n)))|99%
|005|Longest Palindromic Substring
||[005](./leetcode_myself/005.cpp)|使用3层迭代,| O(N^3)| 23%
||[005_dp](./leetcode_myself/005_dp.cpp)|使用动态规划,使用一个二维数组标记回文,减少一层循环|O(N^2) |48%
|006|[ZigZag Conversion](./leetcode_myself/006.cpp)||time O(N) space O(N)|  20 ms, 77.62%
|007|[Reverse Integer](./leetcode_myself/007.cpp)|考察整数最值表示与转换| |98%
|008|[String to Integer (atoi)](./leetcode_myself/008.cpp) |主要考察字符串处理|| 100%
|009|[Palindrome Number](./leetcode_myself/009.cpp)|math | time O(N) space O(1)|  244 ms, 10.78%
|009|[Palindrome Number](./leetcode_myself/009.cpp)|string | time O(N) space O(N)|  212ms 20%
|009|[Palindrome Number](./leetcode_myself/009.cpp)|stack | time O(N) space O(N)|  124 ms, 81.11%
|010|[Regular Expression Matching](./leetcode_myself/010.cpp)|动态规划|time:O(M*N) space:O(M *N)|72%
|011|Container With Most Water
||[011](./leetcode_myself/011.cpp)|暴力解法|time:O(N^2)| 40%
||[011_twoPointer](./leetcode_myself/011_twoPointer.cpp)| 双指针解法| time:O(N) |100%
|013|[Roman to Integer](./leetcode_myself/013.cpp)|注意题目意思|time O(N) space O(1)|20ms 100%
|014|[Longest Common Prefix](./leetcode_myself/014.cpp)|基础 string|time O(N*M) space O(1)| ~0 100%
|015|[3Sum](./leetcode_myself/015.cpp)|双指针|time:O(N^2) space:O(N)|91%
|017|[Letter Combinations of a Phone Number](./leetcode_myself/017.cpp)| dfs ||~0 100%
|019|[Remove Nth Node From End of List](./leetcode_myself/019.cpp)| 双指针解法, 注意删除head 节点的情况|time:O(N)|100%
|020|[Valid Parentheses](./leetcode_myself/020.cpp)| stack |time O(N) space O(N)|~0 100%
|021|[Merge Two Sorted Lists](./leetcode_myself/021.cpp)| list |time O(N) space O(N)|4ms 100%
|022|[Generate Parentheses](./leetcode_myself/022.cpp)| dfs ||~0 100%
|023|[Merge k Sorted Lists](./leetcode_myself/023.cpp)| queue | time O(logM*N) space O(M)  M:number of lists N:avg of lists length|  24ms 58%
|023|[Merge k Sorted Lists](./leetcode_myself/023.cpp)| not use queue |time O(logM*N) space O(M)|  20ms 70%
|023|[Merge k Sorted Lists](./leetcode_myself/023.cpp)| heap | time O(N) space O(1)|  16ms 99%
|026|[Remove Duplicates from Sorted Array](./leetcode_myself/026.cpp)| | time O(N) space O(1)|  16ms 99%
|028|Implement strStr()
||[028](./leetcode_myself/028.cpp)| brute force |time O(N*M) space O(1)|4ms 98%
||[028](./leetcode_myself/028.cpp)| KMP |time O(N+M) space O(M)|~0 100%
||[028](./leetcode_myself/028.cpp)| BM 比 kmp 快|time O(N)~worst O(N*M) space O(1)|~0 100%
||[028](./leetcode_myself/028.cpp)| Sunday 比 BM 快|time O(N)~worst O(M*N) space O(1)|~0 100%
|029|[Divide Two Integers](./leetcode_myself/029.cpp)|注意累加方式, 防止溢出| time:O(log(N)) space:O(1)|12ms 98%
|033|[Search in Rotated Sorted Array](./leetcode_myself/033.cpp)|注意边界条件|time:O(log(N)) space:O(1)|4ms 98%
|034|[Find First and Last Position of Element in Sorted Array](./leetcode_myself/034.cpp)|二分法一种变形使用|time:O(log(N)) space:O(1)|8ms 63%
|036|[Valid Sudoku](./leetcode_myself/036.cpp)| hash table |time O(1) space O(1)|12ms 97%
|038|[Count and Say](./leetcode_myself/038.cpp)| string |time O(N) space O(N)|~0 100%
|041|[First Missing Positive](./leetcode_myself/041.cpp)| math | time O(N) space O(1)|4ms 86%
|042|[Trapping Rain Water](./leetcode_myself/042.cpp)| greedy |time O(N) space O(1)|8ms 72%
|044|[Wildcard Matching](./leetcode_myself/044.cpp)| dp |time O(M*N) space O(M *N)|16ms 99%
|046|[Permutations](./leetcode_myself/046.cpp)| dfs |time O(N!) space O(N)|8ms 99%
|048|[Rotate Image](./leetcode_myself/048.cpp)| math | time O(N^2) space O(1)|4ms 72%
|049|[Group Anagrams](./leetcode_myself/049.cpp)| string hashtable stl|time N*M*logM space N*M|16ms 99%
|053|[Maximum Subarray](./leetcode_myself/053.cpp)|dp|time O(N) space O(1)|4ms,100%
|054|[Spiral Matrix](./leetcode_myself/054.cpp)|math|time O(M*N) space O(1)|~0ms,100%
|055|[Jump Game](./leetcode_myself/055.cpp)|贪婪算法,从尾部向前求局部最优|time:O(N)|100%
|056|[Merge Intervals](./leetcode_myself/056.cpp)|greedy|time O(NlgN) space O(1)|8ms 99%
|062|[Unique Paths](./leetcode_myself/062_dp.cpp)|动态规范|time:O(M*N) space:O(M *N)|100%
|066|[Plus One](./leetcode_myself/066.cpp)|math|time O(N) space O(N)|4ms 36%
|069|[Sqrt(x)](./leetcode_myself/069.cpp)|使用二分查找|time:O(NlogN)| 98%
|070|[Climbing Stairs](./leetcode_myself/070.cpp)|dp|time O(N) space O(N)| ~0ms 100%
|073|[Set Matrix Zeroes](./leetcode_myself/073.cpp)|math|time O(M*N) space O(1)| 48ms 44%
|075|[Sort Colors](./leetcode_myself/075.cpp)|two pointer|time O(N) space O(1)| 4ms 36%
|076|[Minimum Window Substring](./leetcode_myself/076.cpp)|two pointer + greedy|time O(N) space O(1)|4ms 99%
|078|[Subsets](./leetcode_myself/078.cpp)|backtracking recursion|time: O(2^N) space: O(N)| 4ms 100%
|079|[Word Search](./leetcode_myself/079.cpp)|dfs|time O(M*N*(4^L)) space O(L) L=len(word)| 20 ms,80.20%
|084|[Largest Rectangle in Histogram](./leetcode_myself/084.cpp)|stack|time O(N) space O(N)| 12 ms, 44%
|088|[Merge Sorted Array](./leetcode_myself/088.cpp)|merge|time O(N) space O(1)| 4 ms, 99%
|091|Decode Ways
||[091_RecursionWithMemorization](./leetcode_myself/091_RecursionWithMemorization.cpp)|递归+内存共享|time O(N^2),space:O(N^2)|31%
||[091_dp](./leetcode_myself/091_dp.cpp)|动态规划|time:O(N) space:O(1)|100%
|094|[Binary Tree Inorder Traversal](./leetcode_myself/094.cpp)|tree|time O(N) space O(1)| 0 ms, 100%
|098|[Validate Binary Search Tree](./leetcode_myself/098.cpp)|recursion|time O(N) space O(height)| 8 ms, 65%
|101|[Symmetric Tree](./leetcode_myself/101.cpp)| dfs/bfs | time O(N) space O(1)| 8ms, 25%
|102|[Binary Tree Level Order Traversal](./leetcode_myself/102.cpp)| dfs/bfs | time O(N) space O(height)| 4ms, 98%
|103|[Binary Tree Zigzag Level Order Traversal](./leetcode_myself/103.cpp)|stack + recursion | time O(N) space O(N)| 4ms, 49%
|103|[Binary Tree Zigzag Level Order Traversal](./leetcode_myself/103.cpp)|queue + layerOrder| time O(N) space O(N)| 4ms, 49%
|104|[Maximum Depth of Binary Tree](./leetcode_myself/104.cpp)|reursion dfs| time O(N) space O(height)| 4ms, 98%
|105|[Construct Binary Tree from Preorder and Inorder Traversal](./leetcode_myself/105.cpp)|recursion ||100%
|108|[Convert Sorted Array to Binary Search Tree](./leetcode_myself/108.cpp)|recursion |time O(N) space O(height)|12ms, 56%
|116|[Populating Next Right Pointers in Each Node](./leetcode_myself/116.cpp)|dfs/bfs |time O(N) space O(height)|16ms, 47%
|118|[Pascal's Triangle](./leetcode_myself/118.cpp)|math|time O(N^2) space O(N^2)|~0 100%
|121|[Best Time to Buy and Sell Stock](./leetcode_myself/121.cpp)|dp|time O(N) space O(1)|~0 100%
|122|[Best Time to Buy and Sell Stock II](./leetcode_myself/122.cpp)|math|time O(N) space O(1)|4ms 100%
|124|[Binary Tree Maximum Path Sum](./leetcode_myself/124.cpp)|dfs|time O(N) space O(height)|20ms 44%
|125|[Valid Palindrome](./leetcode_myself/125.cpp)|string stl |time O(N) space O(N)|8ms 61%
|127|[Word Ladder](./leetcode_myself/127.cpp)|bidirectional bfs |time O(N*26^(L/2)) space O(N)|28ms 93%
|128|[Longest Consecutive Sequence](./leetcode_myself/128.cpp)|hash map|time O(N) space O(N)|8ms 67%
|130|[Surrounded Regions](./leetcode_myself/130.cpp)|dfs||12ms 99%
|131|[Palindrome Partitioning](./leetcode_myself/131.cpp)|dp+dfs|time O(N^2) space O(N^2)|4ms 100%
|134|[Gas Station](./leetcode_myself/134.cpp)|greedy|time O(N) space O(1)|4ms 99%
|136|[Single Number](./leetcode_myself/136.cpp)|hash map|time O(N) space O(N)|16 ms 35%
|136|[Single Number](./leetcode_myself/136.cpp)|math|time O(N) space O(1)|8 ms 98%
|138|[Copy List with Random Pointer](./leetcode_myself/138.cpp)|list|time O(N) space O(1)|44 ms 39%
|138|[Copy List with Random Pointer](./leetcode_myself/138.cpp)|hashmap|time O(N) space O(N)|36 ms 52%
|139|[Word Break](./leetcode_myself/139.cpp)|动态规划|time:O(N^2) space:O(N)|100%
|140|[Word Break II](./leetcode_myself/140.cpp)|dp+dfs|time O(N^2) space O(N^2)|8ms,81%
|141|[Linked List Cycle](./leetcode_myself/141.cpp)|two pointer|time O(N) space O(1)|4ms 100%
|146|[LRU Cache](./leetcode_myself/146.cpp)|hash map list|time O(1) space O(N)|84ms 55%
|148|[Sort List](./leetcode_myself/148.cpp)|merge sort list|time O(NlogN) space O(1)|28ms 100%
|149|[Max Points on a Line](./leetcode_myself/149.cpp)|dp+math|time O(N^2) space O(N)|8ms 67%
|150|[Evaluate Reverse Polish Notation](./leetcode_myself/150.cpp)|stack|time O(N) space O(N)|8ms 68%
|152|[Maximum Product Subarray](./leetcode_myself/152.cpp)|动态规划 |time:O(N) space:O(1)|100%
|155|[Min Stack](./leetcode_myself/155.cpp)| stack || 16ms,99%
|160|[Intersection of Two Linked Lists](./leetcode_myself/160.cpp)|two pointer |time:O(N) space:O(1)|24ms 87%
|166|[Fraction to Recurring Decimal](./leetcode_myself/166.cpp)|math ||0ms 100%
|162|[Find Peak Element](./leetcode_myself/162.cpp)|二分查找|time:O(logN) space:O(1)|4ms 99%
|169|[Majority Element](./leetcode_myself/169.cpp)|BST |time O(N) space O(N)|8ms 99%
|169|[Majority Element](./leetcode_myself/169.cpp)|Boyer-Moore vote |time O(N) space O(1)|8ms 99%
|169|[Majority Element](./leetcode_myself/169.cpp)|randomization |time O(N) space O(1)|8ms 99%
|169|[Majority Element](./leetcode_myself/169.cpp)|bit vote |time O(32*N) space O(1)|12ms 98%
|169|[Majority Element](./leetcode_myself/169.cpp)|full sorting |time O(NlgN) space O(1)|12ms 98%
|169|[Majority Element](./leetcode_myself/169.cpp)|partial sorting |time O(N) on avg space O(1)|12ms 98%
|169|[Majority Element](./leetcode_myself/169.cpp)|divide and conquer | time O(N)~O(NlgN) space O(NlgN)|16ms 65%
|169|[Majority Element](./leetcode_myself/169.cpp)|divaideand conquer | time O(N)~O(NlgN) space O(lgN)|8ms 99%
|171|[Excel Sheet Column Number](./leetcode_myself/171.cpp)|math | time O(N) sapce O(1)|4ms 98%
|172|[Factorial Trailing Zeroes](./leetcode_myself/172.cpp)|math | time O(logN) space O(1)|12ms 40%
|179|[Largest Number](./leetcode_myself/179.cpp)|sort |time O(NlogN) space O(N)|0ms 100%
|189|[Rotate Array](./leetcode_myself/189.cpp)|math |time O(N) space O(1)|12ms 100%
|190|[Reverse Bits](./leetcode_myself/190.cpp)|math ||4ms 88%
|191|[Number of 1 Bits](./leetcode_myself/191.cpp)|math ||0ms 100%
|198|[House Robber](./leetcode_myself/198.cpp)|math |time O(N) space O(1)|0ms 100%
|200|[Number of Islands](./leetcode_myself/200.cpp)|dfs |time O(2*V*E) sapce O(1)|8ms 99%
|202|[Happy Number](./leetcode_myself/202.cpp)|math ||0ms 100%
|204|[Count Primes](./leetcode_myself/204.cpp)|math |time O(N log log N) space  O(n)|32ms 56%
|206|[Reverse Linked List](./leetcode_myslf/206.cpp)|list|time:O(N) space:O(1)|8ms 33%
|207|Course Schedule
||[207_dfs](./leetcode_myself/207_dfs.cpp)|dfs 解法,二维 vector / map 采用邻接表存储图 |time:O(Node+Edge) |99%
||[207_bfs](./leetcode_myself/207_bfs.cpp)|bfs,使用 queue + vector 数据结构, 采用邻接表存储图|time:O(Node+Edge) | 99%
|208|[Implement Trie (Prefix Tree)](./leetcode_myself/208.cpp)|trie |time O(L) space O(n*l^2)|56ms 69%
|210|[Course Schedule II](./leetcode_myself/210.cpp)|dfs |time = space = O(V+E)~O(V^2)|12ms 87%
|212|[Word Search II](./leetcode_myself/212.cpp)|dfs + trie ||56ms 46%
|215|[Kth Largest Element in an Array](./leetcode_myself/215.cpp)|heap/quick sort |time O(N lgN) space O(N)|16ms 37%
|217|[Contains Duplicate](./leetcode_myself/217.cpp)|set |time O(N lgN) space O(N)|16ms 
|218|[The Skyline Problem](./leetcode_myself/218.cpp)|bst |Time O(NlogN) sapce O(N)|16ms 92%
|230|[Kth Smallest Element in a BST](./leetcode_myself/230.cpp)|中序遍历+stack|time:O(N) space:O(N)| 8ms 99%
|227|[Basic Calculator II](./leetcode_myself/227.cpp)| stack |time O(N) space O(N)|4ms 100%
|234|[Palindrome Linked List](./leetcode_myself/234.cpp)| two pointer |time O(N) |8ms 99%
|236|[Lowest Common Ancestor of a Binary Tree](./leetcode_myself/236.cpp)|dfs|time O(N) space O(height)|12ms 58%
|237|[Delete](./leetcode_myself/237.cpp)| list |time O(1) |8ms 36%
|238|[Product of Array Except Self](./leetcode_myself/238.cpp)| |time O(N) space O(N)|40ms 42
|239|[Sliding Window Maximum](./leetcode_myself/239.cpp)| BST(multiset)|time O(Nlogk) space O(K)|80ms 22%
|239|[Sliding Window Maximum](./leetcode_myself/239.cpp)| monotonic queue|time O(N) space O(K)|80ms 22%
|239|[Sliding Window Maximum](./leetcode_myself/239.cpp)| optimzie monotonic queue -> deque|time O(N) space O(K)|36ms 100%
|240|Search a 2D Matrix II
||[240](./leetcode_myself/240.cpp)|brute force|time:O(N*M) space:O(1)| 964ms 1.4%
||[240](./leetcode_myself/240.cpp)|divide and conquer+ recursion|time:O(n^1.58)| 1284ms 0.3%
||[240](./leetcode_myself/240.cpp)| Smart alg|time O(M+N) space O(1)| 36ms 98%
|242|[Valid Anagram](./leetcode_myself/242.cpp)||time O(N) space O(1)|16ms 36%
|268|[Missing Number](./leetcode_myself/268.cpp)|xor|time O(N) space O(1)|4ms 100%
|268|[Missing Number](./leetcode_myself/268.cpp)|sum|time O(N) space O(1)|4ms 100%
|268|[Missing Number](./leetcode_myself/268.cpp)|math|time O(N) space O(1)|4ms 100%
|279|[Perfect Squares](./leetcode_myself/279.cpp)| dp|time: O(N^2) space:O(N)|73%
|283|[Move Zeroes](./leetcode_myself/283.cpp)| math|time: O(N) space:O(1)|8ms, 100%
|287|Find the Duplicate Number
||[287](./leetcode_myself/287.cpp)|brute force|time O(N^2) sapce O(1)| 452ms  3.2%
||[287](./leetcode_myself/287.cpp)|binary search|time O(NlogN) space O(1)| 12ms 35%
||[287](./leetcode_myself/287.cpp)|Floyd alg|time O(N) space O(1)| 4ms 100%
|289|[Game of Life](./leetcode_myself/289.cpp)| math|time O(M*N) space O(1)|0ms, 100%
|295|[Find Median from Data Stream](./leetcode_myself/295.cpp)| bst|time add O(logN) find O(1) space O(N)|108ms, 67%
|295|[Find Median from Data Stream](./leetcode_myself/295.cpp)| heap|time add O(logN) find O(1) space O(N)|100ms, 91%
|297|[Serialize and Deserialize Binary Tree](./leetcode_myself/297.cpp)| |time O(N) space O(N)|24ms, 62%
|300|Longest Increasing Subsequence
||[300](./leetcode_myself/300.cpp)|动态规划|time:O(N^2) space:O(N) |16ms 55%
||[300](./leetcode_myself/300.cpp)|dp+binary search|time:O(NlogN) space:O(N) |~0ms 100%
|315|[Count of Smaller Numbers After Self](./leetcode_myself/315.cpp)|FenwickTree|time O(NlogN) space O(N)|36ms 48%
|322|[Coin Change](./leetcode_myself/322.cpp)|方法一:dp 方法二:dfs greedy|time:O(size_array*amount) space:O(amount)|4ms 99%
|324|[Wiggle Sort II](./leetcode_myself/324.cpp)||time O(N) space O(1)|124ms 11%
|326|[Power of Three](./leetcode_myself/326.cpp)|math|time O(1) space O(1)|88ms 20%
|329|[Longest Increasing Path in a Matrix](./leetcode_myself/329.cpp)|dp+dfs|time O(COLS* ROWS) space O(COLS*ROWS)|32ms 67%
|334|[Increasing Triplet Subsequence](./leetcode_myself/334.cpp)|math|time O(N) space O(1)|8ms
|341|[Flatten Nested List Iterator](./leetcode_myself/341.cpp)|stack| |20ms 34%
|344|[Reverse String](./leetcode_myself/344.cpp)|使用stl|time O(N) space O(N)|4ms 100%
|347|[Top K Frequent Elements](./leetcode_myself/347.cpp)|hash map + heap|time O(NlogK) space O(N)|20ms 44%
|347|[Top K Frequent Elements](./leetcode_myself/347.cpp)|hash map + sort|time O(NlogN) space O(N)|12ms 99%
|349|[Intersection of Two Arrays](./leetcode_myself/349.cpp)| set|time:O(M+N) space:O(M+N)|4ms 100%
|350|Intersection of Two Arrays II
||[350](./leetcode_myself/350.cpp)|使用排序+双子针 | time: O(max(NlogN,MlogM)) space:O(max(N,M))|8ms 36%
||[350](./leetcode_myself/350.cpp)|使用 map | time:O(N+M) space:O(max(N,M))|4ms 100%
|371|[Sum of Two Integers](./leetcode_myself/371.cpp)| xor|time = space = O(1)|0ms 100%
|378|[Kth Smallest Element in a Sorted Matrix](./leetcode_myself/378.cpp)|binary search|time O(log(max-min)*N*logN) space O(1)| 32ms 57%
|380|[Insert Delete GetRandom O(1)](./leetcode_myself/380.cpp)|使用哈希映射和数组 ||99%
|384|[Shuffle an Array](./leetcode_myself/384.cpp)| |time O(N) space O(N)| 228ms,48%
|387|[First Unique Character in a String](./leetcode_myself/387.cpp)|使用哈希映射 |time O(N) space O(1)|24ms 98%
|395|[Longest Substring with At Least K Repeating Characters](./leetcode_myself/395.cpp)|dfs |time O(26*N) space O(N)|0ms 100%
|412|[Fizz Buzz](./leetcode_myself/412.cpp)|math|time O(N) space O(1)|4 ms 76%
|454|[4Sum II](./leetcode_myself/454.cpp)|hashmap|time O(N^2) space O(N^2)|100 ms 94.50%
|593|[Valid Square](./leetcode_myself/593.cpp)|math|| 100%
|771|[Jewels and Stones](./leetcode_myself/771.cpp)|hashtable|time O(M+N) space O(1)| 4ms,98%


