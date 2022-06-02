#include<iostream>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;

int memo[1001];

int main()
{
    cin >> N;

    // Dynamic Programming ����(Bottom-up ���)
    memo[1] = 1;
    memo[2] = 3;

    for(int i = 3; i <= N; i++)
    {
        memo[i] = (memo[i - 1] + (memo[i - 2] * 2)) % 796796;
    }

    cout << memo[N] << endl;
}