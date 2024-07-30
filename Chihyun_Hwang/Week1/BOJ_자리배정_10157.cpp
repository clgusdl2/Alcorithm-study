#include <iostream>

using namespace std;


int maps[1001][1001];

int testm[3][3];
// 위 오 아 왼

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int c, r;

int k;

void print()
{
	for (int i = 0; i < r+1; i++)
	{
		for (int j = 0; j < c+1; j++)
		{
			cout << maps[i][j] << " ";
		}
		cout << '\n';
	}

}

int main()
{

	cin >> c >> r; // r/c
	cin >> k; // 등수

	if (k > r * c) // 맵크기보다 큰 경우
	{
		cout<< "0";
		return 0;
	}

	int cnt = 1;
	int x = 0;
	int y = 0;
	int dir = 0;
	
	int nx = 0;
	int ny = 0;

	while (1)
	{
		if (cnt == k)
		{
			break;
		}

		if (cnt > r * c)
		{
			break;
		}
		maps[x][y] =cnt;
		nx = x+ dx[dir];
		ny = y+ dy[dir];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c || maps[nx][ny] != 0)
		{
			dir = (dir + 1) % 4;
			continue;
		}

		x = nx;
		y = ny;
		cnt++;
		//print();
	}

	cout << ny+1 <<" " << nx+1;

	return 0;
}