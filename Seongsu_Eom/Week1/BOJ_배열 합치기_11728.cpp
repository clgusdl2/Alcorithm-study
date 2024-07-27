#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;

    // 시간초과 방지
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(M);
    vector<int> C(N + M);

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];

    int a = 0, b = 0, c = 0;

    while (a < N && b < M) {
        if (A[a] <= B[b]) {
            C[c++] = A[a++];
        }
        else {
            C[c++] = B[b++];
        }
    }

    while (a < N) {
        C[c++] = A[a++];
    }

    while (b < M) {
        C[c++] = B[b++];
    }

    for (int i = 0; i < N + M; i++)
        cout << C[i] << " ";

    return 0;
}
