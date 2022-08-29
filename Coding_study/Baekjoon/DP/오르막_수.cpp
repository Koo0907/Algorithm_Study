#include<iostream>

using namespace std;

// 사용할 변수들 초기화
int N = 0;
int Sum = 0;

// DP 배열은 dp[자릿수][숫자]로 선언
int dp[1001][10];

int main()
{
	scanf("%d", &N);

	for(int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for(int i = 2; i <= N; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			for(int k = 0; k <= j; k++)
			{
				// N번째 자리에 올 수 있는 수를 파악하는 것이 중요
				// N번째 자리는 N-1번째 자리에 있는 수의 이상(같거나 크다면)이라면 가능
				// N-1번째 자리에 0이 왔다면 N번째 자리에는 0~9 가능
				// 반복문에서 i는 자릿수, j는 0~9까지의 수, k는 N-1번째 자리에 있는 수 이상의 수를 순회
				// N번째 자리의 수에 올 수 있는 경우를 모두 계산
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
			}
		}
	}

	for(int i = 0; i < 10; i++)
	{
		// 수를 0~9로 나누었으므로 N번째 길이의 오르막 수를 구하려면 반복문을 해야 함
		Sum = (Sum + dp[N][i]) % 10007; 
	}

	cout << Sum << endl;
}