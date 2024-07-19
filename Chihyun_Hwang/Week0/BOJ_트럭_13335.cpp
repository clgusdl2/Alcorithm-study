#include <iostream>
#include <queue>
using namespace std;

int n, w, L; //다리를 건너는 트럭의 수 , 다리의 길이 , L 다리가 견디는 무게
queue<int>start_trucks;
queue<pair<int,int>>move_trucks;



/*

1초 
1번트럭 7 이 다리에 올라감 q.push()?
2초 7번이 지나가는 중
3초 7번이 q.pop()함 + 4번이 올라감
4초 4번은 지나가는 중 + 5번이 올라감
5초 4초는 q.pop() 5번은 지나가는 중
6초 5번은 q.pop() 6번이 올라감
7초 6번은 지나가고 있는중
8초 6번팝
 */


// 한 트럭이 걸리는 시간?
// 다리길이 w + 현재시간  == 지나간 시간
// L 동시에 다리 위에 올라가 있는 트럭들의 무게의 합은 다리의 최대하중인 L보다 작거나 같아야 한다.



void simul()
{
	int time = 0;
	int Lsums = 0;
	int endline = 0;
	while (endline != n)
	{
		time++;

		if (move_trucks.size() > 0) // 먼저 다리에 차량이 있음 먼저 뺴내야함
		{
			int movings_truck_w = move_trucks.front().first;
			int movings_truck_time = move_trucks.front().second;

			if (movings_truck_time == time) // 나갈 수 있는 시간이 된다면?
			{

				Lsums -= movings_truck_w; // 무게 뺴주고
				move_trucks.pop(); //차를 빼주고
				endline++; // 도달지점 차 추가.
			}
		}

		if (start_trucks.size() > 0) // 시작 트럭이 남아있다면
		{
				int cur_truck = start_trucks.front(); // 트럭을 하나 빼고
				if (L >= Lsums + cur_truck) // 다리가 견딜 수 있는 지 확인
				{
					Lsums += cur_truck; 
					start_trucks.pop();
					move_trucks.push({ cur_truck,time + w });
				}

		}
	}

	cout << time << endl;
}

int main()
{
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		start_trucks.push(temp);
	}

	simul();




}