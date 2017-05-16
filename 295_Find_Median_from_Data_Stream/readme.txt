295_Find_Median_from_Data_Stream


题目大意
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.

解决方案
这题直观想到的解题思路是用vector，插入的时候用二分查找，这种解法在solution1.cpp。但是vector的insert要把后续元素顺序后移一位。插入开销是O(N)



更好的解法在solution2.cpp
参考了http://blog.csdn.net/tstsugeg/article/details/51956991
这里用堆，将左边一半存储在大根堆里，右边一半存储在小根堆里。保证左边size==右边size或者左边size==右边size+1
具体写的时候有好几种方法，我觉得最简单的写法在solution2.cpp。先写到左边，写完之后看左右元素数目是否满足关系，如果不满足关系，就将左边的top移动到右边去。但是还有种非法，就是如果写到左边后左右元素数目满足关系，但是左边的top要大于右边的top，那就swap一下两个top。
这就是solution2.cpp
同样的意思在参考链接里用了另一种写法：先按照大小关系写，然后调整size

样例

For example:

addNum(1)
addNum(3)
findMedian() -> 2
addNum(2) 
findMedian() -> 2

