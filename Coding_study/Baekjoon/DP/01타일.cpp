#include<iostream>
#include<vector>

using namespace std;

// ����� ������ �ʱ�ȭ
int N = 0;

long long dp[1000001];	// data type�� long long

int main()
{
	scanf("%d",&N);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	// ������ ��ȭ���� �ᱹ dp[i] = dp[i-1] + dp[i-2]�� �Ǻ���ġ�� ������ ��Ģ
	for(int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[N] << endl;
}