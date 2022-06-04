#include<iostream>

using namespace std;

// 사용할 변수 초기화
int n = 0;

int dp[1001];

int main()
{
    cin >> n;

    // Dynamic Programming 적용(Bottom-up 방식)
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n] << endl;
}