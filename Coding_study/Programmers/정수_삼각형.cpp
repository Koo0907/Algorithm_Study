/* 프로그래머스 */
/* https://school.programmers.co.kr/learn/courses/30/lessons/43105 */
#include <string>
#include <vector>

#define MAX 500

using namespace std;

// dp 테이블 선언
int memo[MAX][MAX];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    // 주어진 triangle의 높이
    int height = triangle.size();
    
    // 맨 위의 값을 dp 테이블 값에 갱신
    memo[0][0] = triangle[0][0];
    
    // 두번째 줄 부터 순회
    for(int i = 1; i < height; i++)
    {
        // 맨 좌측의 값은 경우의 수가 하나이므로 dp 테이블 갱신
        memo[i][0] = memo[i - 1][0] + triangle[i][0];
        
        // 삼각형 내부의 값들은 그 전의 줄에서 선택할 수 있는 경우가 두가지 있으므로, 그 중에서 큰 값을 이용하여 dp 테이블 갱신
        for(int j = 1; j < i; j++)
        {
            memo[i][j] = max(memo[i - 1][j - 1], memo[i - 1][j]) + triangle[i][j];
        }
        
        // 맨 우측의 값은 경우의 수가 하나이므로 dp 테이블 갱신
        memo[i][i] = memo[i - 1][i - 1] + triangle[i][i];
    }
    
    // 마지막 줄 순회를 위한 index 갱신
    int last_line = height - 1;
    
    // 마지막 줄만 순회
    for(int i = 0; i < triangle[last_line].size(); i++)
    {
        // 마지막 줄에서 최대값을 answer에 대입
        answer = max(answer, memo[last_line][i]);
    }
    
    return answer;
}