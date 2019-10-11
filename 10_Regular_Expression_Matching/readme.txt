10_Regular_Expression_Matching


题目大意
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)





解决方案
参考http://www.cnblogs.com/grandyang/p/4461713.html
和 44 Wildcard Matching类似。不同点在于*的意义不同，在之前那道题中，*表示可以代替任意个任意字符，而这道题中的*表示之前那个字符可以有0个，1个或是多个，就是说，字符串a*b，可以表示b或是aaab，即a的个数任意。


1. 暴力解法，solution.cpp

1. p.size() <=1 ，那很好处理了，根本没有'*'
2. p[1] != '*'，那也很好处理，先判断p[0]是否匹配，然后递归调用isMatch(s.substr(1), p.substr(1))
3. p[1] == '*'，这时的处理不好写了，直接看代码：
while(s != "" && (s[0] == p[0]) || p[0] == '?'){
    if(isMatch(s, p.substr(2))) return true;
    s.erase(s.begin());
}
return isMatch(s, p.substr(2));//点睛之笔


2. 动规解法，solution1.cpp
参考https://discuss.leetcode.com/topic/17852/9-lines-16ms-c-dp-solutions-with-explanations/3

P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise.
P[i][j] =  (s[i - 1] == p[j - 1] || p[j - 1] == '.') && P[i - 1][j - 1], if p[j - 1] != '*';
P[i][j] = P[i][j - 2] || (P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')), if p[j - 1] == '*'
p[j-1] == '*' 时，P[i][j - 2]表示p[j-2]*使用0次；
P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.') 表示p[j-2]*至少使用1次。这个至少使用1次一开始写错了，我写成了P[i][j-1]大错特错



样例
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

