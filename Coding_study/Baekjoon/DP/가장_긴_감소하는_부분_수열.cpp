#include<iostream>

using namespace std;

// 사용할 변수들 초기화
int N = 0;
int ans = 0;

int num[1001];
int dp[1001];

int main()
{
	scanf("%d",&N);

	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);
		dp[i] = 1;	// dp 테이블 1로 초기화
	}

	// i : 1 ~ N 까지 순회
	for(int i = 1; i <= N; i++)
	{
		// j : 1 ~ i 까지 순회
		for(int j = 1; j <= i; j++)
		{
			// 마지막 수(num[i])보다 큰 수가 수열 중간에 있다면 dp 테이블 갱신
			if(num[j] > num[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;
}