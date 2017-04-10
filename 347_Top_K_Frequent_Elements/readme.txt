347_Top_K_Frequent_Elements


题目大意
Given a non-empty array of integers, return the k most frequent elements.

解决方案
先对所有数字用map统计出现次数，然后根据次数放到优先队列里，最后再输出就是了

样例
For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

