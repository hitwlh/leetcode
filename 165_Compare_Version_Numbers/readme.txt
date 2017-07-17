165_Compare_Version_Numbers


题目大意
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.





解决方案
这题就是要比较版本号的大小。算法角度看很简单，代码不难写。难度在于题意
1. 01 和 1 的版本号是相等的
所以需要string转int来对比

2. 1 和1.0的版本号是相等的
所以前缀相等之后，还需要看一下后面是否有非'0'非'.'的字符


样例

Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
