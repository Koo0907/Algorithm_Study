#include<iostream>

using namespace std;

// 사용할 변수들 초기화
int N = 0;

long long dp[91];	// data type은 long long

int main()
{
	scanf("%d", &N);

	dp[1] = 1;
	dp[2] = 1;

	for(int i = 3; i <= N; i++)
	{
		// 문제의 점화식은 결국 dp[i] = dp[i-1] + dp[i-2]로 피보나치와 동일한 규칙
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N] << endl;
}