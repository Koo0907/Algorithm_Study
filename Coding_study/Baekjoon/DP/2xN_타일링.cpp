#include<iostream>

using namespace std;

// ����� ���� �ʱ�ȭ
int n = 0;

int dp[1001];

int main()
{
    cin >> n;

    // Dynamic Programming ����(Bottom-up ���)
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n] << endl;
}