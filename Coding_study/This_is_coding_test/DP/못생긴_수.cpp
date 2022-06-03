#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수 초기화
int n = 0;
int idx_2 = 0;
int idx_3 = 0;
int idx_5 = 0;
// 소인수들(2,3,5)은 미리 각각의 값으로 초기화
int num_2 = 2;
int num_3 = 3;
int num_5 = 5;

// 못생긴 수의 배열 및 dp 테이블
int dp[1000];

int main()
{
    cin >> n;

    // 첫번째 요소는 1로 못생긴 수라고 가정
    dp[0] = 1;
    
    for(int i = 1; i < n; i++)
    {
        // 현재 못생긴 수 세 가지 중에서 최소값을 선택
        dp[i] = min(num_2, min(num_3, num_5));

        // 각각 소인수(2,3,5)의 인덱스에 따라서 곱셈 결과를 증가
        if(dp[i] == num_2)
        {
            idx_2++;
            num_2 = dp[idx_2] * 2;
        }
        if(dp[i] == num_3)
        {
            idx_3++;
            num_3 = dp[idx_3] * 3;
        }
        if(dp[i] == num_5)
        {
            idx_5++;
            num_5 = dp[idx_5] * 5;
        }
    }

    cout << dp[n - 1] << endl;
}