#include<iostream>

using namespace std;

// ����� ������ �ʱ�ȭ
int Tc = 0;
int num = 0;

long long dp[101];

int main()
{
	scanf("%d", &Tc);

	for(int i = 0; i < Tc; i++)
	{
		scanf("%d",&num);
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 2;
		for(int j = 6; j <= num; j++)
		{
			// 6��° �ﰢ�����ʹ� dp[N] = dp[N-1] + dp[N-5]�� ��ȭ�� ���
			dp[j] = dp[j - 1] + dp[j - 5];
		}

		cout << dp[num] << endl;
	}
}