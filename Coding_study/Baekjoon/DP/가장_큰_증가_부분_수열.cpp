#include<iostream>

using namespace std;

// 사용할 변수들 초기화
int N = 0;
int max_val = 0;

int num[1001];
int dp[1001];

int main()
{
	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);
		dp[i] = num[i];	// dp 테이블도 배열과 동일한 값으로 초기화
	}

	// i는 마지막 값의 인덱스
	for(int i = 1; i <= N; i++)
	{
		// j는 시작 값의 인덱스
		for(int j = 1; j <= i; j++)
		{
			// 순회중인 j 인덱스의 값이 마지막 값인 i 인덱스 값보다 작다면 아래 로직 수행
			if(num[j] < num[i])
			{
				// ex) 1 100 2 50 60 3 5 6 7 8
				// i = 1인 경우는 j가 해당하는 경우는 없으므로 Pass
				// i = 2인 경우는 j = 1인 경우 해당하므로 dp[2] = max(100(=dp[i]), 1(=dp[j]) + 100(=num[i])) = 101
				// i = 3인 경우는 j = 1인 경우 해당하므로 dp[3] = max(2(=dp[i]), 1(=dp[j]) + 2(=num[i])) = 3
				// i = 4인 경우는 j = 1,3인 경우 해당하므로
				// dp[4] = max(50(=dp[i]), 1(=dp[j]) + 50(=num[i])) = 51
				// dp[4] = max(51(=dp[i]), 3(=dp[j]) + 50(=num[i])) = 53
				// ...
				dp[i] = max(dp[i], dp[j] + num[i]);
			}
		}
		max_val = max(max_val, dp[i]);
	}

	cout << max_val << endl;
}