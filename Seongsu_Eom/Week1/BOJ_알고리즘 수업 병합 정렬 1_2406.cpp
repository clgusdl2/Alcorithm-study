#include <iostream>
#include <vector>

using namespace std;

int N, M, cnt = 0;

void merge(vector<int>& A, int p, int q, int r) {
	int i = p, j = q + 1, t = 0;
	vector<int> tmp(r - p + 1);
	while (i <= q && j <= r) {
		if (A[i] <= A[j]) 
			tmp[t++] = A[i++];
		else 
			tmp[t++] = A[j++];
		cnt++;
		if (cnt == M)
			cout << tmp[t - 1];
	}
	while (i <= q) {
		tmp[t++] = A[i++];
		cnt++;
		if (cnt == M)
			cout << tmp[t - 1];
	}
	while (j <= r) {
		tmp[t++] = A[j++];
		cnt++;
		if (cnt == M)
			cout << tmp[t - 1];
	}

	i = p;
	t = 0;
	while (i <= r)
		A[i++] = tmp[t++];
}

void merge_sort(vector<int>& A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main() {
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	merge_sort(A, 0, N - 1);
	if (cnt < M) {
		cout << -1;
	}
	return 0;
}