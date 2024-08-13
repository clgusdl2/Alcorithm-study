#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M, cnt = 0;

int main() {
    cin >> N >> M;
    if (M == 0) {
        cout << 1;
        return 0;
    }
    if (N == 0) {
        cout << 0;
        return 0;
    }
    vector<vector<int>> t(N + 5, vector<int>(25, 0));
    for (int i = 0; i < M; i++) {
        int a, b, c = 0;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            t[b][c] = 1;
        }
        else if (a == 2) {
            cin >> b >> c;
            t[b][c] = 0;
        }
        else if (a == 3) {
            cin >> b;
            for (int i = 19; i >= 1; i--) {
                t[b][i + 1] = t[b][i];
            }
            t[b][1] = 0;
        }
        else {
            cin >> b;
            for (int i = 2; i <= 20; i++) {
                t[b][i - 1] = t[b][i];
            }
            t[b][20] = 0;
        }
    }
    vector<string> s;
    int check = 0;
    for (int i = 1; i <= N; i++) {
        string a = "";
        for (int j = 1; j <= 20; j++) {
            if (t[i][j] == 1) {
                a += to_string(j) + " ";
            }
        }
        if (a != "") {
            s.push_back(a);
        }
        else {
            check = 1;
        }
    }
    if (check == 1) {
        cnt++;
    }
    if (s.size() == 0) {
        cout << 1;
        return 0;
    }
    sort(s.begin(), s.end());
    cnt++;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i + 1])
            cnt++;
    }

    cout << cnt;

    
}