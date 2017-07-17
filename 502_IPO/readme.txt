502_IPO


题目大意
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given several projects. For each project i, it has a pure profit Pi and a minimum capital of Ci is needed to start the corresponding project. Initially, you have W capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

To sum up, pick a list of at most k distinct projects from given projects to maximize your final capital, and output your final maximized capital.





解决方案
参考https://discuss.leetcode.com/topic/78574/8-liner-c-42ms-beat-98-greedy-algorithm-detailed-explanation
翻译：初始金额为W，如果金额大于Capital[i]，就可以从事Capital[i]并且获得Profits[i]，最多可做k次
这题总想法非常简单，就是不停贪心就是了。但是具体怎么写呢？一开始的版本是每次遍历整个capital，查找可以没用过且可以用的里收益最大的，这样总的开销就是O(k*n)，n=capital.size()
正确的思路：用一个大根堆profits存储Profits[i]，小根堆capital存储(Capital[i], Profits[i])。
一开始把能用的project扔到大根堆里，不能用的扔到小根堆里。然后从大根堆挑出最大的用，更新W，再根据新的W把小根堆里的项目把能用的的收益放到小根堆里。这样的最坏开销所有大根堆里的都要放到小根堆里去，这样的开销是O(nlgn)
代码不难写，关键是一些stl的运用还得看看(自定义优先队列)。




样例
Example 1:
Input: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].

Output: 4

Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.

