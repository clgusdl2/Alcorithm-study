#include <iostream>
using namespace std;

int switchs[101] = {};
int N;

void change(int switchs[101], int p) {
	if (switchs[p]) switchs[p] = 0;
	else switchs[p] = 1;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> switchs[i];

	int s,sex,point;
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> sex;
		cin >> point;

		//남학생
		if (sex == 1) {
			for (int j = point; j <= N; j += point) change(switchs, j);

		}
		//여학생  0 0 1 0 1 1
		else if (sex == 2) {
			int count = 0;
			int left = point;
			int right = point;
			while (1) {
				if (left == 1 || right == N) break;
				if (switchs[left-1] != switchs[right+1]) break;
				left--;
				right++;
			}
			for (int j = left; j <= right; j++) change(switchs, j);
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << switchs[i];
		if (i % 20 == 0) cout << endl;
		else cout << " ";
	}
	return 0;
}