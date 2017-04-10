8_String_to_Integer_atoi


题目大意
Implement atoi to convert a string to an integer.

解决方案
就是个字符串的问题，有以下几个需要考虑的：
1.开头有若干空格，可以直接跳过
2.跳过空格后，以'+'/'-'开头，则需要标记下正负，同时跳过
3.扫描数组，得到结果。扫描过程有两种情况：

a.扫描到当前位置，超过了int范围，则直接返回INT_MAX 或者 INT_MIN
b.扫描到当前位置，不是数字，则直接返回当前扫描结果

样例


