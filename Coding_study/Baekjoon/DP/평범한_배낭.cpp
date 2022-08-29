#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수들 초기화
int N = 0;
int K = 0;

int W[100001];
int V[1001];
int dp[101][100001];

int main()
{
	scanf("%d %d",&N, &K);

	for(int i = 1; i <= N; i++)
	{
		scanf("%d %d", &W[i], &V[i]);
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= K; j++)
		{
			if(W[i] <= j)
			{
				dp[i][j] = max(dp[i - 1][j], V[i] + dp[i - 1][j - W[i]]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K] << endl;
}