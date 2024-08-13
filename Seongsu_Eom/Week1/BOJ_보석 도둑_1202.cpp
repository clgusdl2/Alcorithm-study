#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
long long sum = 0;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> MV;
priority_queue<long long, vector<long long>, greater<long long>> C;
priority_queue<long long> co;

void init() {
    sum = 0;
}

void input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        long long w, v;
        cin >> w >> v;
        MV.push({ w, v });
    }
    for (int i = 0; i < K; i++) {
        long long b;
        cin >> b;
        C.push(b);
    }
}

void solution() {
    while (!C.empty()) {
        long long bag = C.top();
        C.pop();
        while (!MV.empty() && MV.top().first <= bag) {
            co.push(MV.top().second);
            MV.pop();
        }
        if (!co.empty()) {
            sum += co.top();
            co.pop();
        }
    }
}

int main() {
    init();
    input();
    solution();
    cout << sum << endl;
    return 0;
}