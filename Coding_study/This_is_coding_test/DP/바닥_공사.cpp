#include<iostream>

using namespace std;

// 사용할 변수 초기화
int N = 0;

int memo[1001];

int main()
{
    cin >> N;

    // Dynamic Programming 적용(Bottom-up 방식)
    memo[1] = 1;
    memo[2] = 3;

    for(int i = 3; i <= N; i++)
    {
        memo[i] = (memo[i - 1] + (memo[i - 2] * 2)) % 796796;
    }

    cout << memo[N] << endl;
}