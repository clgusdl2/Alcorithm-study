#include<iostream>
#include<vector>

using namespace std;


int* turn_90(int* arr){

}

int* turn_180(int* arr){

}

int* turn_270(int* arr){

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		int arr[n][n];
		int turn_90_result[n*n];
		int turn_180_result(n*n);
		int turn_270_result(n*n);

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> arr[i][j];
			}
		}



	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}