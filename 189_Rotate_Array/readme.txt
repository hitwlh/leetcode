189_Rotate_Array


题目大意
Rotate an array of n elements to the right by k steps.

解决方案
1. 最简单的方法就是新建一个vector，然后按照次序拷贝过来。这个就没写代码了，太简单
2. 1次循环右移1位，做k次就行了，但是这个时间开销是O(nk)，会超时
改进的方法是依次循环移动k位，但是这个可能构成一个环，如下所示：
[1,2,3,4,5,6] k=2
cur = nus[0]
nums[0] = nums[2]
nums[2] = nums[4]
nums[4] = cur，这就死循环了

应该用一个distance检测当前到了哪里，如果发现当前构成了环，那要把起始的下标+1
solution1.cpp 这个代码参考的是网上的，事实上为何一定正确我并不是非常确定

3. 先整个数组reverse，然后前k个数字做reverse，后面的数字再reverse就是结果了
solution2.cpp，写这个代码的时候要注意reverse的起点、终点、中点！！！

样例
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

