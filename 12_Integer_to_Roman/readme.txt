12_Integer_to_Roman


题目大意
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.

解决方案
罗马数字规则：https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97
左减的数字有限制，仅限于I、X、C。比如45不可以写成VL，只能是XLV
左减时不可跨越一个位值。

所以直接用递归的方式解就行了，有7+6==13种情况，每个地方要保留本身以及本身左减

样例


