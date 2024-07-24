#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

unordered_map<int, vector<int> > g;

vector<int> dfs(int v) {
    vector<int> discovered;
    stack<int> s;
    s.push(v);
    discovered.push_back(v);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        for (int neighbor : g[current]) {
            if (find(discovered.begin(), discovered.end(), neighbor) == discovered.end()) {
                discovered.push_back(neighbor);
                s.push(neighbor);
            }
        }
    }

    return discovered;
}

vector<int> bfs(int v) {
    vector<int> discovered;
    queue<int> q;
    q.push(v);
    discovered.push_back(v);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : g[current]) {
            if (find(discovered.begin(), discovered.end(), neighbor) == discovered.end()) {
                discovered.push_back(neighbor);
                q.push(neighbor);
            }
        }
    }

    return discovered;
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; ++i) {
        int key, value;
        cin >> key >> value;
        g[key].push_back(value);
        g[value].push_back(key);
    }

    // 각 정점의 리스트를 정렬
    for (auto& it : g) {
        sort(it.second.begin(), it.second.end());
    }

    // DFS 수행
    vector<int> dfs_result = dfs(v);
    for (int num : dfs_result) {
        cout << num << " ";
    }
    cout << endl;

    // BFS 수행
    vector<int> bfs_result = bfs(v);
    for (int num : bfs_result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
