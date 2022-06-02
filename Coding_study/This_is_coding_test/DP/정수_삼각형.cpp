/* ���� ��ũ */
/* https://www.acmicpc.net/problem/1932 */
#include<iostream>

using namespace std;

// ����� ���� �ʱ�ȭ
int n = 0;

// �Է¹��� �迭�� dp ���̺��� �ϳ��� ���
int dp[500][500];

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (i + 1); j++)
        {
            cin >> dp[i][j];
        }
    }

    // �ι��� �� ���� ��ȸ�ϸ� ���
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < (i + 1); j++)
        {
            int up_left = 0;
            int up = 0;

            // ��ȸ�ϴ� ���� ù��° ���� ���� ���� �밢�� ������ ������ ����Ƿ� up_left ���� ����
            if(j == 0)
            {
                up_left = 0;
                up = dp[i - 1][j];
            }
            // ��ȸ�ϴ� ���� ������ ���� ���� ���� �밢�� �������� ������ ����Ƿ� up ���� ����
            else if(j == i)
            {
                up_left = dp[i - 1][j - 1];
                up = 0;
            }
            // �밢�� ������ ���� �밢�� �������� ���� Ž��
            else
            {
                up_left = dp[i - 1][j - 1];
                up = dp[i - 1][j];
            }

            // ���� ������ ���� �밢�� ���� ���� �밢�� ������ �� �� �� ū ���� �����ָ� dp ���̺� ����
            dp[i][j] += max(up_left, up);
        }
    }

    // ������ ���� �ִ밪 Ž��
    int max_val = 0;
    for(int i = 0; i < n; i++)
    {
        max_val = max(max_val, dp[n-1][i]);
    }

    cout << max_val << endl;
}