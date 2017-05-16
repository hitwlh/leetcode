486_Predict_the_Winner


题目大意
Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.



Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.





解决方案
这题一看就知道动态规划和暴力搜索都能解。数据量很小，暴力解法在solution1.cpp。时间复杂度2^n

动态规划解法在solution2.cpp
动规解法的递推公式挺有意思的。
对于区间[j, i+j-1]，选手A可以选j\i+j-1，选完之后选手B在剩余区间先选，他的最优解就是选手A在那个区间的最优解，因此直接用sum减去选手A的在[j+1, i+j-1]以及[j, i+j-2]的最优解，就是选手A在选了左/右后在剩余子区间的结果，再和j\i+j-1拼接到一起。
时间复杂度n^2




样例

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
