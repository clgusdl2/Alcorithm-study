#include<iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;

int T, N, M, K, A, B;
int a[15]; // 접수 창구 시간
int b[15]; // 정비 창구 시간
int tk[1005]; // 사람 도착 시간
int tkvit[1005]; // 사람 현재 상황
int cnt; // 결과
vector<int> at[15]; // 해당 접수 창구에 들어간 사람
vector<int> bt[15]; // 해당 정비 창구에 들어간 사람
int avit[15]; // 접수 창구 사람 있는지 확인
int bvit[15]; // 정비 창구 사람 있는지 확인
int t; // 시간
int ab; // 완료된 사람 수


void init() {
	cnt = -1;
	ab = 0;
	t = 0;
	for (int i = 0; i < 15; i++) {
		avit[i] = -1;
		bvit[i] = -1;
		at[i].clear();
		bt[i].clear();
	}
	for (int i = 0; i < 1005; i++) {
		tkvit[i] = 0;
	}
}


void input() {
	cin >> N >> M >> K >> A >> B;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= K; i++) {
		cin >> tk[i];
	}
}


void solution() {
	queue<int> qa; // 접수 받을 사람
	queue<int> qa2[15]; // 접수 받고 있는 사람
	queue<int> qb; // 정비 받을 사람
	while (1) {
		if (ab == K) {
			break;
		}

		for (int i = 1; i <= N; i++) {
			if (avit[i] != -1)
				avit[i]++;
			if (avit[i] == a[i]) {
				avit[i] = -1;
				int abc = qa2[i].front();
				qa2[i].pop();
				qb.push(abc);
			}	
		}

		for (int i = 1; i <= M; i++) {
			if (bvit[i] != -1)
				bvit[i]++;
			if (bvit[i] == b[i]) {
				bvit[i] = -1;
				ab++;
			}
		}

		for (int i = 1; i <= K; i++) {
			if (tk[i] == t) {
				qa.push(i);
			}
		}

		if (!qa.empty()) {
			for (int i = 1; i <= N; i++) {
				if (avit[i] == -1) {
					int abc = qa.front();
					qa.pop();
					qa2[i].push(abc);
					avit[i] = 0;
					at[i].push_back(abc);
				}
				if (qa.empty()) {
					break;
				}
			}
		}

		if (!qb.empty()) {
			for (int i = 1; i <= M; i++) {
				if (bvit[i] == -1) {
					int abc = qb.front();
					qb.pop();
					bvit[i] = 0;
					bt[i].push_back(abc);
				}
				if (qb.empty()) {
					break;
				}
			}
		}

		t++;
	}

	int abcd = 0;
	int vit[1005] = { 0, };
	for (int i = 0; i < at[A].size(); i++) {
		for (int j = 0; j < bt[B].size(); j++) {
			if (at[A][i] == bt[B][j] && vit[at[A][i]] == 0) {
				vit[at[A][i]] = 1;
				abcd += at[A][i];
			}
		}
	}
	if (abcd != 0) {
		cnt = abcd;
	}
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