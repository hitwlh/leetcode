464_Can_I_Win


题目大意
In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.
What if we change the game so that players cannot re-use integers?
For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.
You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.


解决方案
仔细看了看，不能通过数学手段直接得到结果。
那就是暴力搜索了。
有n!种排列。如果一直搜索不到赢的方法，就要遍历到尾，强行暴力的最坏开销就是O(n!)
n可以到20，超时
用动态规划。保留计算过的结果，如果遇到算过的，直接读取。这样的开销是C(1,n) + C(2,n) + C(3,n) + .. + C(n,n) = 2^n
2^20=100万，没问题。
如果保存过当前选择，那就不需要再保存当前sum了，因为如果选择的是一样的，那当前sum肯定也是一样的。


但是有一个非常需要注意的！！状态压缩！！
标识是否选择有2种方法，第一种是用一个长度为n的数组，0表示没选过，1表示选过了。当然用map也是类似的。更有效率的方法是直接用位运算。因为至多有20位，直接用一个unsigned int就能存下了，虽然这个对第一层map没什么用，但是对tmp_result非常有用，而且如果索引是unsigned int，那tmp_result就可以用unordered_map了。
unordered_map比map快一倍。位压缩过的比没压缩过的快3-5倍
solution.cpp里记录的是最快的


one-time-attention
要有if(maxChoosableInteger * (maxChoosableInteger+1) < desiredTotal * 2) return false;。如果所有选完sum不够，就是输。如果不做这个判断，可能调用出来对方输得出自己赢的结论。


样例
Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.

