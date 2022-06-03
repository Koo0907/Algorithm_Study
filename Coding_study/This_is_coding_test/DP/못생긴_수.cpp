#include<iostream>
#include<vector>

using namespace std;

// ����� ���� �ʱ�ȭ
int n = 0;
int idx_2 = 0;
int idx_3 = 0;
int idx_5 = 0;
// ���μ���(2,3,5)�� �̸� ������ ������ �ʱ�ȭ
int num_2 = 2;
int num_3 = 3;
int num_5 = 5;

// ������ ���� �迭 �� dp ���̺�
int dp[1000];

int main()
{
    cin >> n;

    // ù��° ��Ҵ� 1�� ������ ����� ����
    dp[0] = 1;
    
    for(int i = 1; i < n; i++)
    {
        // ���� ������ �� �� ���� �߿��� �ּҰ��� ����
        dp[i] = min(num_2, min(num_3, num_5));

        // ���� ���μ�(2,3,5)�� �ε����� ���� ���� ����� ����
        if(dp[i] == num_2)
        {
            idx_2++;
            num_2 = dp[idx_2] * 2;
        }
        if(dp[i] == num_3)
        {
            idx_3++;
            num_3 = dp[idx_3] * 3;
        }
        if(dp[i] == num_5)
        {
            idx_5++;
            num_5 = dp[idx_5] * 5;
        }
    }

    cout << dp[n - 1] << endl;
}