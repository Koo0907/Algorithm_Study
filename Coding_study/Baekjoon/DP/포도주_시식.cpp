#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수 초기화
int n = 0;
int num = 0;
int cnt = 0;

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

    // dp 테이블의 0,1 인덱스의 값은 포도주의 양으로 맞춰주고 순회 시작
    dp[0] = vec[0];
    dp[1] = vec[1];

    // dp 테이블에 포도주 한 잔의 양이 들어갔으므로 cnt 증가
    cnt = 1;

    for(int i = 2; i <= n; i++)
    {
        // cnt가 2 미만이라면 직전의 최대 양에 현재 순회중인 포도주의 양을 더하여 dp 테이블 갱신
        if(cnt < 2)
        {
            dp[i] = dp[i - 1] + vec[i];
            cnt++;
        }
        else
        {
            // cnt가 2 이상이라면 앞서 두번의 포도주를 마셨다는 의미
            // 그렇다면 현재 포도주를 마실지, 마시지 않을지에 대해 판단을 해야 함
            // 이번 차례에 마시지 않는 경우는 dp[i-1]
            // 이번 차례에 마시고 직전에는 마시지 않았을 경우에는 dp[i-2] + vec[i]
            // 이번 차례에 마시고 직전에도 마셨을 경우에는 dp[i-3] + vec[i-1] + vec[i]
            dp[i] = max(dp[i - 1], max(dp[i - 2] + vec[i], dp[i - 3] + vec[i - 1] + vec[i]));
            
            // 각각의 경우에 맞춰서 연속하여 마셨는지의 여부를 각각 확인해서 cnt 값 갱신
            if(dp[i] == dp[i - 3] + vec[i - 1] + vec[i])
            {
                cnt = 2;
            }

            if(dp[i] == dp[i - 2] + vec[i])
            {
                cnt = 1;
            }

            if(dp[i] == dp[i - 1])
            {
                cnt = 0;
            }

        }
    }

    // n번째 포도주까지 마셨을 때의 최대값 출력
    cout << dp[n] << endl;
}