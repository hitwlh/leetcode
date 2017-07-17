214_Shortest_Palindrome


题目大意
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.


解决方案
这题题意理解之后，最快想到的肯定是暴力的解法。

solution1.cpp
暴力解法。input是s，假如需要在左边添加t，则t+s是回文串
说明s.substr(s.length() - t.length())是回文串，要令t最小，就是要找到s里最大的i，使得s.substr(i)是回文的
这样的串，显然最右侧的字符==s[0]，因此从有往左找==s[0]的字符s[j]，找到的话，再看s.substr(j+1)是不是回文的，如果是，那直接就得到结果了，把j右侧的串reverse然后添加到s左侧，就是结果了。

solution2.cpp
这里需要补一下kmp的知识
这个资料讲得非常清楚
http://blog.csdn.net/v_july_v/article/details/7041827
理解next数组之后，代码就好写了。
在参考链接里next[i] = j表示
s[0] s[1] ... s[j-1] == s[i-j] s[j] ... s[i-1]
例如：
KMP table:
c  a t a c b # b c a t a c
-1 0 0 0 0 1 0 0 0 1 2 3 4
参考链接里讲了这样子的next数组怎么求。。
但是在这里要包含到最后一个元素，所以在最后再多求一个next，
那么就有这样的kmp table:
KMP table:
c  a t a c b # b c a t a c
-1 0 0 0 0 1 0 0 0 1 2 3 4 5
这个5就表示最后5个元素是互文的，因此只需要添加前1个元素在末尾就ok了



样例

Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".

