274_H-Index


题目大意
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."





解决方案
首先是对于题意的理解，这一块就不简单。题目的意思是找出最大的h，满足它引至少为h的文章有h篇。
在solution1.cpp里第一个是正确的，第二个是错误、wa的
考虑输入[0, 0, 4, 4]，按照第一个算法可以得到2，按照第2个算法只能得到0。第一个算法碰到一篇高引文章，就会计算根据当前高引情况所能算得的h(相当于遍历文献篇数)，直到失败。而第二个算法只会遍历它引，错了！！
这道题蛮有意思的






solution2.cpp里记录的是hash的方式求。



样例


For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.