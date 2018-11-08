# leetcode-myself
leetcode code by myself

使用 C/C++ 编程
--
001:暴力搜索,使用两次迭代 10%

001_hashmap:使用哈希表,时间:O(N),空间O(N) 70%

001_binarySearch: 先记住数组下标,后排序,后用二分查找 时间:O(NlgN)+O(N)  空间:O(N)  99%

002:分别考虑4种情况,有4处if判断 100%

003:根据条件最多长度95,暴力搜索 51%

003_hashmap:使用字符值建立哈希表 O(N**2)  51%

005:使用3层迭代,效率极低 O(N**3) 23%

005_dp:使用动态规划,使用一个二维数组标记回文,减少一层循环,O(N**2) 48%

007:考察整数最值表示与转换 98%

008:主要考察字符串处理 100%

011:Container With Most Water 暴力解法,时间:O(N**2) 40%

011_twoPointer: 双指针解法, 时间:O(N) 100%

019:Remove Nth Node From End of List 双指针解法, 注意删除head 节点的情况,时间:O(N),100%

055:贪婪算法,从尾部向前求局部最优 100%

069:使用二分查找O(NlgN) 98%

207_dfs:Course Schedule : 图之 DFS 解法,二维 vector / map(=>采用邻接表存储图),时间:O(Node+Edge) 99%

207_bfs:图之bfs,使用 queue + vector 数据结构, 采用邻接表存储图,时间:O(Node+Edge)  99%

593:较直接的判断方式,第一时间不一定能想到 100%

105:递归方法 100%