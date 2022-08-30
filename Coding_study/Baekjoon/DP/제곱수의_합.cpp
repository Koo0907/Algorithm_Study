#include<iostream>

using namespace std;

// 사용할 변수들 초기화
int N = 0;

int dp[100001];

int main()
{
	scanf("%d",&N);

	// dp 테이블은 모두 1^2로 구성할 수 있는 값(최대값)으로 초기화
	for(int i = 1; i <= N; i++)
	{
		dp[i] = i;
	}

	for(int i = 1; i <= N; i++)
	{
		// 2의 제곱수부터 순회하는데, j^2값이 i보다 작아야 OutOfBound가 발생하지 않음
		for(int j = 2; (j * j) <= i; j++)
		{
			// 값이 어떤 수의 제곱이라면 dp테이블은 무조건 1로 갱신 후 break;
			if(i == (j * j))
			{
				dp[i] = 1;
				break;
			}
			// 값이 j의 제곱수 이상이라면 점화식 사용
			// ex)	i = 5, j = 2
			//		5(=dp[5]) = min(5(=dp[5]), 1(=dp[1]) + 1) = 2
			// ex)	i = 6, j = 2
			//		6(=dp[6]) = min(6(=dp[6]), 2(=dp[2]) + 1) = 3
			// ex)	i = 7, j = 2
			//		7(=dp[7]) = min(7(=dp[7]), 3(=dp[3]) + 1) = 4
			// ex)	i = 8, j = 2
			//		8(=dp[8]) = min(8(=dp[8]), 2(=dp[4]) + 1) = 3
			//		...
			else
			{
				dp[i] = min(dp[i], dp[i - (j * j)] + 1);
			}

		}
	}

	cout << dp[N] << endl;
}