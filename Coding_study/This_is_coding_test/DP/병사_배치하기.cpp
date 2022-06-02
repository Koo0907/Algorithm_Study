/* 백준 링크 */
/* https://www.acmicpc.net/problem/18353 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int num = 0;

int memo[2000];
vector<int> vec;

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // 순서를 뒤집어서 '가장 긴 증가하는 수열(LIS)' 알고리즘을 적용
    reverse(vec.begin(), vec.end());

    // Dynamic Programming을 위한 DP 테이블 초기화
    for(int i = 0; i < N; i++)
    {
        memo[i] = 1;
    }

    // 1 ~ N까지 순회하기 시작
    for(int i = 1; i < N; i++)
    {
        // 0 ~ i까지 순회하기 시작
        for(int j = 0; j < i; j++)
        {
            // i번째 값이 j번째 값도 크다면 dp 테이블 갱신
            if(vec[i] > vec[j])
            {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }
    }

    // 가장 긴 수열의 길이 구함
    int max_val = 0;
    for(int i = 0; i < N; i++)
    {
        max_val = max(max_val, memo[i]);
    }

    cout << N - max_val << endl;
}