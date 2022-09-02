#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
#define MAX 50

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int n = 0;

// 미로 맵
int map[MAX][MAX];

// 최단거리 테이블
int dis[MAX][MAX];

// 최단거리 테이블 초기화
void map_clear(void)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			dis[i][j] = INF;
		}
	}
}

void dijkstra(void)
{
	// 최단거리 테이블 초기화
	map_clear();

	// {금액, {x좌표, y좌표}}을 요소로 하는 최소 힙 우선순위 큐 선언
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

	// 최단거리 테이블 갱신
	// map의 값이 1인 경우가 빈 공간이고 0인 경우가 부숴야 하는 벽이므로 (1 - map[i][j])로 갱신 
	dis[0][0] = 1 - map[0][0];

	// 시작 좌표 및 최단거리 삽입
	pq.push({dis[0][0], {0, 0}});

	// 큐가 빌 때까지 반복
	while(!pq.empty())
	{
		// roo은 현재 좌표까지의 부순 벽의 최소값
		// x는 현재 좌표의 x 값
		// y는 현재 좌표의 y 값
		int room = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		// 상,하,좌,우 방향 순회
		for(int i = 0; i < 4; i++)
		{
			// next_x는 다음 좌표의 x 값
			// next_y는 다음 좌표의 y 값
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// 다음 좌표가 맵 안에 있다면 아래 로직 수행
			if((next_x >= 0) && (next_x < n) && (next_y >= 0) && (next_y < n))
			{
				// next_room은 현재 좌표까지 부순 벽의 값과 다음 좌표의 벽, 혹은 공간의 값의 합
				// 다음 좌표의 영역이 0인 경우에만 벽을 부숴야 하므로 (1 - map[i][j]) 사용
				int next_room = 1 - map[next_x][next_y] + room;

				// next_room 값이 최단거리 테이블의 값보다 작다면 아래 로직 수행
				if(next_room < dis[next_x][next_y])
				{
					// 최단거리 테이블 갱신
					dis[next_x][next_y] = next_room;

					// 우선순위 큐에 삽입
					pq.push({next_room, {next_x, next_y}});
				}
			}
		}
	}
}

int main()
{
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	dijkstra();

	cout << dis[n - 1][n - 1] << endl;

}