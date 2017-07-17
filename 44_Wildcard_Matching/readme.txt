44_Wildcard_Matching


题目大意
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)




解决方案

s里没有'?' '*'，所以特殊字符的匹配只需要考虑p




1.动规解法 solution.cpp
f[i][j]表示p[0...i]和s[0...j]能匹配

a. p[i] != '*'
若p[i]==s[j]或p[i]=='?',将最后一个字符匹配掉，所以f[i][j]=f[i-1][j-1];
否则f[i][j] = false

b. p[i] == '*'
'*'可以选择匹配0个字符，此时f[i][j]=f[i-1][j];或匹配1个字符，此时f[i][j]=f[i-1][j-1];……所以，
f[i][j] = f[i-1][j]||f[i-1][j-1]||……||f[i-1][0]
而f[i][j-1] = f[i-1][j-1]||f[i-1][j-2]||……||f[i-1][0]
所以f[i][j] = f[i][j-1] || f[i-1][j]

因此动规的时间复杂度是O(s.length() * p.length())
one-time-attention
1. 求f[0...p.length()][0] 的代码，也就是soluiton.cpp里被注释掉的内容是错的。反例：
"c"
"*?*"


2. 贪心、回溯 solution1.cpp
参考http://www.cnblogs.com/yezhangxiang/p/3920920.html
http://www.cnblogs.com/grandyang/p/4401196.html
http://blog.unieagle.net/2012/11/07/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Awildcard-matching/

依据连续的'*'，将p分割成一些不带'*'的子串。然后在s中依次匹配就好了。

1. 在p里面，首先连续做匹配(普通字符以及'?')，如果匹配失败，就“重新匹配”：
如果sstar有效，s上次从sstar开始匹配，现在把sstar++，然后从新的sstar开始匹配。如果sstar是无效的，那就直接返回false了)
2. 如果匹配到'*'，那说明'*'前面的匹配告一段落，记录下新的匹配位置
3. 如果s不能被有效匹配完，返回false；如果能，那再看p后面有没有非'*'

这个算法的复杂度不好说，因为匹配失败的时候，只是把sstar++。如果匹配失败的新起点改成类似KMP，应该就可以是线性了。

样例

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
