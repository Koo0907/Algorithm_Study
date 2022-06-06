#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수 초기화
int n = 0;
int num = 0;

// dp 테이블
int dp[301];

vector<int> vec;

int main()
{
    cin >> n;

    // 계단의 값을 입력받는 벡터의 첫번째 값은 0으로 설정 후 입력받음
    vec.push_back(0);

    for(int i = 0; i < n; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // 3번 연속으로 계단을 밟을 수 없으므로 두번째 계단까지의 초기값을 미리 설정함
    dp[0] = vec[0];
    dp[1] = vec[1];
    dp[2] = vec[1] + vec[2];

    // 3번째 계단부터 해당 로직 수행
    // 현재 순회중인 계단에서 직전의 계단을 밟고 현재 계단을 밟는 경우에는 dp[i - 3] + vec[i - 1] + vec[i]
    // 현재 순회중인 계단에서 전전의 계단을 밝고 현재 계단을 밟는 경우에는 dp[i - 2] + vec[i]
    for(int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 3] + vec[i - 1], dp[i - 2]) + vec[i];
    }

    // n번째 계단을 밟았을 때의 최대값 출력
    cout << dp[n] << endl;
}