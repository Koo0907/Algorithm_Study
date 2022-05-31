#include<iostream>

using namespace std;

// 사용할 변수 초기화
int T = 0;
int n = 0;
int m = 0;

// 금광 지도
int gold[20][20];

// dp 배열
int dp[20][20];

int main()
{
    cin >> T;

    for(int tc = 0; tc < T; tc++)
    {
        cin >> n >> m;

        // 금광 지도와 dp 배열 초기화
        memset(gold, 0, sizeof(gold));
        memset(dp, 0, sizeof(dp));

        // 금광 지도 입력
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> gold[i][j];
            }
        }

        // dp 배열에 금광 지도 데이터 복사
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                dp[i][j] = gold[i][j];
            }
        }

        // 최대값을 구하기 위한 변수들 선언
        int left_up = 0;
        int left = 0;
        int left_down = 0;

        // Dynamic Programming 적용(Bottom-up 방식)
        // 첫번째 반복문에서 j를 먼저 순회
        // j를 먼저 순회시켜야 열을 기준으로 고정시키고 행을 차례대로 체크함(탐색 방향 ↓)
        // 반대로 i를 먼저 순회시키면 행을 기준으로 고정시키고 열을 차례대로 체크하기 때문에 오답(탐생 방향 →)
        for(int j = 1; j < m; j++)
        {
            for(int i = 0; i < n; i++)
            {
                // 금광 지도에서 첫번째 행의 경우에는 left_up 방향은 무시
                if(i == 0)
                {
                    left_up = 0;
                    left = dp[i][j - 1];
                    left_down = dp[i + 1][j - 1];
                }
                // 금광 지도에서 마지막 행의 경우에는 left_down 방향은 무시
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

                // 금광 지도에서 현재 위치의 금광과 left_up, left, left_down의 최대값을 더해줌
                dp[i][j] = dp[i][j] + max(left_up, max(left, left_down));
            }
        }

        int res = 0;

        // 금광 지도에서 마지막 열에서의 최대값을 탐색
        for(int i = 0; i < n; i++)
        {
            res = max(res, dp[i][m - 1]);
        }

        cout << res << endl;
    }
}