#include<iostream>

using namespace std;

// 사용할 변수들 초기화
int N = 0;
int K = 0;

long long dp[1001][1001];

int main()
{
	scanf("%d %d",&N, &K);

	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for(int i = 2; i <= N; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(j == 0 || j == i)
			{
				dp[i][j] = 1;
			}
			else
			{
				// 파스칼의 삼각형 이용
				//	1
				//	1 1
				//	1 2 1
				//	1 3 3 1
				//	1 4 6 4 1
				//	...
				dp[i][j] = (dp[i - 1][j - 1]+dp[i - 1][j]) % 10007;
			}
		}
	}

	cout << dp[N][K] << endl;
}