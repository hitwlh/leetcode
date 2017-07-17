503_Next_Greater_Element_II


题目大意
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Note: The length of given array won't exceed 10000.





解决方案
496的进阶，那题只需要找到一个元素后面第一个比它大的元素
这题需要“循环顺序”，如果找到最后还是没有，那头开始找起(绕一圈)。
先把整个vector压到栈里，然后从最后一个元素开始找后面比它大的元素，剩余的处理方法和496就一样了。



样例

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
