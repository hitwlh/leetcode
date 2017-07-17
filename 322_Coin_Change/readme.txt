322_Coin_Change


题目大意
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.



解决方案
看代码可以立刻看懂。
ret[i] = j代表amount=i时最少需要j个硬币
易错点还蛮多的，主要是边界判断。
1. 首先是，我直接用INT_MAX，返回的时候如果是INT_MAX，就要改成-1
2. 因为我初始化成了INT_MAX，而INT_MAX+1是INT_MIN，所以这里有溢出要处理，所以把ret里的元素改成了unsigned int类型的




样例
Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

