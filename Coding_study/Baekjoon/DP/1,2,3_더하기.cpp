#include<iostream>
#include<cstring>

using namespace std;

// ����� ���� �ʱ�ȭ
int T = 0;
int n = 0;

int memo[12];

int main()
{
    cin >> T;

    for(int tc = 0; tc < T; tc++)
    {
        cin >> n;

        // memo �ʱ�ȭ
        memset(memo, 0, sizeof(memo));

        // 1,2,3�� ���� �迭�� ���������� ��
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 4;

        // Dynamic Programming ����(Bottom-up ���)
        // ��Ģ�� ���� memo[i]�� ���� ���� i�� ���� �� �ִ� 1,2,3�� �����̶�� ������
        // memo[i]�� memo[i-3] ~ memo[i - 1]�� �հ� ����.
        // ex) 4�� ����� ������ ���� 1�� ����� ���տ� + 3 �߰�, 2�� ����� ���տ� + 2 �߰�, 3�� ����� ���տ� + 1 �߰�
        for(int i = 4; i <= n; i++)
        {
            memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
        }

        cout << memo[n] << endl;
    }
}