#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

/*
보석 총N개

보석 정보 : 무게 M ,가격 V

가방에 담을 수 있는 무게 Ci


*/

int N, K; //보석과 가방의 개수
int M, V;//보석의 정보 수
int C; //가방에 담을 수 있는 무게

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
			pq.push(gems[gidx].second); // 가치를 비교하기위해
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
	}// 가방 1개 담을것 중 가장 가치가 높은걸 담는다.
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