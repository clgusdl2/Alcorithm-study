#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,S = 0;

vector<int> arr;

int combination(int in_k){ //NCk
    int n = N;
    int k = in_k;
    int count = 0;

    vector<int> zerosum;

    // cout << N << "C" << in_k << endl;

    for(int i=0; i<k; i++){
        zerosum.push_back(1);
    }

    for(int i=0; i<n-k; i++){ //선택되는 개수. 1개면 1개
        zerosum.push_back(0);
    }

    sort(zerosum.begin(), zerosum.end());
    for(int i=0; i<N; i++){
    }

    do{
        //조합 1개
        int sum = 0;
        for(int i=0; i<N; i++){
            sum += arr[i] * zerosum[i];
        }
        if(sum == S){
            // for(int i=0; i<N; i++){
            //     cout << zerosum[i] << " ";
            // }
            count ++;
        }
    }while(next_permutation(zerosum.begin(), zerosum.end()));

    return count;
}


int main(){
    int count = 0;
    cin >> N >> S;
    for(int i=0; i<N; i++){
        int in_num;
        cin >> in_num;
        arr.push_back(in_num);
    }

    for(int i=1; i<=N; i++){
        count += combination(i);
    }

    cout << count;
}