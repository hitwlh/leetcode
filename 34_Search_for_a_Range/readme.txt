34_Search_for_a_Range


题目大意
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

让我们在一个有序整数数组中寻找相同目标值的起始和结束位置

解决方案
1.显然是遍历解法，这个解法的代码在solution1.cpp
之所以拿来记录一下，是因为太坑爹了！！竟然出了3个wa才ac！！
考虑到right右侧是和target不同的，因此我用了for(int i = 1; i < nums.size(); i++)这个循环来找right+1
但是不对，因为右侧可能不存在！！！也就是说右侧可能没法访问，right已经到达最后，这个可以用判断最末尾元素是否==target来解决。
但是用i=1来作为初始化也是错的，因为可能1无法访问，vector就是只有1个元素！，因此要先判断nums[0]是否等于target！


2.第二个就是二分法了，用递归写的
和普通二分查找的区别在于：如果nums[mid] == target，需要继续往左右查找
这里有一个容易错的点：那就是递归函数的参数有left和right，它们的意义是查找区间，并不是结果，这里一不小心就混淆了！！结果应该由其它变量来保存
定义了int ret_left = INT_MAX, ret_right = -1;保存结果

第一个错是如果
样例


