#include <iostream>

using namespace std;

int m[101];

#define toggle(a) (a==1 ? 0:1)

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> m[i];
	}
	int student;
	cin >> student;
	
	while (student--)
	{
		int gender, nums;
		cin >> gender >> nums;

		if (gender == 1)
		{
			for (int i = nums; i <= n; i += nums)
			{
				m[i] = toggle(m[i]);
			}
		}
		else
		{
			int right = nums + 1;
			int left = nums - 1;

			m[nums] = toggle(m[nums]);
			while (right <= n || left >= 0)
			{
				if (m[right] != m[left])
				{
					break;
				}
				else
				{
					m[right] = toggle(m[right]);
					m[left] = toggle(m[left]);
				}
				right++;
				left--;

			}
	
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << m[i] << " ";
		if (i % 20 == 0)
		{
			cout << endl;
		}
	}


}