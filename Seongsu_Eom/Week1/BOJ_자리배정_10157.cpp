#include <iostream>

using namespace std;

int N, M, K, x, y, cnt = 0;
int sx, sy, ex, ey, mode = 0;

void so(int c) {
	if (c == K - 1) {
		return;
	}
	if (x == sx && mode == 0) {
		if (y < ey) {
			y++;
			return so(c + 1);
		}
		else {
			sx++;
			mode = 1;
			return so(c);
		}
	}
	else if (y == ey && mode == 1) {
		if (x < ex) {
			x++;
			return so(c + 1);
		}
		else {
			ey--;
			mode = 2;
			return so(c);
		}
	}
	else if (x == ex && mode == 2) {
		if (y > sy) {
			y--;
			return so(c + 1);
		}
		else {
			ex--;
			mode = 3;
			return so(c);
		}
	}
	else if (y == sy && mode == 3) {
		if (x > sx) {
			x--;
			return so(c + 1);
		}
		else {
			sy++;
			mode = 0;
			return so(c);
		}
	}


}

int main() {
	cin >> N >> M >> K;
	int c = 0;
	sx = 0;
	sy = 0;
	ex = N - 1;
	ey = M - 1;
	x = 0;
	y = 0;
	if (K > M * N) {
		cout << 0;
		return 0;
	}
	so(0);
	cout << x + 1<< " " << y + 1;
	return 0;
}