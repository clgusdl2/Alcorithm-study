#include <iostream>
#include <string.h>

using namespace std;

int N;
int M[1005][3];
int M2[1005][3];
int c;

void init() {
	memset(M2, 0, sizeof(M2));
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> M[i][j];
			M2[i][j] = M[i][j];
			if (i > 0) {
				M2[i][j] += min(M2[i - 1][(j + 1) % 3], M2[i - 1][(j + 2) % 3]);
			}
		}
		
	}
}

void solution() {
	
	c = min(M2[N - 1][0], min(M2[N - 1][1], M2[N - 1][2]));

}


int main() {
	init();
	input();
	solution();
	cout << c;
}