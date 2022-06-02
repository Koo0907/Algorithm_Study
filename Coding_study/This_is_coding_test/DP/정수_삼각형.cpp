/* 백준 링크 */
/* https://www.acmicpc.net/problem/1932 */
#include<iostream>

using namespace std;

// 사용할 변수 초기화
int n = 0;

// 입력받을 배열과 dp 테이블을 하나로 사용
int dp[500][500];

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (i + 1); j++)
        {
            cin >> dp[i][j];
        }
    }

    // 두번쨰 줄 부터 순회하며 계산
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < (i + 1); j++)
        {
            int up_left = 0;
            int up = 0;

            // 순회하는 행의 첫번째 값은 위의 행의 대각선 왼쪽이 범위를 벗어나므로 up_left 값은 무시
            if(j == 0)
            {
                up_left = 0;
                up = dp[i - 1][j];
            }
            // 순회하는 행의 마지막 값은 위의 행의 대각선 오른쪽이 범위를 벗어나므로 up 값은 무시
            else if(j == i)
            {
                up_left = dp[i - 1][j - 1];
                up = 0;
            }
            // 대각선 왼쪽의 값과 대각선 오른쪽의 값을 탐색
            else
            {
                up_left = dp[i - 1][j - 1];
                up = dp[i - 1][j];
            }

            // 현재 영역의 값에 대각선 왼쪽 값과 대각선 오른쪽 값 중 더 큰 값을 더해주며 dp 테이블 갱신
            dp[i][j] += max(up_left, up);
        }
    }

    // 마지막 행의 최대값 탐색
    int max_val = 0;
    for(int i = 0; i < n; i++)
    {
        max_val = max(max_val, dp[n-1][i]);
    }

    cout << max_val << endl;
}