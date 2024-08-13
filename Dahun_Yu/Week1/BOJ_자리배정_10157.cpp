#include <iostream>
using namespace std;

int main(){

    int C,R;
    cin >> C >> R;
    int K;
    cin >> K;

    //시작점
    int x = 1;
    int y = 1;

    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    int direction = 0;

    int visited[1001][1001] = {};
    visited[1][1] = 1;

    if(K>C*R) cout  << 0;
    else{
        for(int i=0;i<K-1;i++){
            int nx = x+dx[direction%4];
            int ny = y+dy[direction%4];
            if(1>nx || C<nx || 1>ny || R<ny || visited[nx][ny]) direction+=1;
            x = x+dx[direction%4];
            y = y+dy[direction%4];
            visited[x][y] = 1;
        }
        cout << x << " " << y;
    }
    return 0;
}