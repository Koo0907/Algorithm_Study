#include<iostream>
#include<cstring>

using namespace std;

// 사용할 변수 초기화
int T = 0;
int n = 0;

int memo[12];

int main()
{
    cin >> T;

    for(int tc = 0; tc < T; tc++)
    {
        cin >> n;

        // memo 초기화
        memset(memo, 0, sizeof(memo));

        // 1,2,3의 경우는 배열에 고정값으로 줌
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 4;

        // Dynamic Programming 적용(Bottom-up 방식)
        // 규칙에 따라서 memo[i]의 값이 숫자 i를 만들 수 있는 1,2,3의 조합이라고 했을때
        // memo[i]는 memo[i-3] ~ memo[i - 1]의 합과 같다.
        // ex) 4를 만드는 조합의 수는 1을 만드는 조합에 + 3 추가, 2를 만드는 조합에 + 2 추가, 3을 만드는 조합에 + 1 추가
        for(int i = 4; i <= n; i++)
        {
            memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
        }

        cout << memo[n] << endl;
    }
}