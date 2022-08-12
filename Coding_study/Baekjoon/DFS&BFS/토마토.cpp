#include<iostream>
#include<queue>

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수들 초기화
int N = 0;
int M = 0;
int res = 0;
bool already = true;
int map[1000][1000];
queue<pair<int, int>> path;

// map에 0(익지 않은 토마토)이 있는지 확인하는 함수
bool check()
{
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(map[i][j] == 0)
			{
				return true;
			}
		}
	}

	return false;
}

void bfs()
{
	while(!path.empty())
	{
		// 현재 queue에 들어있는 좌표 추출하고 삭제
		int x = path.front().first;
		int y = path.front().second;
		path.pop();

		for(int i = 0; i < 4; i++)
		{
			// 방향벡터 사용해서 다음 좌표 갱신
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// 다음 좌표들이 map 안에 있으면 아래 로직 수행
			if((next_x >= 0) && (next_x < M) && (next_y >= 0) && (next_y < N))
			{
				// 다음 좌표의 토마토가 익지 않았다면 아래 로직 수행
				if(map[next_x][next_y] == 0)
				{
					// 다음 좌표의 영역에 현재 좌표 값 +1로 갱신
					// 0이 아닌 자연수는 모두 익은 토마토라고 판단
					// 해당 좌표의 영역 값은 토마토가 익기까지 걸린 날짜에 1을 더한 값임
					map[next_x][next_y] = map[x][y] + 1;

					// queue에 다음 좌표 추가
					path.push({next_x, next_y});

					// 한번이라도 익지 않은 토마토가 익었다면, flag clear
					already = false;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// 초기 map에서 익은 토마토의 좌표를 queue에 미리 추가
			if(map[i][j] == 1)
			{
				path.push({i, j});
			}
		}
	}

	// bfs 함수 호출
	bfs();

	// map 상에 아직 0(익지 않은 토마토)이 있다면 결과값은 -1
	if(check())
	{
		res = -1;
	}
	// 한번도 익지 않은 토마토가 주위의 익은 토마토로 인해서 익은 적이 없다면 결과값은 0
	else if(already)
	{
		res = 0;
	}
	// 그 이외의 경우에 결과값은 map 상의 영역 값 중에 최대값에서 1을 빼준 값
	else
	{
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(map[i][j] > res)
				{
					res = map[i][j] - 1;
				}
			}
		}
	}

	cout << res << endl;
}