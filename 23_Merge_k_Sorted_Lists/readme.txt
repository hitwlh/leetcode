23_Merge_k_Sorted_Lists


题目大意
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

解决方案
先实现merge2
然后按照merge sort的划分方式，进行合并。总元素数目是N, 时间复杂度是O(kN)


solution2.cpp
用一个容量为k的小根堆，每次从堆里选最小的，移除，再将其下一个节点放入堆，时间复杂度是O(kN)

样例


