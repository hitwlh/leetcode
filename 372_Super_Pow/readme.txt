372_Super_Pow


题目大意
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.



解决方案
题目翻译：求a^b%1337
参考
http://www.doc88.com/p-5836182437827.html
http://www.infocool.net/kb/Other/201611/217955.html

http://www.cnblogs.com/micrari/p/5739769.html

要明白性质: (a*b)%c = (a%c)*(b%c)%c
因此
实现mypow(a, b)计算a^b % 1337，其中b是个位数
在主函数里把b的最后一位拿去做mypow(a, b)，然后对剩余的b反复递归处理。具体代码见solution.cpp，很好懂。
时间复杂度是sum(b)，b的每位数字<=9所以，复杂度也就是O(9n)。


前两个参考链接里详细讲了快速幂乘算法，其实就是把a^b分解成a^(b/2) * a^(b/2) * a^(b%2)。这样就把问题规模一直在减半。
但是这里有个问题就是b是一个数组，它/2是O(n)的，因此尽管快速幂乘能实现O(lgn)，第二个链接最后给的代码还是行不通的，压根不是O(lgn)。

第三个链接也没有给出O(lgn)，但是看它的代码应该是给了O(1n)的，里面提到了“欧拉函数来降指数”，先对b数组处理，处理成了一个int数字，这个蛮有意思的，但是总的时间复杂度没有理论提升，我也懒得再看了。以后想看可以看这个。


样例
Example1:
a = 2
b = [3]
Result: 8

Example2:
a = 2
b = [1,0]
Result: 1024

