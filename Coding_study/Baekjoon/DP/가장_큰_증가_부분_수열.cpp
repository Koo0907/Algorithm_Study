#include<iostream>

using namespace std;

// ����� ������ �ʱ�ȭ
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
		dp[i] = num[i];	// dp ���̺� �迭�� ������ ������ �ʱ�ȭ
	}

	// i�� ������ ���� �ε���
	for(int i = 1; i <= N; i++)
	{
		// j�� ���� ���� �ε���
		for(int j = 1; j <= i; j++)
		{
			// ��ȸ���� j �ε����� ���� ������ ���� i �ε��� ������ �۴ٸ� �Ʒ� ���� ����
			if(num[j] < num[i])
			{
				// ex) 1 100 2 50 60 3 5 6 7 8
				// i = 1�� ���� j�� �ش��ϴ� ���� �����Ƿ� Pass
				// i = 2�� ���� j = 1�� ��� �ش��ϹǷ� dp[2] = max(100(=dp[i]), 1(=dp[j]) + 100(=num[i])) = 101
				// i = 3�� ���� j = 1�� ��� �ش��ϹǷ� dp[3] = max(2(=dp[i]), 1(=dp[j]) + 2(=num[i])) = 3
				// i = 4�� ���� j = 1,3�� ��� �ش��ϹǷ�
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