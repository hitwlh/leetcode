406_Queue_Reconstruction_by_Height


题目大意
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
Note:
The number of people is less than 1,100.

解决方案
肯定是先sort一下
1. 我想到的解法是先准备好整个队列的空位，然后从矮的排起，这样排到某一个人的时候，他前面所有空位的人都比他高或跟他等高，这样就知道他应该往那里排了，但是这里有一个one-time-attention，那就是加入身高为7的人有2个，第一个人占了一个空位，第二个人再去找位置时，就无法从前面的空位判断出前面有一个人跟他一样高，因此还要有一个same用来标识前面有多少人跟他一样高，然后从头到尾遍历空位就是比他更高的，合起来就是比他高及等高的，这样才对。代码在solution1.cpp

2.第二种策略是向各自高的人里头去插入，因为插入个子矮的人不会对个子高的人造成影响，因此先对最高的几个人站个队，然后次高的依次插入。因为插入的时候知道自己的位置，而且后插入的人要么更矮，要么等高，而等高的人只能插入到自己后面，所以插入的时候事实上就知道了正确的位置了。这个代码参考网上写的，比较容易实现，solution2.cpp

样例
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

