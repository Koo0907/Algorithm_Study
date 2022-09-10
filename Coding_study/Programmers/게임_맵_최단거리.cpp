/* 프로그래머스 */
/* https://school.programmers.co.kr/learn/courses/30/lessons/1844 */
#include<vector>
#include<queue>
using namespace std;

// 상,하,좌,우 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 좌표 큐 선언
queue<pair<int, int>> q;

// 방문 처리를 위한 배열
bool visited[100][100] = {false};

void bfs(int x, int y, vector<vector<int>> &maps)
{
    // X축의 길이와 Y축의 길이
    int axis_x = maps.size();
    int axis_y = maps[0].size();
    
	// 파라미터 좌표 방문 처리
    visited[x][y] = true;
    
	// 파라미터 좌표 큐에 추가
    q.push({x, y});
    
	// 큐가 빌 때까지 반복
    while(!q.empty())
    {
		// 큐에서 좌표 데이터 추출 및 삭제
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
		// 상,하,좌,우 네 방향 확인
        for(int i = 0; i < 4; i++)
        {
			// 다음 좌표 구함
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
			// 다음 좌표가 맵 상에 있는지 확인
            if((next_x >= 0 ) && (next_x < axis_x) && (next_y >= 0) && (next_y < axis_y))
            {
				// 다음 좌표의 값이 1이고 아직 방문하지 않았는지 확인
                if((maps[next_x][next_y] == 1) && (visited[next_x][next_y] == false))
                {
					// 다음 좌표 방문 처리
                    visited[next_x][next_y] = true;

					// 다음 좌표 값 갱신
                    maps[next_x][next_y] = maps[x][y] + 1;

					// 다음 좌표 큐에 추가
                    q.push({next_x, next_y});
                }
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
	// X축의 길이와 Y축의 길이
    int axis_x = maps.size();
    int axis_y = maps[0].size();
    
	// BFS 함수 수행
    bfs(0,0, maps);
    
	// 마지막 영역을 방문했는지 확인 후 출력
    if(visited[axis_x - 1][axis_y - 1] == false)
    {
        answer = -1;
    }
    else
    {
        answer = maps[axis_x - 1][axis_y - 1];
    }
    
    return answer;
}