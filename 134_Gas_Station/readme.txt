134_Gas_Station


题目大意
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

解决方案
基本的思路是从头到尾遍历起点，然后从起点判断能否转一圈。有个优化就是如果从A点往前走，经过BCDE然后到不了F，那下次的起点直接选F+1就是了，因为BCDEF为起点肯定都是不能开到F+1的

但是写法有好几种
我的写法在solution1.cpp里，从头到尾选起点的代价是O(N),找到某起点后验证是否成功的代价也是O(N)，比如找到最后一个起点是最后一个车站，那验证这个车站的代价是O(N)，总的代价就是O(2N)。


http://www.cnblogs.com/felixfang/p/3814463.html
看solution2.cpp就会知道不需要O(2N)。假设我当前的起点是start，那只管往前走，如果走到了前头一个点走不下去，那就那个点后一个点作为起点，如果走到终点还是成功的，想一想这时的情况，从start往后是能够走到终点的，而start前面的油站，其实形成了一个个独立的“段”，每个段都是起点出发，到了终点，但是不能到下一个段。因此每个段的累加是负数，这时start到终点后剩余的油量，再从头开始走这些“段”，就是每过一个段油量减少，如果减到起点前油量不为负数，就说明可以绕一圈，而这个统计的油量其实就是所有油站的油量减去所有cost。所以solution2.cpp的代码十分简洁，20行都不到

样例


