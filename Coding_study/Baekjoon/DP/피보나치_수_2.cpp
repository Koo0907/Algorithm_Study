#include<iostream>

using namespace std;

// ����� ������ �ʱ�ȭ
int num = 0;

long long dp[91];

int main()
{
	scanf("%d",&num);

	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i <= num; i++)
	{
		// �Ǻ���ġ �Լ� ��Ģ ����
		// DP �⺻ ����
		dp[i] = dp[i - 1] + dp[i - 2]; 
	}

	cout << dp[num];
}