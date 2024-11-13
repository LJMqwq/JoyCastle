#include "Solution.h"
#include <functional>
using namespace std;

/// <summary>
/// 时间复杂度：O(n)，空间复杂度：O(n)
/// 进阶挑战1：dfs新增一个维度，表示现有的钥匙数量，选择相邻宝箱时钥匙数减1。题目说只有一把钥匙，实际上随便来任意把均可
/// 进阶挑战2：本算法可以处理负数的分数，无须修改
/// </summary>
/// <param name="treasures"></param>
/// <returns></returns>
int Solution::maxTreasureValue(vector<int>& treasures)
{
	int n = treasures.size();
	vector<int>memo(n, -1);
	function<int(int)>dfs = [&](int i) {
		if (i < 0) {
			return 0;
		}

		int& ans = memo[i];
		if (ans != -1) {
			return ans;
		}

		ans = max(dfs(i - 1), dfs(i - 2) + treasures[i]);
		return ans;
	};
	return dfs(n - 1);
}
