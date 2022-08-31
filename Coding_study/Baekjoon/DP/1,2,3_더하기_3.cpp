#include<iostream>

using namespace std;

// 사용할 변수 초기화
int T = 0;
int n = 0;

long long memo[10000001];

int main()
{
    cin >> T;

    for(int tc = 0; tc < T; tc++)
    {
        cin >> n;

        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 4;

        for(int i = 4; i <= n; i++)
        {
            memo[i] = (memo[i - 1] + memo[i - 2] + memo[i - 3]) % 1000000009;
        }

        cout << memo[n] << endl;
    }
}