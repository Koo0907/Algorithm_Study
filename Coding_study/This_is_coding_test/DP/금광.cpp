#include<iostream>

using namespace std;

// ����� ���� �ʱ�ȭ
int T = 0;
int n = 0;
int m = 0;

// �ݱ� ����
int gold[20][20];

// dp �迭
int dp[20][20];

int main()
{
    cin >> T;

    for(int tc = 0; tc < T; tc++)
    {
        cin >> n >> m;

        // �ݱ� ������ dp �迭 �ʱ�ȭ
        memset(gold, 0, sizeof(gold));
        memset(dp, 0, sizeof(dp));

        // �ݱ� ���� �Է�
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> gold[i][j];
            }
        }

        // dp �迭�� �ݱ� ���� ������ ����
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                dp[i][j] = gold[i][j];
            }
        }

        // �ִ밪�� ���ϱ� ���� ������ ����
        int left_up = 0;
        int left = 0;
        int left_down = 0;

        // Dynamic Programming ����(Bottom-up ���)
        // ù��° �ݺ������� j�� ���� ��ȸ
        // j�� ���� ��ȸ���Ѿ� ���� �������� ������Ű�� ���� ���ʴ�� üũ��(Ž�� ���� ��)
        // �ݴ�� i�� ���� ��ȸ��Ű�� ���� �������� ������Ű�� ���� ���ʴ�� üũ�ϱ� ������ ����(Ž�� ���� ��)
        for(int j = 1; j < m; j++)
        {
            for(int i = 0; i < n; i++)
            {
                // �ݱ� �������� ù��° ���� ��쿡�� left_up ������ ����
                if(i == 0)
                {
                    left_up = 0;
                    left = dp[i][j - 1];
                    left_down = dp[i + 1][j - 1];
                }
                // �ݱ� �������� ������ ���� ��쿡�� left_down ������ ����
                else if(i == (n - 1))
                {
                    left_up = dp[i - 1][j - 1];
                    left = dp[i][j - 1];
                    left_down = 0;
                }
                else
                {
                    left_up = dp[i - 1][j - 1];
                    left = dp[i][j - 1];
                    left_down = dp[i + 1][j - 1];
                }

                // �ݱ� �������� ���� ��ġ�� �ݱ��� left_up, left, left_down�� �ִ밪�� ������
                dp[i][j] = dp[i][j] + max(left_up, max(left, left_down));
            }
        }

        int res = 0;

        // �ݱ� �������� ������ �������� �ִ밪�� Ž��
        for(int i = 0; i < n; i++)
        {
            res = max(res, dp[i][m - 1]);
        }

        cout << res << endl;
    }
}