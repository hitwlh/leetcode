137_Single_Number_II


题目大意
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.



解决方案
考虑每个元素的为一个32位的二进制数，这样每一位上出现要么为1 ，要么为0。对数组，统计每一位上1 出现的次数count，必定是3N或者3N+1 次。让count对3取模，能够获得到那个只出现1次的元素该位是0还是1。

样例


