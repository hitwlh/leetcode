380_Insert_Delete_GetRandom_O


题目大意
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.






解决方案
看到那么多的O(1)要求，很自然地会想到用hash去做。但是用hash的话可以插入删除没法O(1)产生随机元素。
这就涉及到c++ stl的实现了，unordered_map是用一个大的vector然后冲突的话就用一个链表存储。这样是无法直接线性获取到
可以看一看http://www.cplusplus.com/reference/unordered_map/unordered_map/begin/关于unordered_map的桶的代码，mymap.begin(i)能获取到第i个桶的begin，mymap.end(i)获得到第i个桶的end。
为了O(1)时间内解决这个问题，用一个vector，hash一个值的存储索引。这样就能线性查找、插入。删除的时候把最后一个元素和删除的元素swap一下，然后erase最后一个元素




样例

Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
