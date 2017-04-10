136_Single_Number


题目大意
Given an array of integers, every element appears twice except for one. Find that single one.

解决方案
注意异或运算满足交换律以及结合律，并且a ^ a == 0     a ^ 0 == a  
所以直接对全部进行异或就ok了

样例


