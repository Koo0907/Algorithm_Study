#include<iostream>

using namespace std;

// 사용할 변수들 초기화
int N = 0;
int dp[1001] = {0};

int main()
{
	cin >> N;

	// Dynamic Programming 적용(Bottom-up 방식)
	dp[1] = 1;
	dp[2] = 3;

	for(int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + (2 * dp[i - 2])) % 10007;
	}

	cout << dp[N] << endl;
}