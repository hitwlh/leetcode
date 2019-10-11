164_Maximum_Gap


题目大意
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.



解决方案
这题非常妙。非常简单的做法就是直接sort然后找。这个开销是O(NlogN)。还有O(N)的解法。
用桶排的思想(当然其实不需要真的去排序，事实上是压缩解的可能性)
Suppose there are N elements and they range from A to B.
Then the maximum gap will be no smaller than ceiling[(B - A) / (N - 1)]上整

len = ceiling[(B - A) / (N - 1)], then we will have at most num = (B - A) / len + 1 of bucket
当然这里不值得花很多时间去想具体多少桶，可以适当多分配几个，或者每次如桶前看桶够不够，不够就增加就是了，都可以

注意，由于一个桶的上下界的差有最大值，且通过鸽巢原理设计，令其小于最终解，所以桶内没有解，解只能在桶间，因此就可以桶内不排序。因此只需要保存每个桶里的最大值最小值，然后顺序遍历所有桶，求出桶间差距最大的就是最终解

样例


