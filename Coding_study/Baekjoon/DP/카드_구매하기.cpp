#include<iostream>
#include<vector>

using namespace std;

// ����� ������ �ʱ�ȭ
int N = 0;

int card[10001];
int dp[1001];


int main()
{
	scanf("%d", &N);

	// ī���� ���� �Է�
	for(int i = 1; i <= N; i++)
	{
		scanf("%d",&card[i]);
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			// N���� ī�带 �� ���� �ִ밪�� �Ʒ��� ���� ����
			// ī�� N-1���� �� ���� �ִ밪 + 1�� ¥�� ī����
			// ī�� N-2���� �� ���� �ִ밪 + 2�� ¥�� ī����
			// ī�� N-3���� �� ���� �ִ밪 + 3�� ¥�� ī����
			// ...
			// ī�� 0���� �� ���� �ִ밪 + N�� ¥�� ī����
			// ���� ����� �� �߿��� �ִ밪�� ����
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}

	cout << dp[N] << endl;

}