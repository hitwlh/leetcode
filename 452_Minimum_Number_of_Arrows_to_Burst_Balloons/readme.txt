452_Minimum_Number_of_Arrows_to_Burst_Balloons


题目大意
There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.
An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.




解决方案
贪心方案，先sort一遍，然后从左到右显然第一个气球需要一只箭射破，那这枝箭应该射破尽可能多气球。要射破尽可能多，这就是one-time-attention了，一开始写错了
从左往右看一串，显然是i+1.first <= i.second(也就是说后面的气球的起点要小于前面气球的终点)
但是这样错了，看
[[10,16], [2,8], [1,6], [7,12]]
排完序是[[1,6], [2,8], [7,12], [10,16]]
[1,6], [2,8]是可以一箭射破的但是如果简单的i+1.first <= i.second，那就是7 <= 8，第三个气球也破了，事实是这只代表2、3可以一起破，而不是1、2、3一起破，因此应该是找到当前最小的终点，去比较，见下面的代码
min_end = points[i].second;
while(i+1 < points.size() && points[i+1].first <= min_end){
                i++;
                min_end = min(min_end, points[i].second);
}




样例
Example:
Input:
[[10,16], [2,8], [1,6], [7,12]]
Output:
2
Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).

