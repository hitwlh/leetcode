375_Guess_Number_Higher_or_Lower_II


题目大意
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.





解决方案
这题首先要明白不是二分而已。
比如求[1, 4]这个区间，正确的解法是去看1、3，如果二分做就是2、3了，代价更大
要遍历[1,n]找切割点，这个问题就成了动态规划，左侧和右侧都要保留，然后代价就是min(k + max(result[j][k-1], result[k+1][j+i-1]));
看代码的注释，切割点不是区间终点。
其实这题的递推公式
solve(L,n) = x + max(solve(L,x-1),solve(x+1,n)) 不是很好想
我一开始以为x应该改为x-1，因为如果选择的是左侧，而左侧的最右一定不是切割点，那直接选左侧的最右，也即x-1，然后不选x就是了。事实上大错特错，因为这完全了解岔了，选x-1，只知道答案在其右侧，不知道x是不是答案，因此这两者完全不等价。反倒是选完x-1还要选x
其实这个递推公式相当于模拟了这个的求解过程。首先随便选一个位置切割，然后左右都要是最优解，随便选的位置也可以从头到尾遍历。这样做毫无疑问能得到最优解。





样例
Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.



