154_Find_Minimum_in_Rotated_Sorted_Array_II


题目大意
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
The array may contain duplicates.


解决方案
这几题一起联合看
33 Search in Rotated Sorted Array
81  Search in Rotated Sorted Array II   
153 Find Minimum in Rotated Sorted Array 
154 Find Minimum in Rotated Sorted Array II  

观察到这种数组的特点，这类题就会变得非常好解。
在153题中，
一个区间内，如果左端比右端小，那这个区间就一定是递增的，而且如果把整个区间分为2半

但是在这题中，有了变化，因为元素可以重复了，因此左端和右端出了某一个更大之外，还有可能相等。
对于一个区间[left, right]，如果左端右端更大，那这个区间一定是递增的，很好做。
如果相等，有两种可能，一个是这个区间是常数，一个是这个区间是rotated的，并且右边最大值与左边最小值相等。由于无法确认是哪种情况，因此记录下当前的left(right)值，然后让left往右移动1或者让right往左移动1


样例


