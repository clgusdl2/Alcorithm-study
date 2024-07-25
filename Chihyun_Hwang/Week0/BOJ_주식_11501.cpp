#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<long long>v;
void input()
{

	cin >> n;

	for (int j = 0; j < n; j++)
	{
		long long a;
		cin >> a;
		v.push_back(a);
	}
}

long long solve()
{

	int maxv = 0;
	long long ans = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] > maxv)
		{
			maxv = v[i];
		}
		else
		{
			ans += maxv - v[i];
		}
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		v.clear();
		input();
		long long ans = solve();
		cout << ans << endl;

	}


}