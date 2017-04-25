445_Add_Two_Numbers_II


题目大意
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

解决方案
先reverse两个输入，然后相加，再把相加的结果reverse
one-time-attention:
有可能5+5进位，这样两个list都空，但是进位仍不空，因此要把对acc的处理放到最后


更进一步的思考，
一开始很自然地想到了用递归来做，但是一定要想清楚内在的逻辑，事实上如果用递归做，
if(l1->next && l2->next)满足的时候，不知道哪个队列长，那么l1和l2的结点如何做加法？没法做，除非用一些表示来递归表示哪个更长，太麻烦了

更自然的做法是找到最高位对齐的，做加法，这个挺容易的，就是reverse然后做加法，solution1.cpp
如果不reverse，我的做法是在主函数把长的串分为两部分，一部分是多出来的高位，一部分是和短的串对齐
然后对齐的串用递归的方法进行加法，并保留最高位进位
对多出来的高位做加法。然后把结果串起来，solution2.cpp

样例


