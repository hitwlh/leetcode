321_Create_Maximum_Number


题目大意
Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.


给了我们两个数组，里面数字是无序的，又给我们一个k值为k <= m + n，然后我们从两个数组中共挑出k个数，数字之间的相对顺序不变，求能组成的最大的数。

解决方案
翻译：给两个vector表示两个数，再给length为k，求用vector里的数能组成的最大数字
要求不能改变相对顺序。具体看例子

解决方案：
1. 由于要找k位，并且是从两个vector里分别挑的，所以第一个vector里最少选max(0, k-n)个数字，最多选min(m, k)个数字，对应算得另一个vector里选多少

2. 参考http://www.cnblogs.com/grandyang/p/5136749.html

假如第一个vector里选i个数字，第二个里选k-i个数字，那么肯定要从第一个vector里挑最大的i位数，第二个里挑最大的k-i位数
挑最大的i位数的方法是，从第一个数字开始，入栈，栈从上到下递增。处理一个数字时，如果后面的数字还够多，就把当前数字和栈里的数字比较，如果栈顶小，就一直弹栈，直到栈空或栈顶不比当前处理的数字小，再将当前数字入栈；如果后面的数字刚刚好够用，那就把剩余所有数字入栈就行了。

3. 选好两个数字之后做merge，这里竟然容易错。如果当前比较的有大小区别，那显然了。但是如果是相等的，那怎么处理呢？正确的办法是往后比较，选后面一位更大的那个，如果一直比较到一个到尾了，那就用另一个。这里还挺有讲究的。具体看代码。
反例：
[6,7]
[6,0,4]
这里必需选第一个vector里的6.

solution.cpp是我自己写的。solution1.cpp是参考网上的。solution1简洁得多，主要用了vector类的max和<操作符。




样例
Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]

