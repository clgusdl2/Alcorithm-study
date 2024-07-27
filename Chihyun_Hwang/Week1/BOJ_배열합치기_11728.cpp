#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int *arr1 = new int[n];
	int* arr2 = new int[m];
	int* sorted = new int[n + m];

	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> arr2[i];

	}


	int i = 0;
	int j = 0;
	int idx = 0;
	while (i < n && j < m)
	{
	
		if (arr1[i] <= arr2[j])
		{
			sorted[idx++] = arr1[i++];
		}
		else
		{
			sorted[idx++] = arr2[j++];
		}
	}


	while (i < n) {
		sorted[idx++] = arr1[i++];
	}

	while (j < m) {
		sorted[idx++] = arr2[j++];
	}

	for (int i = 0; i < n + m; i++)
	{
		cout << sorted[i] << " ";
	}

	return 0;

}