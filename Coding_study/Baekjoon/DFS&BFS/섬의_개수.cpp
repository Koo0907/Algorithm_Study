#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 50

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

using namespace std;

// 사용할 변수 초기화
int w = 0;
int h = 0;
int cnt = 0;

// 지도 배열
int map[MAX][MAX];

// BFS 수행 함수
void bfs(int a, int b)
{
	// 큐 선언
	queue<pair<int, int>> q;

	// 파라미터 좌표 큐에 추가
	q.push({a, b});

	// 파라미터 좌표 방문 처리
	// 맵 상에서는 0,1로만 구분되기 때문에 2는 방문했다는 의미
	map[a][b] = 2;

	// 큐가 빌 때까지 반복
	while(!q.empty())
	{
		// 큐에서 좌표 추출 및 삭제
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 대각선 방향 포함해서 여덟가지 경우 순회
		for(int i = 0; i < 8; i++)
		{
			// 다음 좌표 계산
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// 다음 좌표가 맵 안에 있다면 아래 로직 수행
			if((next_x >= 0) && (next_x < h) && (next_y >= 0) && (next_y < w))
			{
				// 다음 좌표가 땅이라면 아래 로직 수행
				if(map[next_x][next_y] == 1)
				{
					// 다음 좌표 큐에 추가
					q.push({next_x, next_y});

					// 다음 좌표 방문 처리
					map[next_x][next_y] = 2;
				}
			}
		}
	}
}

int main()
{
	while(1)
	{
		scanf("%d %d",&w, &h);
		
		// w와 h가 모두 0이 입력되면 반복문 종료
		if((w == 0) && (h == 0))
		{
			break;
		}

		// 지도 데이터 입력
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				scanf("%d",&map[i][j]);
			}
		}

		// 지도 데이터 순회
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				// 좌표가 땅인 경우 아래 로직 수행
				if(map[i][j] == 1)
				{
					// BFS 함수 수행
					bfs(i, j);

					// 섬의 개수 증가
					cnt++;
				}
			}
		}

		// 섬의 개수 출력
		cout << cnt << endl;

		// 섬의 개수 초기화
		cnt = 0;
	}
}