#include<iostream>

using namespace std;

// ����� ������ �ʱ�ȭ
int N = 0;

int dp[100001];

int main()
{
	scanf("%d",&N);

	// dp ���̺��� ��� 1^2�� ������ �� �ִ� ��(�ִ밪)���� �ʱ�ȭ
	for(int i = 1; i <= N; i++)
	{
		dp[i] = i;
	}

	for(int i = 1; i <= N; i++)
	{
		// 2�� ���������� ��ȸ�ϴµ�, j^2���� i���� �۾ƾ� OutOfBound�� �߻����� ����
		for(int j = 2; (j * j) <= i; j++)
		{
			// ���� � ���� �����̶�� dp���̺��� ������ 1�� ���� �� break;
			if(i == (j * j))
			{
				dp[i] = 1;
				break;
			}
			// ���� j�� ������ �̻��̶�� ��ȭ�� ���
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