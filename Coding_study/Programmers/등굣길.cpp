/* 프로그래머스 */
/* https://school.programmers.co.kr/learn/courses/30/lessons/42898 */
#include <string>
#include <vector>

// 맵의 최대 크기
#define MAX 101

using namespace std;

// modular 수
int div_num = 1000000007;

// dp 테이블
int dp[MAX][MAX];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    // 웅덩이 좌표 확인
    for(int i = 0; i < puddles.size(); i++)
    {
        int x = puddles[i][0];
        int y = puddles[i][1];
        
        // 웅덩이 좌표의 값은 -1로 설정
        dp[y][x] = -1;
    }
    
    // 집이 있는 위치는 1로 설정
    dp[1][1] = 1;
    
    // 맵 전체 순회
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            // 순회하는 영역이 웅덩이가 아니라면 아래 로직 수행
            if(dp[i][j] != -1)
            {
                // 임시 변수 선언
                int a = 0;
                int b = 0;
                
                // 순회하는 영역의 왼쪽 영역이 웅덩이가 아닌지 확인
                if(dp[i-1][j] != -1)
                {
                    a = dp[i-1][j]; 
                }
                
                // 순회하는 영역의 위쪽 영역이 웅덩이가 아닌지 확인
                if(dp[i][j-1] != -1)
                {
                    b = dp[i][j-1];
                }
                
                // 순회하는 영역 갱신
                dp[i][j] += ((a + b) % div_num);
            }
        }
    }
    
    // 학교 좌표의 값 대입
    answer = dp[n][m];
    
    return answer;
}