#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int maps[1000][1000];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N, M,K;
int ans;
typedef struct CELL
{
	int x;
	int y;
	int t;
	int life;
};

struct cmpC {
	bool operator()(CELL a, CELL b)
	{
		return a.life < b.life;
	}
};

vector<CELL>cells;
priority_queue <CELL, vector<CELL>, cmpC>pq;


#define centerSZ 175
#define centerSZ 175





void init()
{
	memset(maps, 0, sizeof(maps));
	cells.clear();
	ans = 0;
}

void input()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp;
			cin >> temp;
			// 중앙에서 퍼져야함
			maps[centerSZ + i][centerSZ + j] = temp;


			if (temp != 0)
			{
				CELL a;
				a.life = temp;
				a.t = temp;
				a.x = centerSZ + i;
				a.y = centerSZ + j;
				cells.push_back(a);
			}
		}
	}


}



void play()
{

	int CELLSZ = cells.size();

	int deadcell = 0;

	while (K--)// 배양시간 
	{
		for (int i = 0; i < CELLSZ; i++)  // 모든 셀을 검사하면서 
		{
			//if (cells[i].life == -1) continue;
			cells[i].t -= 1; // 각 셀을 -1씩 뺸다.
			if (cells[i].t == -1) // 시간이  0일떄 활성화 -1일떄 번식 시작. 
			{
				pq.push(cells[i]);
			}// 셀이 번식을 시작한다 . 번식 순서는 큰 순서 

			if (-cells[i].t == cells[i].life) // 시간이 생명까지 다가면 DEADCELL 추가 
			{
				//cells[i].life = -1;
				deadcell++;
			}
		}// 모든 셀을 검색함



		while (!pq.empty())
		{
			int cx = pq.top().x;
			int cy = pq.top().y;
			int clife = pq.top().life;
			int ctime = pq.top().t;
			pq.pop();

			for(int i = 0 ; i<4;i++){
				int nx = cx + dx[i];
				int ny = cy + dy[i];
	//			if (nx < 0 || ny < 0 || nx >= 350 || ny >= 350) continue;
				if (maps[nx][ny] == 0)
				{
					maps[nx][ny] = clife;
					CELLSZ++;
					cells.push_back({nx,ny,clife,clife}); // 새시간을 부여 라이프
					//셀이 추가할 때마다 사이즈를 늘림
					
				}

				
			}

		}
	}
	

	ans = CELLSZ - deadcell;

}

int main()
{
	int T;
	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		init();
		input();
		play();
		cout << "#" << test << " " << ans << endl;
	}


}