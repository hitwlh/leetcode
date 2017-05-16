381_Insert_Delete_GetRandom_O1_-_Duplicates_allowed


题目大意
Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.





解决方案
380题的进阶版本
参考http://blog.csdn.net/vipin_pei/article/details/52540894
将unordered_map<int, int> mmp;改为unordered_map<int, unordered_set<unsigned int>> mmp;就行了。
注意写erase的时候还是麻烦了不少。如果是删除末尾，很好删。直接删set和mmp里的就行了。如果不是删除末尾，那麻烦多了，三言两语讲不清，直接看代码

样例
Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();

