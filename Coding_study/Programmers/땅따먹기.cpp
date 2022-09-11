/* 프로그래머스 */
/* https://school.programmers.co.kr/learn/courses/30/lessons/12913 */
#include <iostream>
#include <vector>

// 행의 최대 길이
#define MAX 100000

using namespace std;

// dp 테이블
int dp[MAX][4];

// 가장 큰 값을 구하기 위한 변수
int max_val = 0;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    // 첫번째 행의 값은 주어진 land의 값으로 갱신
    for(int i = 0; i < land[0].size(); i++)
    {
        dp[0][i] = land[0][i];
    }
    
    // 두번째 행부터 순회 시작
    for(int i = 1; i < land.size(); i++)
    {
        // 열의 수 만큼 순회
        for(int j = 0; j < land[i].size(); j++)
        {
            // 임시 변수 초기화
            int temp_val = 0;
            
            // 현재 순회중인 행의 윗행에서 순회
            for(int k = 0; k < land[i - 1].size(); k++)
            {
                // 현재 순회중인 열과 다른 열만 선택
                if(k != j)
                {
                    // 윗행에서의 가장 큰 값을 구함
                    temp_val = max(temp_val, dp[i - 1][k]);
                }
            }
            
            // dp 테이블에서 현재 순회중인 좌표의 값을 갱신
            dp[i][j] = land[i][j] + temp_val;
            
            // dp 테이블에서 최대값 갱신
            max_val = max(max_val, dp[i][j]);
        }
    }
    
    // dp 테이블에서의 최대값 answer에 대입
    answer = max_val;

    return answer;
}