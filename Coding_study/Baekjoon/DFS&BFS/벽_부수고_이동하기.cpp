#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 1000

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int N = 0;
int M = 0;
int ans = 0;

// 맵 배열
int map[MAX][MAX];

// 벽을 부순 것에 대한 여부와 방문 처리 및 경로 갱신 3차원 배열
int visited[2][MAX][MAX];

// BFS 수행 함수
int bfs(int wall, int x, int y)
{
	// 벽을 부순 것에 대한 여부와 좌표를 요소로 하는 큐 선언
	queue<pair<int, pair<int, int>>> q;

	// 초기 값 큐에 추가
	q.push({wall, {x, y}});

	// 해당 좌표 방문 처리
	visited[wall][x][y] = 1;

	// 큐가 빌 때까지 반복
	while(!q.empty())
	{
		// 큐에 있는 데이터 추출 및 삭제
		wall = q.front().first;
		x = q.front().second.first;
		y = q.front().second.second;
		q.pop();

		// 추출한 좌표가 마지막 좌표라면 지금까지의 경로 반환
		if((x == (N - 1)) && (y == (M - 1)))
		{
			return visited[wall][x][y];
		}

		// 상,하,좌,우 방향으로 순회
		for(int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			
			// 다음 좌표가 맵 안에 있는지 확인
			if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < M))
			{
				// 다음 좌표가 0인 경우
				if(map[next_x][next_y] == 0)
				{
					// 다음 좌표를 방문처리 하지 않았다면 아래 로직 수행
					if(visited[wall][next_x][next_y] == 0)
					{
						// 다음 좌표 방문 처리 및 경로 갱신 
						visited[wall][next_x][next_y] = visited[wall][x][y] + 1;

						// 다음 좌표 큐에 추가
						q.push({wall, {next_x, next_y}});
					}	
				}
				// 다음 좌표가 1인 경우
				else
				{
					// 아직 벽을 부순 적이 없다면 아래 로직 수행
					if(wall == 0)
					{
						// 다음 좌표를 방문처리 하지 않았다면 아래 로직 수행
						if(visited[wall + 1][next_x][next_y] == 0)
						{
							// 다음 좌표 방문 처리 및 경로 갱신
							// 주의할 점은 경로 갱신하는 visited 배열은 wall = 1인 배열임
							// 지금까지는 wall = 0으로 벽을 부수지 않은 채로 경로를 갱신해 왔음
							// 이제 벽을 만나고 벽을 한번 부쉈으므로 wall = 1인 visited 배열로 경로를 갱신함
							visited[wall + 1][next_x][next_y] = visited[wall][x][y] + 1;

							// 다음 좌표 큐에 추가
							q.push({wall + 1, {next_x, next_y}});
						}
					}
				}
			}
		}
	}
	// 경로를 찾지 못했다면 -1 반환
	return -1;
}

int main()
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%1d",&map[i][j]);
		}
	}

	// 초기 좌표에 벽을 부수지 않았다는 조건에서 BFS 함수 수행
	ans = bfs(0, 0, 0);

	cout << ans << endl;

}