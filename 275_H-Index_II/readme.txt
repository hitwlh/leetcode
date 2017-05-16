275_H-Index_II


题目大意
274题的进阶版本。
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

解决方案
考虑1 4 4 4
h是3。需要明白的一点：h属于[0, citations.size()]
二分搜索其实是要找第一个满足citations[i] >= n - i的i(有n-i篇，它引大于等于n-i的文章)，然后返回n - i
看代码，有两种写法。while(L <= R)和 while(L < R)

样例


