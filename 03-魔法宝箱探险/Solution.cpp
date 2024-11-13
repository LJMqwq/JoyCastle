#include "Solution.h"
#include <functional>
using namespace std;

/// <summary>
/// ʱ�临�Ӷȣ�O(n)���ռ临�Ӷȣ�O(n)
/// ������ս1��dfs����һ��ά�ȣ���ʾ���е�Կ��������ѡ�����ڱ���ʱԿ������1����Ŀ˵ֻ��һ��Կ�ף�ʵ�������������Ѿ���
/// ������ս2�����㷨���Դ������ķ����������޸�
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
