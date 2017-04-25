146_LRU_Cache


题目大意
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

解决方案
这题关键在于怎么设计数据结构，我一开始也能想到要用一个队列来保存<key, value>，然后查找成功的话就把该元素移动到队列头
但是队列的移动操作是O(n)的，因为需要查找。
想把队列的移动操作减到O(1)，需要：双向队列，知道队列的iterator
因此设计出了这题的数据结构：
unordered_map<int, list<pair<int, int>>::iterator> index;
list<pair<int, int>> data;

用
data.splice(data.begin(), data, index[key]);能够把data的index[key]元素移动到data.begin()

ont-time-attention
list里要保存pair，因为index做erase操作的时候是根据key来的，如果只存value，index就没法做erase了!!!

样例

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
