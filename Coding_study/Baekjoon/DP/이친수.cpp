#include<iostream>

using namespace std;

// ����� ������ �ʱ�ȭ
int N = 0;

long long dp[91];	// data type�� long long

int main()
{
	scanf("%d", &N);

	dp[1] = 1;
	dp[2] = 1;

	for(int i = 3; i <= N; i++)
	{
		// ������ ��ȭ���� �ᱹ dp[i] = dp[i-1] + dp[i-2]�� �Ǻ���ġ�� ������ ��Ģ
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N] << endl;
}