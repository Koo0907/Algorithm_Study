#include<iostream>

using namespace std;

// ����� ������ �ʱ�ȭ
int N = 0;
int dp[1001] = {0};

int main()
{
	cin >> N;

	// Dynamic Programming ����(Bottom-up ���)
	dp[1] = 1;
	dp[2] = 3;

	for(int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + (2 * dp[i - 2])) % 10007;
	}

	cout << dp[N] << endl;
}