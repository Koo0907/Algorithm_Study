#include<iostream>

using namespace std;

// ����� ������ �ʱ�ȭ
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
		dp[i] = 1;	// dp ���̺� 1�� �ʱ�ȭ
	}

	// i : 1 ~ N ���� ��ȸ
	for(int i = 1; i <= N; i++)
	{
		// j : 1 ~ i ���� ��ȸ
		for(int j = 1; j <= i; j++)
		{
			// ������ ��(num[i])���� ū ���� ���� �߰��� �ִٸ� dp ���̺� ����
			if(num[j] > num[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;
}