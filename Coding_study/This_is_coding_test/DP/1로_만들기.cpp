#include<iostream>

using namespace std;

// ����� ���� �ʱ�ȭ
int X = 0;

int memo[30001];

int main()
{
    cin >> X;

    for (int i = 2; i <= X; i++)
    {
        // ������ ������ 1�� ���� ���
        memo[i] = memo[i - 1] + 1;

        // ������ ���� 2�� ������ �������� ���
        if (i % 2 == 0)
        {
            memo[i] = min(memo[i], memo[i / 2] + 1);
        }

        // ������ ���� 3���� ������ �������� ���
        if (i % 3 == 0)
        {
            memo[i] = min(memo[i], memo[i / 3] + 1);
        }

        // ������ ���� 5�� ������ �������� ���
        if (i % 5 == 0)
        {
            memo[i] = min(memo[i], memo[i / 5] + 1);
        }
    }
    cout << memo[X] << endl;
}