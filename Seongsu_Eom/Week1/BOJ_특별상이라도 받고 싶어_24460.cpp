#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MAP[1050][1050];
int N;

int so(int n, int x, int y) {
    if (n >= 2) {
        int a[4];
        a[0] = so(n / 2, x, y);
        a[1] = so(n / 2, x + n / 2, y);
        a[2] = so(n / 2, x, y + n / 2);
        a[3] = so(n / 2, x + n / 2, y + n / 2);
        sort(a, a + 4);
        return a[1];
    }
    else return MAP[y][x];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }
    int a = so(N, 0, 0);
    cout << a;
    return 0;
}