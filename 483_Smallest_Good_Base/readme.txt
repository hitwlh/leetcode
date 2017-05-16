483_Smallest_Good_Base


题目大意
For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.
Now given a string representing n, you should return the smallest good base of n in string format. 

Note:
The range of n is [3, 10^18].
The string representing n is always valid and will not have leading zeros.





解决方案
题意：对给定的n，求k进制，满足k进制下n的表示为111...1，找到最小的k。
参考http://chuansong.me/n/1663389652129

假设1...1里共有(m+1)个1，则m越大，k就越小，所以是要找满足条件的最大m。
因为k至少为2，所以m最大就是log(num + 1) / log(2)，因此m从[log(num + 1) / log(2), 2]顺序遍历

1. 当m定下来的时候，怎么找k呢？
n  = 1 + k^1 + k^2 + k^3 + ... + k^m
n > k ^ m  （1）

另外，由二项式公式(a＋b)^n＝...
把k代入a，1代入b，m代入n，得到(k+1)^m的展开式，这个展开式>=1 + k^1 + k^2 + k^3 + ... + k^m，m==1时等号成立
因此(k+1)^m >= n （2）

由这两个不等式得到k属于[n^(1/m)-1, n^(1/m))，如果n^(1/m)是整数，则k = n^(1/m)-1，否则k = n^(1/m)取下整
所以知道m之后k只有一个备选答案，验证一下是否满足num在k进制下的表示为111..1，如果是就可以返回k了，否则就是失败

这种解法记录在solution1.cpp里

2. 只用不等式(1)，即 k < n^(1/m)， 且k >= 2;
然后从2到 n^(1/m)(这个式子为分数时，去下整。为整数时，-1)做二分搜索。挺容易的。
这种解法记录在solution2.cpp里

one-time-attention
这题搞清楚这点数学关系之后就很好懂了，但是写c++代码很麻烦，以下几个注意点：
solution1.cpp
1. 不要用atoi，而是用atoll
2. 不要用int，全部用 long long
3. pow函数的第二个参数，如果用double精度是不满足的，long long k = pow(n, (long double)1 / m);发现在m等于1的时候，本来应该返回n的，但是因为double的1有精度问题，当n接近long long的上限时，能造成好几十的误差
4. pow(a, b)，当a和b都是整数时，反倒可能靠不住。自己用while实现类似效果
    a. 用等比公式的计算，会溢出成负数，将等比公式的分母乘到num那边去，num也会溢出成负数。但是最后仍然相等，比较相等操作是可靠的
    b. 用while累加的方法算，不会溢出。
    a和b都记录在solution1.cpp里了

solution2.cpp
在20-22行是为了比较哪个更大，但是注意不能直接用long long，因为二分的时候二分点会溢出，而且连乘溢出成负数了还不停地做乘法是无意义的。所以用一个long double 来做连除，做到除成小数就说明大小关系了。


这题关键是数学关系和溢出等等的判断，二分什么很容易写。如果用python写，精度很好实现，会很容易写。


样例

Example 1:
Input: "13"
Output: "3"
Explanation: 13 base 3 is 111.
Example 2:
Input: "4681"
Output: "8"
Explanation: 4681 base 8 is 11111.
Example 3:
Input: "1000000000000000000"
Output: "999999999999999999"
Explanation: 1000000000000000000 base 999999999999999999 is 11.
