#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        long long sum = 0;
        cin >> N;
        vector<long long> M(N);
        vector<long long> DAT(1000001, -1);
        for (int i = 0; i < N; i++) {
            cin >> M[i];
            DAT[M[i]] = i;
        }
        int a = 0;
        for (long long i = 1000000; i >= 1; i--) {
            if (DAT[i] == -1) continue;
            if (a > DAT[i]) continue;
            for (int j = a; j <= DAT[i]; j++) {
                sum = sum + i - M[j];
            }
            a = DAT[i] + 1;
        }

        cout << sum << endl;

    }
}