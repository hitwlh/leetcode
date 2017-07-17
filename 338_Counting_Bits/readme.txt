338_Counting_Bits


题目大意
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.




解决方案
这题的解决方案还是挺多的，只记录了最简洁的解法：
i&(i-1)可以把i的二进制里最右侧的1抹成0，那
ret[i] = ret[i&(i-1)]+1;
就行了



样例

Example:
For num = 5 you should return [0,1,1,2,1,2].


