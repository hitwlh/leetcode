405_Convert_a_Number_to_Hexadecimal


题目大意
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.

解决方案
挺容易的。就是区分下情况。0，正数的很好实现。负数的首先需要明白int的负数怎么表示：
比如-100，用int表示就是(-2^31) + (2^31 - 100)
因此正数部分是(2^31 - 100)，应该写成(2^30 - 100 + 2^30)
正数部分可以直接调用正数的实现。然后如果正数部分的返回最高位没到负数的那个byte，那直接往左边填充"8000..."
如果到了，那就
if(s1[0] <= '1') s1[0] = s1[0] + 8;
else s1[0] = s1[0] - '2' + 'a';


one-time-attention
num = (1 << 30) + num + (1 << 30);必须加括号

样例
Example 1:
Input:
26
Output:
"1a"

Example 2:
Input:
-1
Output:
"ffffffff"

