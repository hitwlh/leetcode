354_Russian_Doll_Envelopes


题目大意
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)




解决方案
翻译：就是一堆信封，要求最多可以将多少信封套在一起

solution1
先对信封从小到大排序，然后从左到右确定某封信封作为最外层信封的时候能装多少信封(这个信封右侧的信封显然是不能装进来的，右侧的pair.first要 比它大)，结果记作num[i]。当要计算num[i]时，需要对信封i前面所有信封遍历一遍，找到那些能装进i里头去的(备选的可能不止一封)，然后对这些num，找最大的装进envelopes[i]里，时间复杂度是O(n^2)
one-time-attention
1. 要从i-1往前找到0，找到最能装的信封。看第11行代码(别以为最能装的信封就是i-1，因为i-1的第二维可能很小，导致i-1压根装不了别人)
2. 最后要返回所有信封里最能装的。看第17行代码(需要遍历一遍，不要以为最能装的就是最后一个信封，原因同上)


solution2
参照300题进行优化


样例
Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).



