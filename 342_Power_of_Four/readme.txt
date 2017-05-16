342_Power_of_Four


题目大意
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
Follow up: Could you solve it without loops/recursion?


解决方案
231. Power of Two要判断是否是2的次幂，是2的次幂意味着这个数字的二进制形式里只有1个1(不是正负位上的)，num & (num-1)) == 0就能做到这一点
而要是4的次幂，等价于有一个1且1在奇数位置上，所以先用num & (num-1)) == 0确定只有1个1。然后用(0x55555555 & num) == num确定1在奇数位置上

样例
Example:
Given num = 16, return true. Given num = 5, return false.

