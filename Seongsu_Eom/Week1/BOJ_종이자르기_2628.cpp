#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;


int main() {
	cin >> N >> M >> K;
	vector<pair<int, int>> MAP(K);
	int c[2] = { 0, };
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		c[a]++;
		MAP[i] = { a,b };
	}
	sort(MAP.begin(), MAP.end());

	int x = 0, y = 0, a = 0;
	for (int i = 0; i < c[0]; i++) {
		int b = MAP[i].second - a;
		if (b > x)
			x = b;
		a = MAP[i].second;
	}
	if (x < M - a)
		x = M - a;

	a = 0;
	for (int i = c[0]; i < c[0] + c[1]; i++) {
		int b = MAP[i].second - a;
		if (b > y)
			y = b;
		a = MAP[i].second;
	}
	if (y < N - a)
		y = N - a;
	cout << x * y;

	return 0;
}