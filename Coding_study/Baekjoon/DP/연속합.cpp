#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수 초기화
int n = 0;
int num = 0;
int max_val = 0;

// dp 테이블
int dp[100001];

vector<int> vec;

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // dp 테이블의 첫번째 값은 수열의 첫번째 값으로 초기화
    dp[0] = vec[0];

    // 최대값도 dp 테이블의 첫번째 값으로 초기화
    max_val = dp[0];

    for(int i = 1; i < n; i++)
    {
        // 수열을 값 하나씩 더하면서 부분합의 최대값을 판단
        // 현재 순회중인 수에 대해서 직전 수부터 연속적으로 선택하는 경우에는 dp[i-1] + vec[i]
        // 현재 순회중인 수에 대해서 직전 수를 제외하고 순회하는 수만 선택하는 경우에는 vec[i]
        // 각각의 경우의 더 큰 값을 선택
        dp[i] = max(dp[i - 1] + vec[i], vec[i]);

        // 한번씩 순회와 최대값 판단이 끝나면 최대값 비교 후 갱신
        if(dp[i] > max_val)
        {
            max_val = dp[i];
        }
    }

    // 최대값 출력
    cout << max_val << endl;
}