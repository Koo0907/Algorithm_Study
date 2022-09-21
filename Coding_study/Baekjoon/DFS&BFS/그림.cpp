#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 1e9
#define MAX 500

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int n = 0;
int m = 0;
int cnt = 0;
int max_val = 0;

// 도화지 배열
int picture[MAX][MAX];

// BFS 수행 함수
void bfs(int x, int y)
{
    // 그림의 크기 초기화
    int size = 1;

    // 큐 선언
    queue<pair<int, int>> q;

    // 큐에 현재 좌표 추가
    q.push({x, y});

    // 현재 좌표의 값을 2로 설정하여 방문하였음을 표시
    picture[x][y] = 2;

    // 큐가 빌 때까지 순회
    while(!q.empty())
    {
        // 큐에서 데이터 추출 및 삭제
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // 동,서,남,북 방향 순회
        for(int i = 0; i < 4; i++)
        {
            // 다음 좌표 계산
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // 다음 좌표가 도화지 내에 있는지 확인
            if((next_x >= 0) && (next_x < n) && (next_y >= 0) && (next_y < m))
            {
                // 다음 좌표가 1(아직 방문하지 않은 색이 칠해져 있는 공간)인지 확인
                if(picture[next_x][next_y] == 1)
                {
                    // 큐에 다음 좌표 추가
                    q.push({next_x, next_y});

                    // 다음 좌표 방문 처리
                    picture[next_x][next_y] = 2;

                    // 그림의 크기 증가
                    size++;
                }
            }
        }
    }

    // 그림의 크기 최대값 갱신
    max_val = max(max_val, size);
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &picture[i][j]);
        }
    }

    // 도화지 좌표 완전탐색
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // 좌표 영역이 1인 경우에만 아래 로직 수행
            if(picture[i][j] == 1)
            {
                // BFS 함수 호출
                bfs(i, j);

                // 그림의 개수 증가
                cnt++;
            }
        }
    }

    // 출력
    printf("%d\n%d\n", cnt, max_val);
}