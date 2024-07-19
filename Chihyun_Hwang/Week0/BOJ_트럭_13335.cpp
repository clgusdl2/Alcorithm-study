#include <iostream>
#include <queue>
using namespace std;

int n, w, L; //�ٸ��� �ǳʴ� Ʈ���� �� , �ٸ��� ���� , L �ٸ��� �ߵ�� ����
queue<int>start_trucks;
queue<pair<int,int>>move_trucks;



/*

1�� 
1��Ʈ�� 7 �� �ٸ��� �ö� q.push()?
2�� 7���� �������� ��
3�� 7���� q.pop()�� + 4���� �ö�
4�� 4���� �������� �� + 5���� �ö�
5�� 4�ʴ� q.pop() 5���� �������� ��
6�� 5���� q.pop() 6���� �ö�
7�� 6���� �������� �ִ���
8�� 6����
 */


// �� Ʈ���� �ɸ��� �ð�?
// �ٸ����� w + ����ð�  == ������ �ð�
// L ���ÿ� �ٸ� ���� �ö� �ִ� Ʈ������ ������ ���� �ٸ��� �ִ������� L���� �۰ų� ���ƾ� �Ѵ�.



void simul()
{
	int time = 0;
	int Lsums = 0;
	int endline = 0;
	while (endline != n)
	{
		time++;

		if (move_trucks.size() > 0) // ���� �ٸ��� ������ ���� ���� ��������
		{
			int movings_truck_w = move_trucks.front().first;
			int movings_truck_time = move_trucks.front().second;

			if (movings_truck_time == time) // ���� �� �ִ� �ð��� �ȴٸ�?
			{

				Lsums -= movings_truck_w; // ���� ���ְ�
				move_trucks.pop(); //���� ���ְ�
				endline++; // �������� �� �߰�.
			}
		}

		if (start_trucks.size() > 0) // ���� Ʈ���� �����ִٸ�
		{
				int cur_truck = start_trucks.front(); // Ʈ���� �ϳ� ����
				if (L >= Lsums + cur_truck) // �ٸ��� �ߵ� �� �ִ� �� Ȯ��
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