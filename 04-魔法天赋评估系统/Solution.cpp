#include "Solution.h"

/// <summary>
/// 时间复杂度：O(m+n)，空间复杂度：O(1)
/// 进阶挑战1：可考虑用对顶堆模拟：定义一个大根堆存储较小的数，定义一个小根堆存储较大的数，并使两个堆的大小之差<=1
/// 进阶挑战2：用小根堆存储k个数组的最小索引，每次弹出数值最小的索引，再将其所在数组的下一个索引加入小根堆
/// </summary>
/// <param name="fireAbility"></param>
/// <param name="iceAbility"></param>
/// <returns></returns>
double Solution::FindMedianTalentIndex(vector<int>& fireAbility, vector<int>& iceAbility)
{
	int m = fireAbility.size();
	int n = iceAbility.size();

	int ans = 0;
	int i = 0, j = 0;
	while (i < m && j < n && (i + j) * 2 <= m + n)
	{
		if ((i + j + 1) * 2 >= m + n) {
			ans += min(fireAbility[i], iceAbility[j]);
		}

		if (fireAbility[i] < iceAbility[j]) {
			i++;
		}
		else {
			j++;
		}
	}

	for (; i < m && (i + j) * 2 <= m + n; i++)
	{
		if ((i + j + 1) * 2 >= m + n) {
			ans += fireAbility[i];
		}
	}

	for (; j < n && (i + j) * 2 <= m + n; j++)
	{
		if ((i + j + 1) * 2 >= m + n) {
			ans += iceAbility[j];
		}
	}

	return (m + n) % 2 != 0 ? ans : ans * 0.5;
}
