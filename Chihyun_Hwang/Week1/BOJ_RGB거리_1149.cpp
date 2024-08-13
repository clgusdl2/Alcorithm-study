// RGB 거리
// 1번집은 2번집과 달라야한다
// n-1번집은 n번집과 달라야한다.
// 
#include <iostream>
using namespace std;
#define max 1010
int N;
int cost[max][3];
int dp[max][3];
int a,b;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))


int main()
{
	cin>>N;
	for(int i = 1 ; i<=N;i++) cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
	
	for(int i = 1 ; i<=N;i++)
	{
		dp[i][0] = min(dp[i-1][1] +cost[i][0] , dp[i-1][2]+cost[i][0]);
		dp[i][1] =min(dp[i-1][0] +cost[i][1] , dp[i-1][2]+cost[i][1]);
		dp[i][2] =min(dp[i-1][0] +cost[i][2] , dp[i-1][1]+cost[i][2]);
		
	}
	cout<<min(min(dp[N][0],dp[N][1]),dp[N][2])<<endl;
}