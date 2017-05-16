162_Find_Peak_Element


题目大意
A peak element is an element that is greater than its neighbors.
Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that num[-1] = num[n] = -∞.




解决方案
就是给一个数组，找到其中的"peak"：比左边邻接元素大、比右边邻接元素大。假设两侧都是-∞

思路：二分。参考http://courses.csail.mit.edu/6.006/spring11/lectures/lec02.pdf，这里头把这个称作“采样”
直观想一想，初始化left、right后，[left, right]内一定有peak存在。如果peak不是left、right，那peak一定在left右边，right左边，我随机采样（比如选择中点），采样点要么是peak，要么是peak左，要么是peak右，可以通过将采样点和采样点左侧元素对比，来判断采样点在peak哪侧，用采样点更新[left, right]区间，然后反复做就是了。

非常有意思的题目！！！

样例
For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

