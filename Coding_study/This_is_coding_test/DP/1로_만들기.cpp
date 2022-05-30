#include<iostream>

using namespace std;

// 사용할 변수 초기화
int X = 0;

int memo[30001];

int main()
{
    cin >> X;

    for (int i = 2; i <= X; i++)
    {
        // 현재의 수에서 1을 빼는 경우
        memo[i] = memo[i - 1] + 1;

        // 현재의 수가 2로 나누어 떨어지는 경우
        if (i % 2 == 0)
        {
            memo[i] = min(memo[i], memo[i / 2] + 1);
        }

        // 현재의 수가 3으로 나누어 떨어지는 경우
        if (i % 3 == 0)
        {
            memo[i] = min(memo[i], memo[i / 3] + 1);
        }

        // 현재의 수가 5로 나누어 떨어지는 경우
        if (i % 5 == 0)
        {
            memo[i] = min(memo[i], memo[i / 5] + 1);
        }
    }
    cout << memo[X] << endl;
}