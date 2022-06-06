#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수 초기화
int n = 0;
int num = 0;

// dp 테이블
int dp[10001];

vector<int> vec;

int main()
{
    cin >> n;

    // 포도주의 양이 들어가는 벡터의 첫번째 값은 0으로 설정 후 입력받음
    vec.push_back(0);

    for(int i = 0; i < n; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // 3번 연속으로 포도주를 마실 수 없으므로 두번째 경우까지의 초기값을 미리 설정함
    dp[0] = vec[0];
    dp[1] = vec[1];
    dp[2] = vec[1] + vec[2];

    // 세번째 포도주의 경우부터 해당 로직 수행
    // 이번 차례에 마시지 않는 경우는 dp[i-1]
    // 이번 차례에 마시고 직전에는 마시지 않았을 경우에는 dp[i-2] + vec[i]
    // 이번 차례에 마시고 직전에도 마셨을 경우에는 dp[i-3] + vec[i-1] + vec[i]
    for(int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], max(dp[i - 2] + vec[i], dp[i - 3] + vec[i - 1] + vec[i]));
    }

    // n번째 포도주까지 마셨을 때의 최대값 출력
    cout << dp[n] << endl;
}