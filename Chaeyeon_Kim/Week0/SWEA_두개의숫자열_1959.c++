#include<iostream>
#include<vector>
using namespace std;


int multiplication(int n, int m, vector<int> arr1, vector<int> arr2){
	int max = 0;
	for(int i=0; i<m-n+1; i++){
		int sum = 0;
		for(int j=0; j<n; j++){
			sum += arr1[j] * arr2[i+j];
		}
		if(sum > max){
			max = sum;
		}
	}
	return max;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N,M = 0;
		cin >> N >> M;
		int result = 0;
		vector <int> arr1;
		vector <int> arr2;

		for(int i=0; i<N; i++){
			int in_num;
			cin >> in_num;
			arr1.push_back(in_num);
		}

		for(int i=0; i<M; i++){
			int in_num;
			cin >> in_num;
			arr2.push_back(in_num);
		}

		if(M>N){
			result = multiplication(N, M, arr1, arr2);
		}else{
			result = multiplication(M, N, arr2, arr1);
		}

		cout << "#" << test_case <<result;

	}
}