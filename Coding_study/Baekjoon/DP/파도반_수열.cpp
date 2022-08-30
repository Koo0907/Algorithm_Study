#include<iostream>

using namespace std;

// 사용할 변수들 초기화
int Tc = 0;
int num = 0;

long long dp[101];

int main()
{
	scanf("%d", &Tc);

	for(int i = 0; i < Tc; i++)
	{
		scanf("%d",&num);
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 2;
		for(int j = 6; j <= num; j++)
		{
			// 6번째 삼각형부터는 dp[N] = dp[N-1] + dp[N-5]의 점화식 사용
			dp[j] = dp[j - 1] + dp[j - 5];
		}

		cout << dp[num] << endl;
	}
}