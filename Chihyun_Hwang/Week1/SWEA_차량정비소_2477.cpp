#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

//

int N, M; // A창구 B창구
int K; // 고객 수
int A, B; // 이용한 고객 찾기

int Atable[11];
int Btable[11];

int Auser[11];
int Buser[11];

int Atime[11];
int Btime[11];

queue<int>waitingQ;
queue<int>waitingQ2;


typedef struct People
{
	int AT;
	int BT;

	int time;
};

People person[1002];

void input()
{
	cin >> N >> M >> K >> A >> B;
	for (int i = 1; i <= N; i++)
	{
		cin >> Atime[i]; // Atable 각각 걸리는 시간 
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> Btime[i]; // Btable 각 창구 걸리는 시간 
	}

	for (int i = 1; i <= K; i++)
	{
		cin >> person[i].time; // 도착시간
	}
}

void play()
{
	int out = 0;
	int Times = 0;

	memset(Atable, -1, sizeof(Atable));
	memset(Btable, -1, sizeof(Btable));


	while (true)
	{
		// 1. 도착한 사람 큐에 넣기
		for (int i = 1; i <= K; i++)
		{
			if (person[i].time == Times)
			{
				waitingQ.push(i); // 고객번호 
			}
		}


		// 2. 접수 창고에 시간 다 된 사람 내보내기.
		for (int i = 1; i <= N; i++)
		{
			if (Atable[i] == Times)
			{
				Atable[i] = -1;
				waitingQ2.push(Auser[i]);
			}
		}


        // 3. 접수 창고 비였으면 도착한 사람 넣기

		for (int i = 1; i <= N; i++)
		{
			if (waitingQ.empty()) break;
			if (Atable[i] == -1)
			{
				Atable[i] = Atime[i] + Times;
				Auser[i] = waitingQ.front();
				person[waitingQ.front()].AT = i;
				waitingQ.pop();
			}
		}

        // 4. 정비 창고에 시간 다 된 사람 내보내기.
		for (int i = 1; i <= M; i++)
		{
			if (Btable[i] == Times)
			{
				Btable[i] = -1;
				out++;
			}
		}



        // 5. 정비 창고 비였으면 도착한 사람 넣기

		for (int i = 1; i <= M; i++)
		{
			if (waitingQ2.empty()) break;

			if (Btable[i] == -1)
			{
				Btable[i] = Btime[i] + Times;
				Buser[i] = waitingQ2.front();
				person[waitingQ2.front()].BT = i;
				waitingQ2.pop();
			}
		}



        // 6. 만약 나간 사람이 사람 총합과 같다면 끝

		if (out == K) break;



        Times++;
	}
}

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		input();
		play();


		int ans = 0;
		for (int i = 1; i <= K; i++)
		{
			if (person[i].AT == A && person[i].BT == B) ans += i;
		}
		if (ans == 0) cout << "#" << i << " " << -1 << endl;
		else cout << "#" << i << " " << ans << endl;

	}



}
