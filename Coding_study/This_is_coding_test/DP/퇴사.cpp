/* 백준 링크 */
/* https://www.acmicpc.net/problem/14501 */
#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int num1 = 0;
int num2 = 0;
int max_val = 0;

// dp[i] = i번쨰 날부터 마지막 날까지 낼 수 있는 최대 이익
int dp[16];
vector<pair<int, int>> vec;

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num1 >> num2;
        vec.push_back({num1, num2});
    }

    // Dynamic Programming 적용(Bottom-up 방식)
    // 상담 리스트를 뒤에서부터 거꾸로 확인하면서 dp 테이블 갱신
    // ex) n = 7 / 3, 10 / 5, 20 / 1, 10 / 1, 20 / 2, 15 / 4, 40 / 2, 200
    // dp[6] = 0 -> 상담 기간 초과
    // dp[5] = 0 -> 상담 기간 초과
    // dp[4] = 15(max(15 + dp[6], max_val(0))) / max_val = 15
    // dp[3] = 35(max(20 + dp[4], max_val(15))) / max_val = 35
    // dp[2] = 45(max(10 + dp[3], max_val(35))) / max_val = 45
    // dp[1] = 45(max(20 + dp[6], max_val(45))) / max_val = 45
    // dp[0] = 45(max(10 + dp[3], max_val(45))) / max_val = 45
    for (int i = (N - 1); i >= 0; i--)
    {
        int time = vec[i].first + i;

        // 상담이 기간 안에 끝나는 경우는 아래 로직 수행
        if (time <= N)
        {
            // 현재 상담 일자의 이익과 현재 상담을 마친 일자부터의 최대 이익을 더한 값을 현재의 최대 이익과 비교하고 최대 이익 갱신
            dp[i] = max(vec[i].second + dp[time], max_val);
            max_val = dp[i];
        }
        // 상담이 기간을 벗어나는 경우는 현재의 최대 이익으로 갱신
        else
        {
            dp[i] = max_val;
        }
    }

    cout << max_val << endl;
}