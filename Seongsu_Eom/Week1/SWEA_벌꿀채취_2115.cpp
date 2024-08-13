#include<iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;

int T, N, M, C;
int MAP[15][15];
int MAP2[15][15];
int MAP3[15][15];
int vit[15][15];
int vit2[15][15];
int mx, mx2;



void init() {
	mx = 0;
	mx2 = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			MAP2[i][j] = 0;
			vit[i][j] = 0;
			vit2[i][j] = 0;
		}
	}
}

void input() {
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
}

void dfs(int c, int d, int y, int x, int cnt) {
	if (cnt == M) {
		if (c <= C && d > MAP2[y][x]) {
			MAP2[y][x] = d;
		}
		return;
	}

	for (int i = 0; i < M; i++) {
		if (x + i >= N) break;
		if (vit[y][x + i] == 1) continue;
		if (c + MAP[y][x + i] > C) {
			if (MAP2[y][x] < d)
				MAP2[y][x] = d;
		}
		else {
			vit[y][x + i] = 1;
			int a = MAP[y][x + i];
			dfs(c + a, d + a * a, y, x, cnt + 1);
			vit[y][x + i] = 0;
		}
	}

	if (c <= C) {
		if (MAP2[y][x] < d)
			MAP2[y][x] = d;
	}
}

void dfs2(int d, int y, int x, vector<pair<int,int>> v) {
	if (d == mx) {
		for (int i = 0; i < v.size(); i++) {
			int a = v[i].first;
			int b = v[i].second;
			vit2[a][b] = 1;
		}
		return;
	}
	if (d > mx)
		return;

	for (int i = 0; i < M; i++) {
		vit[y][x + i] = 1;
		v.push_back({ y,x + i });
		int a = MAP[y][x + i];
		dfs2(d + a * a, y, x, v);
		v.pop_back();
		vit[y][x + i] = 0;
	}
}


void solution() {
	int a[2];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			dfs(0, 0, i, j, 0);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			if (mx < MAP2[i][j]) {
				mx = MAP2[i][j];
				a[0] = i;
				a[1] = j;
			}
		}
	}

	for (int i = a[1] - M + 1; i < a[1] + M; i++) {
		if (i < 0 || i >= N) continue;
		MAP2[a[0]][i] = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			if (mx2 < MAP2[i][j]) {
				mx2 = MAP2[i][j];
			}
		}
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solution();
		cout << "#" << tc << " " << mx + mx2 << endl;
	}
}