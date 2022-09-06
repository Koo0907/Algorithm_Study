#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define INF -1
#define MAX 50

using namespace std;

// 상,하,좌,우 방향 벡터
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 사용할 변수 초기화
int N = 0;
int M = 0;
int max_val = 0;
int ans = 0;

// 보물섬 지도 맵
char map[MAX][MAX];

// 방문 처리 및 경로 맵
int visited[MAX][MAX];

// BFS 수행 함수
void bfs(int x, int y)
{
	// 방문 처리 및 경로 맵 초기화
	memset(visited, INF, sizeof(visited));

	// 큐 선언
	queue<pair<int, int>> q;

	// 파라미터 좌표 큐에 추가
	q.push({ x, y });

	// 방문 처리 및 경로 갱신
	visited[x][y] = 0;

	// 큐가 빌 때까지 반복
	while (!q.empty())
	{
		// 큐에 있는 좌표 데이터 추출
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// 상,하,좌,우 방향 순회
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// 다음 좌표가 맵 상에 있는지 확인
			if ((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < M))
			{
				// 다음 좌표를 아직 방문하지 않았고 다음 좌표의 영역이 육지인지 확인
				if ((visited[next_x][next_y] == INF) && (map[next_x][next_y] == 'L'))
				{
					// 다음 좌표 방문 처리 및 경로 갱신
					visited[next_x][next_y] = visited[x][y] + 1;

					// 다음 좌표 큐에 추가
					q.push({ next_x, next_y });

					// 최대 경로 값 갱신
					max_val = max(max_val, visited[next_x][next_y]);
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1s", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// 모든 육지 좌표에서 BFS 수행
			if (map[i][j] == 'L')
			{
				bfs(i, j);
			}
		}
	}

	// 최대 경로값 출력
	cout << max_val << endl;

}