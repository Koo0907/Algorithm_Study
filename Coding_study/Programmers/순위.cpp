/* 프로그래머스 */
/* https://school.programmers.co.kr/learn/courses/30/lessons/49191 */
#include <string>
#include <vector>

// 무한을 의미하는 INF 정의
#define INF 1e9

using namespace std;

// 선수들의 경기 결과를 담는 맵
int map[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    // 경기 결과 맵 INF로 초기화
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            map[i][j] = INF;
        }
    }
    
    // 경기 결과 데이터를 경기 결과 맵에 대입
    for(int i = 0; i < results.size(); i++)
    {
        int x = results[i][0];
        int y = results[i][1];
        
        map[x][y] = 1;
    }
    
    // 플로이드 와셜 알고리즘 수행
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    
    // 각 행마다 순회(모든 선수들을 순회)
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        
        // 각 열을 순회
        for(int j = 1; j <= n; j++)
        {
            //행과 열을 뒤집어서 확인해도 INF(경기 결과가 없다는 뜻)가 없다면 순위를 알 수 있음
            if(map[i][j] != INF || map[j][i] != INF)
            {
                // 두 선수의 순위를 알 수 있으므로 cnt 증가
                cnt++;
            }
        }
        
        // 한 선수에 대해서 경기결과를 모두 순회하고 cnt 값이 본인을 제외한 나머지 선수들의 수와 같다면 순위를 매길 수 있음
        if(cnt == n - 1)
        {
            // answer 증가
            answer++;
        }
    }
    
    return answer;
}