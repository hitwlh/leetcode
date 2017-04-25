121_Best_Time_to_Buy_and_Sell_Stock


题目大意
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

解决方案
想清楚一个点：某一天如果卖，那前面买的价格肯定是最低的，因此只需要从nums[i]到尾遍历一遍，遍历到的时候就是假设要在这天卖，非常简单
curMin = min(curMin, prices[i-1]);
ret = max(ret, prices[i] - curMin);




样例
Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.

