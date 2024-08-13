#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;


int T, N, M, K;
int MAP[500][500];
priority_queue<tuple<int, int, int>> q;
vector<tuple<int, int, int, int>> v;
int ydir[4] = { -1,1,0,0 };
int xdir[4] = { 0,0,-1,1 };
int cnt, ac, dc;

void init() {
	memset(MAP, 0, sizeof(MAP));
	while (!q.empty())
		q.pop();
	cnt = 0;
	ac = 0;
	dc = 0;
	v.clear();
}

void input() {
	cin >> N >> M >> K;
	for (int i = 160; i < 160 + N; i++) {
		for (int j = 160; j < 160 + M; j++) {
			int a;
			cin >> a;
			if (a != 0) {
				ac++;
				v.push_back({ a,i,j,a });
				MAP[i][j] = 1;
			}
		}
	}
}


void solution() {
	int day = 0;
	while (day < K) {
		day++;

		int da = v.size();
		for (int i = 0; i < da; i++) {
			if (get<0>(v[i]) == 0) continue;
			get<3>(v[i])--;
			int d = get<3>(v[i]);
			int p = get<0>(v[i]);
			if (d == -1) {
				int y = get<1>(v[i]);
				int x = get<2>(v[i]);
				q.push({ p,y,x });
			}
			if (p == -d) {
				dc++;
				get<0>(v[i]) = 0;
				continue;
			}
		}
		while (!q.empty()) {
			int p = get<0>(q.top());
			int y = get<1>(q.top());
			int x = get<2>(q.top());
			q.pop();
			for (int j = 0; j < 4; j++) {
				int dy = y + ydir[j];
				int dx = x + xdir[j];

				if (MAP[dy][dx] == 1 || dy < 0 || dx < 0 || dy >= 500 || dx >= 500) continue;
				MAP[dy][dx] = 1;
				ac++;
				v.push_back({ p,dy,dx,p });
			}
		}
	}
	cnt = ac - dc;
}


int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solution();
		cout << "#" << tc << " " << cnt << endl;
	}

}