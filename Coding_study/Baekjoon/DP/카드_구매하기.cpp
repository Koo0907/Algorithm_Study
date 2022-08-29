#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수들 초기화
int N = 0;

int card[10001];
int dp[1001];


int main()
{
	scanf("%d", &N);

	// 카드팩 가격 입력
	for(int i = 1; i <= N; i++)
	{
		scanf("%d",&card[i]);
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			// N개의 카드를 살 때의 최대값은 아래의 경우와 같음
			// 카드 N-1개를 살 때의 최대값 + 1개 짜리 카드팩
			// 카드 N-2개를 살 때의 최대값 + 2개 짜리 카드팩
			// 카드 N-3개를 살 때의 최대값 + 3개 짜리 카드팩
			// ...
			// 카드 0개를 살 때의 최대값 + N개 짜리 카드팩
			// 위의 경우의 수 중에서 최대값을 선택
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}

	cout << dp[N] << endl;

}