31_Next_Permutation


题目大意
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.
输出下一排列

解决方案
首先排列的各个元素显然有偏序关系<
假设给出的排列最后5个元素是ABCDE，通过从尾部遍历一遍得到关系如下：
...A<B>C>D>E
那么下一个排列就需要从BCDE里头挑一个最小的(且比A大)和A对调，假如是C，那么这几个元素之间的大小关系是B>C>A>D>E,
对调完的最后5个元素是：...C<B>A>D>E
再把BADE逆序一下就变成了...C>E<D<A<B

所以算法就是先从后往前找到第一个A<B，然后从B>C>D>E中找出比A大的将其与A对调，最后再将后面几个元素颠倒

样例

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
