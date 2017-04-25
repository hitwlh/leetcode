122_Best_Time_to_Buy_and_Sell_Stock_II


题目大意
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

解决方案
这题和121题结合起来看，导致我的思维一下子局限在了动态规划的解法上，事实上这题应该是贪心，如果明天比今天贵，那我就今天买明天卖，就这个策略就能得到最优解。解决方案保留在solution.cpp里。

solution1.cpp 和 solution2.cpp里分别是两种超时的动态规划解法
虽然都是动态规划，但是这俩代码实现起来难度有差别。我发现[start, end]这个区间内部进行划分，也就是solutio2.cpp，要比[start, end]后半部分相结合的写法更简单，也就是solution1.cpp 。以后这类问题都尽量这样去做递归函数的设计


样例


