13_Roman_to_Integer


题目大意
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.

解决方案
罗马数字规则：https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97
左减数字必须为一位，因此要做减法的只需要往右看一下就ok

扫描字符串，对于右侧更大的字符，应该拿去做减法，右侧更小的字符应该拿去做加法
最右侧的字符肯定拿去做加法

样例


