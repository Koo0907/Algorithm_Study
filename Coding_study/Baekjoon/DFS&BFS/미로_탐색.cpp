#include<iostream>
#include<queue>

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수들 초기화
int N = 0;
int M = 0;
int cnt = 0;
int map[100][100];
queue<pair<int, int>> path;

void bfs(int x, int y)
{
	// queue에 좌표 추가
	path.push({x, y});

	// queue가 비워질 때 까지 반복
	while(!path.empty())
	{
		// 현재 queue에 들어있는 좌표 추출하고 삭제
		x = path.front().first;
		y = path.front().second;
		path.pop();

		for(int i = 0; i < 4; i++)
		{
			// 방향벡터 사용해서 다음 좌표 갱신
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// 다음 좌표들이 map 안에 있으면 아래 로직 수행
			if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < M))
			{
				// 다음 좌표의 영역 값이 1이라면 아래 로직 수행
				if(map[next_x][next_y] == 1)
				{
					// 다음 좌표 값을 현재 좌표 값 + 1로 갱신
					map[next_x][next_y] = map[x][y] + 1;

					// queue에 다음 좌표 추가
					path.push({next_x, next_y});
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// 연속된 숫자에 대해서 1개씩만 입력 받도록 함
            // ex) 00110 -> 0, 0, 1, 1, 0
			scanf("%1d",&map[i][j]);
		}
	}

	bfs(0, 0);	// bfs 함수 호출

	cout << map[N - 1][M - 1] << endl;
}