123_Best_Time_to_Buy_and_Sell_Stock_III


题目大意
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

解决方案
参考121题 Best Time to Buy and Sell Stock， 可以在O(n)时间内找到一个区间内的最大收益
本题要求2次买卖，因此是需要找划分(将原数组划分为2份，分别买卖)，划分有O(n)种

一开始我直接调用121题的函数，那计算每个划分的收益的复杂度是O(n)总的复杂度是O(n^2)，结果超时了
网上查了查，想了想，其实可以一开始遍历数组一遍，得到left和right数组，left[i]表示从[0,i]区间进行一次买卖能获得的最大收益。right[i]表示从[i, prices.size()-1]区间进行一次买卖能获得的最大收益，求left数组和right数组的时间复杂度都是O(n)， 因此总的时间(加上划分)复杂度就是O(n)

样例


