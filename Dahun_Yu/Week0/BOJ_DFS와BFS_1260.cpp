#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& g, int st, vector<bool>& visited) {
    visited[st] = true;
    cout << st << " ";
    for (auto i : g[st]) {
        if (!visited[i]) {
            dfs(g, i, visited);
        }
    }
}

void bfs(vector<vector<int>>& g, int st, vector<bool>& visited) {
    queue<int> q;
    q.push(st);
    visited[st] = true;

    while (!q.empty()) {
        int start = q.front();
        cout << start << " ";
        q.pop();

        for (auto next : g[start]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;
    vector<vector<int>> g(N + 1);


    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        sort(g[i].begin(), g[i].end());
    }


    vector<bool> visited1(N + 1,false);
	dfs(g,V, visited1);
    cout << endl;
    vector<bool> visited2(N + 1, false);
	bfs(g,V,visited2);

	return 0;
}