#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

/*
���� ��N��

���� ���� : ���� M ,���� V

���濡 ���� �� �ִ� ���� Ci


*/

int N, K; //������ ������ ����
int M, V;//������ ���� ��
int C; //���濡 ���� �� �ִ� ����

vector<pair<int, int>>gems;
vector<int>backpack;


priority_queue<int>pq;
int gidx = 0;
int greedy(int idx)
{

	//cout << gems.size() << endl;
	//cout << backpack.size() << endl;

	while (gidx < N && gems[gidx].first <= backpack[idx])
	{
			pq.push(gems[gidx].second); // ��ġ�� ���ϱ�����
			gidx++;
	}

	if (pq.empty())
	{
		return 0;
	}
	else
	{
		int res = pq.top(); pq.pop();
		//cout << res << endl;
		return res;

	}
	
	
}

void play()
{
	sort(gems.begin(), gems.end());
	sort(backpack.begin(), backpack.end());
	long long ans = 0;
	for (int i = 0; i < K; i++)
	{
		ans += greedy(i);
	}// ���� 1�� ������ �� ���� ��ġ�� ������ ��´�.
	cout << ans;
	return; 
}


int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int m, v;
		cin >> m >> v;
		gems.push_back({ m,v });
	}
	
	for (int i = 0; i < K; i++)
	{
		cin >> C;
		backpack.push_back(C);
	}
	play();




}