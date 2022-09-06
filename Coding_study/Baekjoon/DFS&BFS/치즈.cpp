#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

#define MAX 100

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int N = 0;
int M = 0;
int ch = 0;
int cnt = 0;

// 치즈판 배열
int map[MAX][MAX];

// 방문 처리 배열
bool visited[MAX][MAX];

// 치즈판에서의 치즈 개수를 구하는 함수
void count_cheese(void)
{
	// 전역변수 ch 초기화
	ch = 0;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// 해당 좌표의 값이 1(치즈)이면 ch 증가
			if(map[i][j] == 1)
			{
				ch++;
			}
		}
	}
}

// 치즈가 다 녹았는지 확인하는 함수
bool check(void)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// 해당 좌표의 값이 1(치즈)이면 flase 반환
			if(map[i][j] == 1)
			{
				return false;
			}
		}
	}

	return true;
}

// 공기 영역을 채우는 BFS 수행 함수
// 세번째 파라미터는 외부 공기(2), 내부 공기(3)에 따라 다르게 호출
void oxyzen_bfs(int x, int y, int cri)
{
	// 방문 처리 배열 초기화
	memset(visited, false, sizeof(visited));
	
	// 큐 선언
	queue<pair<int, int>> q;

	// 파라미터 좌표 큐에 추가
	q.push({x, y});

	// 파라미터 좌표 cri(외부 공기:2 or 내부공기:3) 갱신
	map[x][y] = cri;

	// 방문 처리
	visited[x][y] = true;

	// 큐가 빌 때까지 반복
	while(!q.empty())
	{
		// 큐에서 좌표 추출 및 삭제
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// 상,하,좌,우 방향 순회
		for(int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// 다음 좌표가 맵 상에 있는지 확인
			if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < M))
			{
				// 다음 좌표가 0(공기)이고 아직 방문하지 않았다면 아래 로직 수행
				if(map[next_x][next_y] == 0 && visited[next_x][next_y] == false)
				{
					// 다음 좌표 cri(외부 공기:2 or 내부공기:3) 갱신
					map[next_x][next_y] = cri;

					// 다음 좌표 방문 처리
					visited[next_x][next_y] = true;

					// 다음 좌표 큐에 추가
					q.push({next_x, next_y});
				}
			}
		}
	}
}

// 치즈가 녹는 과정을 수행하는 함수
void melting_cheese(void)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// 해당 좌표가 1(치즈)이면 아래 로직 수행
			if(map[i][j] == 1)
			{
				// 치즈의 위치에서 상,하,좌,우 방향 확인
				for(int k = 0; k < 4; k++)
				{
					int next_i = i + dx[k];
					int next_j = j + dy[k];

					// 다음 좌표가 맵 상에 있는지 확인
					if((next_i >= 0) && (next_i < N) && (next_j >= 0) && (next_j < M))
					{
						// 치즈 주변 좌표에 2(외부 공기)가 있다면 아래 로직 수행
						if(map[next_i][next_j] == 2)
						{
							// 현재 좌표에서의 치즈는 녹아서 0으로 갱신하고 break
							map[i][j] = 0;
							break;
						}
					}
				}
			}
		}
	}
}

// 2(외부 공기)와 3(내부 공기)로 구분해준 공기 영역을 모두 0(공기)ㄹ 원복하는 함수
void restore_oxyzen(void)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// 순회중인 좌표가 2 or 3이라면 0으로 갱신
			if((map[i][j] == 2) || (map[i][j] == 3))
			{
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	while(1)
	{
		// 현재까지의 치즈 수 계산
		count_cheese();

		// 외부 공기 구분을 위한 BFS 함수 호출
		oxyzen_bfs(0, 0, 2);

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				// 순회중인 좌표가 0이라면 내부 공기를 의미하므로 아래 로직 수행
				if(map[i][j] == 0)
				{
					// 내부 공기 구분을 위한 BFS 함수 호출
					oxyzen_bfs(i, j, 3);
				}
			}
		}

		// 치즈가 녹는 함수 호출
		melting_cheese();

		// 흐른 시간을 의미하는 cnt 증가
		cnt++;

		// 치즈가 모두 녹았는지 확인
		if(check())
		{
			break;
		}

		// 치즈맵에서의 외부 공기, 내부 공기를 모두 공기로 원복
		restore_oxyzen();
	}

	cout << cnt << endl << ch << endl;
}