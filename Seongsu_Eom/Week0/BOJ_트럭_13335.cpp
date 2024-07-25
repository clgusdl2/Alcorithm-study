#include<iostream>

using namespace std;

int n ,w, L , b, cnt;
int m[1001];
int t[1000000];

int main(int argc, char** argv)
{
    cin >> n >> w >> L;
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    int b = 0;
    for (int i = 0; i < n; i++) {
        if (t[b] + m[i] <= L) {
            for (int j = b; j < b + w; j++) {
                t[j] += m[i];
            }
        }
        else {
            i--;
        }
        b++;
    }

    cout << b + w;

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}