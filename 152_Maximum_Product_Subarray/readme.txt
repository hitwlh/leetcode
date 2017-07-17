152_Maximum_Product_Subarray


题目大意
Find the contiguous subarray within an array (containing at least one number) which has the largest product.


解决方案
明显是动态规划。定义三个数组MAX、H_MAX、H_MIN
MAX[i]表示i, i+1, ..., n的最优解
H_MAX[i]表示连乘时以nums[i]为起点的最大连乘积
H_MIN[i]表示连乘时以nums[i]为起点的最小连乘积

初始化
MAX[n-1] = H_MAX[n-1] = H_MIN[n-1] = nums[n-1];
而后

若nums[i] < 0，
H_MAX[i] = max(nums[i], nums[i] * H_MIN[i+1]);
H_MIN[i] = min(nums[i], nums[i] * H_MAX[i+1]);

若nums[i] >= 0，
H_MAX[i] = max(nums[i], nums[i] * H_MAX[i+1]);
H_MIN[i] = min(nums[i], nums[i] * H_MIN[i+1]);

MAX[i] = max(H_MAX[i], MAX[i+1]);

样例
For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

