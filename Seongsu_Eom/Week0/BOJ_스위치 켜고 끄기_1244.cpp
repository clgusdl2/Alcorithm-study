#include<iostream>

using namespace std;

int N, M;
int n[101];

int main(int argc, char** argv)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }
    cin >> M;
    int a, b;
    for (int i = 0; i < M; i++) {

        cin >> a >> b;
        if (a == 1) {
            int c = 1;
            while (1) {
                if (b * c - 1 >= N) {
                    break;
                }
                n[b * c - 1] = (n[b * c - 1] == 0) ? 1 : 0;
                c++;
            }
        }
        else {
            int c = 1;
            b--;
            n[b] = (n[b] == 0) ? 1 : 0;
            while (1) {
                if (c == b + 1) {
                    break;
                }
                if (c == N - b) {
                    break;
                }

                if (n[b + c] == n[b - c]) {
                    n[b + c] = (n[b + c] == 0) ? 1 : 0;
                    n[b - c] = (n[b - c] == 0) ? 1 : 0;
                    c++;
                }
                else {
                    break;
                }
            }
        }
    }
    int c = 0;
    for (int i = 0; i < N; i++) {
        cout << n[i];
        c++;
        if (c % 20 == 0) {
            cout << endl;
        }
        else cout << " ";
    }



    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}