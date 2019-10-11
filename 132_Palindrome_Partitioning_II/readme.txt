132_Palindrome_Partitioning_II


题目大意
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.



解决方案
这里要读一个字符串做cut，求最小的切割数，使得每个部分都是回文串。我没想到好的做法，参考了discuss

solution1.cpp
dp[i]表示从s[i]到串尾的最佳切割, isp[i][j]表示s[i...j]是否是回文串，显然dp[i]左边是一个回文串，右边本来就是最优子结构，因此用一个循环遍历去找左边的回文串

对j>=i, 且isp[i][j] == true
dp[i] = min(1+dp[j+1])
这里有个易错点就是当j==s.length()-1时，这个时候切割数是0，dp[j+1]没有意义，为了保持形式的统一，把dp[s.length()]设置成-1

这个解法的时间复杂度是O(n^2), 空间复杂度是O(n^2)

solution2.cpp
dp[i]表示从s[0]到s[i]的的最佳切割
右边是一个回文串，左边本来就是最优子结构。为了找右边的回文串，可以直接按照遍历的顺序，把i当做中点，看以i为中点所能获得的最长的回文串，这样计算dp[i+j]的时候，左侧是dp[i-j]，dp[i-j...i+j]是回文串，而i是中点，说明dp[i-j-1]是已经计算完了的，所以可以直接用到优化子结构
这个算法比较难想，但是空间复杂度做到了优化。实际效果也快了三五倍

这个解法的时间复杂度是O(n^2), 空间复杂度是O(n)

样例
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

