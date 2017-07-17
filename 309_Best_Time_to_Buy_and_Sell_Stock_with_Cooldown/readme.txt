309_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown


题目大意
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)



解决方案
自己没想到方法做，看了solution里的参考答案。分成了三个数组:sell, buy, rest
如果想到要3个数组，这题就不难了。

buy表示当天自己持有股票时的最大收益
sell表示当天自己不持有股票时的最大收益
rest表示当天不操作的的最大收益




样例
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]

