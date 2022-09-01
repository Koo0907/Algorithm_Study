#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
#define MAX 125

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int N = 0;
int cnt = 0;

// 동굴 맵
int map[MAX][MAX];

// 최단거리 테이블
int dis[MAX][MAX];

// 최단거리 테이블 초기화
void map_clear(void)
{
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
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

	// 시작 좌표 및 금액 삽입
	pq.push({map[0][0], {0, 0}});

	// 최단거리 테이블 갱신
	dis[0][0] = map[0][0];

	// 큐가 빌 때까지 반복
	while(!pq.empty())
	{
		// cost는 현재 좌표의 금액
		// x는 현재 좌표의 x 값
		// y는 현재 좌표의 y 값
		int cost = pq.top().first;
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
			if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
			{
				// next_cost는 현재 좌표의 금액과 다음 좌표의 금액의 합
				int next_cost = cost + map[next_x][next_y];

				// next_cost 값이 최단거리 테이블의 값보다 작다면 아래 로직 수행
				if(dis[next_x][next_y] > next_cost)
				{
					// 최단거리 테이블 갱신
					dis[next_x][next_y] = next_cost;

					// 우선순위 큐에 삽입
					pq.push({next_cost, {next_x, next_y}});
				}
			}
		}
	}
}

int main()
{
	while(1)
	{
		scanf("%d", &N);

		// 0 입력되면 종료
		if(N == 0)
		{
			break;
		}

		// 테스트 케이스 수
		cnt++;

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		dijkstra();

		cout << "Problem " << cnt << ": " << dis[N - 1][N - 1] << endl;
	}

}