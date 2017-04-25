188_Best_Time_to_Buy_and_Sell_Stock_IV


题目大意
Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

解决方案
参考了
http://blog.csdn.net/ljiabin/article/details/44900389
http://blog.csdn.net/feliciafay/article/details/45128771
http://www.jianshu.com/p/67a5402a6f55

动态规划
到第i天时进行j次交易的最大收益，要么等于到第i-1天时进行j次交易的最大收益（第i天价格低于第i-1天的价格），要么等于到第i-1天时进行j-1次交易，然后第i天进行一次交易（第i天价格高于第i-1天价格时）。于是得到动规方程如下（其中diff = prices[i] – prices[i – 1]）：

profit[i][j] = max(profit[i – 1][j], profit[i – 1][j – 1] + diff)
但其实不对，为什么不对呢？因为diff是第i天和第i-1天的差额收益，如果第i-1天当天本身也有交易呢，那么这两次交易就可以合为一次交易，这样profit[i – 1][j – 1] + diff实际上只进行了j-1次交易，而不是最多可以的j次，这样得到的最大收益就小了。



mustSell[i][k] 表示前i天，至多进行k次交易，第i天必须sell的最大获益
globalbest[i][k] 表示前i天，至多进行k次交易，第i天可以不sell的最大获益
mustSell[i][k] = max(globalBest[i - 1][k - 1] + profit, mustSell[i - 1][k] + profit)
globalBest[i][k] = max(globalBest[i - 1][k], mustSell[i][k])
globalBest比较简单，不过是不断地和已经计算出的local进行比较，把大的保存在globalBest中。
然后看mustSell， 关键是要理解mustSell的定义，mustSell[i][j]表示，前i天进行了j次交易，并且第i天进行了第j次交易的最大利润，所以mustSell[i][j]中必然有一次交易，也就是当近一次交易，发生在第i天。 mustSell由两个部分的比较完成。
第一部分是，globalbest[i-1][j-1]+max(diff,0), 表示的就是，前面把之前的j - 1次交易，放在之前的i - 1天，然后让第i天来进行第j次交易，那么加入此时diff(price[i] - price[i - 1])大于零，那么正好可以可借助这次交易的机会增长里利润(利润= diff)，否则的话，如果diff小于零，那就在第i天当天进行一次买卖，凑一次交易的次数，但是产生利润为0.
第二部分是, mustSell[i-1][j]+diff， 这里的 mustSell[i-1][j]表示的是，前面j次交易在第i - 1天就已经完成了，可是因为说了mustSell[a][b]一定要表达在第a天完成了b次交易的最大利润，所以就需要强制使得交易在第i天发生，为了实现这一点，只需要在local[i - 1][j]的基础上，加上diff ( = price[i] - price[i - 1])就可以了。如果diff < 0 那也没有办法，因为必须满足local的定义。接下来算global的时候，总会保证取得一个更大的值。


具体写的时候可以用二维数组，solution1.cpp
也可以优化空间，solution2.cpp
注意在优化空间的时候，迭代的次序有点变化。
solution1.cpp中：
for(int j = 1; j <= k; j++){
    for(int i = 1; i < prices.size(); i++){
solution2.cpp中：
for(int i = 1; i < prices.size(); i++){
    for(int j = k; j >= 1; j--){
基本上动态规划要优化空间都是这样做，迭代要逆序！！！要记得举一反三！！！

样例
