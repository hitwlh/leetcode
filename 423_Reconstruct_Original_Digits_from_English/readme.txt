423_Reconstruct_Original_Digits_from_English


题目大意
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.

给了我们一串英文字符串，是由表示数字的英文单词组成的，不过字符顺序是打乱的，让我们重建出数字。

解决方案
zero
one
two
three
four
five
six
seven
eight
nine
0、2、4、6、8都有单一字符，用这些先求出0、2、4、6、8
然后再求1、3、5、7、9




样例

Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"

