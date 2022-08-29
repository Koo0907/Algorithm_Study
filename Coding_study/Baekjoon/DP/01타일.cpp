#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수들 초기화
int N = 0;

long long dp[1000001];	// data type은 long long

int main()
{
	scanf("%d",&N);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	// 문제의 점화식은 결국 dp[i] = dp[i-1] + dp[i-2]로 피보나치와 동일한 규칙
	for(int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[N] << endl;
}