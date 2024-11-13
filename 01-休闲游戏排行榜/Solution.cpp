#include "Solution.h"
#include <queue>
using namespace std;

/// <summary>
/// ʱ�临�Ӷȣ�nlog(m)��nΪscore�ĳ���
/// ����˼����û���Ż���
/// </summary>
/// <param name="score"></param>
/// <param name="m"></param>
/// <returns></returns>
vector<int> Solution::getTopScores(vector<int>& score, int m)
{
	//С����
	priority_queue<int, vector<int>, greater<>>pq;
	for (int& x : score) {
		if (pq.size() < m) {
			pq.push(x);
		}
		else {
			if (x > pq.top()) {
				pq.pop();
				pq.push(x);
			}
		}
	}

	vector<int>ans;
	while (!pq.empty())
	{
		int x = pq.top();
		pq.pop();
		ans.emplace_back(x);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
