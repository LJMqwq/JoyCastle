#include "Solution.h"

/// <summary>
/// ʱ�临�Ӷȣ�O(m+n)���ռ临�Ӷȣ�O(1)
/// ������ս1���ɿ����öԶ���ģ�⣺����һ������Ѵ洢��С����������һ��С���Ѵ洢�ϴ��������ʹ�����ѵĴ�С֮��<=1
/// ������ս2����С���Ѵ洢k���������С������ÿ�ε�����ֵ��С���������ٽ��������������һ����������С����
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
