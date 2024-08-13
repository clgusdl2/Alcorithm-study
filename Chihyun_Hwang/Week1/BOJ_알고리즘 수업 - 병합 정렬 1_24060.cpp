#include <iostream>

using namespace std;
#define MAXN 500001
int cnt = 0;
int sorted[MAXN];
int n, kk;
int list[5] = { 3,4,1,2,5 };
void merge(int list[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;
	int l;

	/* 분할 정렬된 list의 합병 */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}


	while (i <= mid)
	{
		sorted[k++] = list[i++];
	}
	while (j <= right)
	{
		sorted[k++] = list[j++];
	}




	for (int l= left; l <= right; l++)
	{
		list[l] = sorted[l];
		cnt++;
		if (cnt == kk) cout << sorted[l];
	}

}

void mergesort(int list[], int left, int right)
{
	int mid;

	if(left < right)
	{
		mid = (left + right) / 2;
		mergesort(list, left, mid);

		mergesort(list, mid + 1, right);

		merge(list, left, mid, right);

	}

}


int main()
{



	cin >> n >> kk;
	int *list = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	mergesort(list, 0, n - 1);
	if (cnt < kk) cout << "-1";
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << list[i];
	//}


	return 0;
}