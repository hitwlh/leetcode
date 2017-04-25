234_Palindrome_Linked_List


题目大意
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

解决方案
对于O(1) space这点，卡在判断回文的想法上了。
回文除了逆序相等之外，另外的思路就是后一半的逆序和前一半相等。
所以先用fast slow指针找到middle，然后将右侧reverse，然后左侧、右侧比较是否相等

样例


