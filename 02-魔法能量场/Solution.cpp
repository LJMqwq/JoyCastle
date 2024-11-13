#include "Solution.h"
#include <stack>
#include <functional>

/// <summary>
/// 说明：刚开始想用双指针，然后想了想觉着不太对，就改成了区间dp，不知道有没有更好的做法
/// 时复：O(n^2)，空复：O(n^2)
/// 进阶挑战1：假设可以将某个塔的高度增加m，则将dfs中的ans一行修改为ans = (heights[i] == 0 || heights[j] == 0) ? 0 : (heights[i] + heights[j] + m) * (j - i);
/// 进阶挑战2：单独处理高为0时的情况，算法中已经处理
/// /// </summary>
/// <param name="heights"></param>
/// <returns></returns>
float Solution::maxEnergyField(vector<int>& heights)
{
	int n = heights.size();

	//记录索引i右边第一个比它大的索引
	vector<int>right(n, n);
	stack<int>st;

	for (int i = 0; i < n; i++)
	{
		int& x = heights[i];
		while (!st.empty() && x > heights[st.top()]) {
			int j = st.top();
			st.pop();
			right[j] = i;
		}
		st.push(i);
	}

	while (!st.empty())
	{
		st.pop();
	}

	//记录索引i左边第一个比它大的索引
	vector<int>left(n, -1);
	for (int i = n - 1; i >= 0; i--)
	{
		int& x = heights[i];
		while (!st.empty() && x > heights[st.top()])
		{
			int j = st.top();
			st.pop();
			left[j] = i;
		}

		st.push(i);
	}

	vector<vector<int>>memo(n, vector<int>(n, -1));
	function<int(int, int)>dfs = [&](int i, int j) {
		if (i >= j) {
			return 0;
		}

		int& ans = memo[i][j];
		if (ans != -1) {
			return ans;
		}

		ans = (heights[i] == 0 || heights[j] == 0) ? 0 : (heights[i] + heights[j]) * (j - i);
		ans = max({ ans,dfs(right[i],j),dfs(i,left[j]) });
		return ans;
	};

	return dfs(0, n - 1) * 0.5f;
}
