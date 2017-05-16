387_First_Unique_Character_in_a_String


题目大意
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
Note: You may assume the string contain only lowercase letters.



解决方案
直接遍历存储就是了，挺简单的。
one-time-attention
注意index是从0开始的，所以要写成
else if(a[s[i] - 'a'] >= 0) a[s[i] - 'a'] = -1;
if(a[i] >= 0) MIN = min(MIN, a[i]);
如果漏了等号就错了




样例
Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

