278_First_Bad_Version


题目大意
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

解决方案
题目翻译： 就是[1, 2, ..., n]，左边全是0，右边全是1，找到第一个1的下标


显然是二分，我的做法在solution1.cpp，网上的做法是solution2.cpp，网上的写得很好
注意这里求中点必须用left+(right-left)/2 ；(left+right)/2会溢出
样例


