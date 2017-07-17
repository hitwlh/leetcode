319_Bulb_Switcher


题目大意
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.



解决方案
题意好理解，给数字n，表示n盏灯，编号1, 2, 3, 4, ..., n，初始为全暗，然后把下面这些灯进行翻转
1, 2, 3, 4, ..., n
2, 4, 6, ...
3, 6, ...
...
n-1
n

如果模仿这个过程,那开销是O(n^2)。事实上考虑一下，对编号为36的灯
(1, 36) (2, 18) (3, 12) (4, 9) (6, 6)
也就是：
第1次翻转和第36次翻转会修改36号灯
第2次翻转和第18次翻转会修改36号灯
第3次翻转和第12次翻转会修改36号灯
第4次翻转和第9次翻转会修改36号灯
第6次翻转会修改36号灯
(1, 36) (2, 18) (3, 12) (4, 9)这样的翻转并不能真正修改36号灯，(6, 6)才会。
因此只有平方数能亮，其余都灭。
因此只需要看1,2,3,...n里有多少个平方数，这个直接对n开方就得到了。



样例
Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.

