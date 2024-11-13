#include "Solution.h"
#include <stack>
#include <functional>

/// <summary>
/// ˵�����տ�ʼ����˫ָ�룬Ȼ����������Ų�̫�ԣ��͸ĳ�������dp����֪����û�и��õ�����
/// ʱ����O(n^2)���ո���O(n^2)
/// ������ս1��������Խ�ĳ�����ĸ߶�����m����dfs�е�ansһ���޸�Ϊans = (heights[i] == 0 || heights[j] == 0) ? 0 : (heights[i] + heights[j] + m) * (j - i);
/// ������ս2�����������Ϊ0ʱ��������㷨���Ѿ�����
/// /// </summary>
/// <param name="heights"></param>
/// <returns></returns>
float Solution::maxEnergyField(vector<int>& heights)
{
	int n = heights.size();

	//��¼����i�ұߵ�һ�������������
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

	//��¼����i��ߵ�һ�������������
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
