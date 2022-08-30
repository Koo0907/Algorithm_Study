#include<iostream>

using namespace std;

// 사용할 변수들 초기화
int num = 0;

long long dp[91];

int main()
{
	scanf("%d",&num);

	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i <= num; i++)
	{
		// 피보나치 함수 규칙 적용
		// DP 기본 문제
		dp[i] = dp[i - 1] + dp[i - 2]; 
	}

	cout << dp[num];
}