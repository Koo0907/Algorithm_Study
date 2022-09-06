#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 300

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int N = 0;
int M = 0;
int year = 0;
bool success = false;

// 방문 처리를 위한 배열
bool visited[MAX][MAX];

// 빙산 맵
int ice[MAX][MAX];

// 빙산이 녹고 난 뒤의 빙산 맵
int next_ice[MAX][MAX];

// DFS 함수 호출
void dfs(int a, int b)
{
	// 파라미터 좌표 값 방문 처리
	visited[a][b] = true;

	// 상,하,좌,우 네 방향 순회
	for(int i = 0; i < 4; i++)
	{
		int x = a + dx[i];
		int y = b + dy[i];

		// 다음 좌표가 맵 상에 있는지 확인
		if((x >= 0) && (x < N) && (y >= 0) && (y < M))
		{
			// 다음 좌표의 영역이 0이 아니고 방문하지 않았다면 아래 로직 수행
			if((ice[x][y] != 0) && (visited[x][y] == false))
			{
				// DFS 함수 호출
				dfs(x, y);
			}
		}
	}
}

// 빙산이 두 덩이 이상으로 분리되었는지 체크하는 함수
bool ice_check(void)
{
	// 방문 처리 배열 초기화
	memset(visited, 0, sizeof(visited));

	// 덩이 수 초기화
	int ice_cnt = 0;

	// 빙산 맵 순회
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// 순회하는 영역이 0이 아니고 방문하지 않았다면 아래 로직 수행
			if((ice[i][j] != 0) && (visited[i][j] == false))
			{
				// DFS 함수 호출
				dfs(i, j);

				// 덩이 증가
				ice_cnt++;
			}
		}
	}

	// 두 덩이 이상인 경우 아래 로직 수행
	if(ice_cnt >= 2)
	{
		// 두 덩이 이상으로 분리되었다는 뜻의 success flag set
		success = true;
		return true;
	}
	else
	{
		return false;
	}

}

// 1년 뒤의 빙산 맵 구하는 함수
void ice_melting(void)
{
	// 방문 처리 배열 초기화
	memset(visited, 0, sizeof(visited));

	// 빙산 맵 순회
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// 순회하는 영역이 0이 아니고 방문하지 않았다면 아래 로직 수행
			if((ice[i][j] != 0) && (visited[i][j] == false))
			{
				// 상,하,좌,우 순회하며 0이 있는 영역 탐색
				int zero_cnt = 0;
				for(int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];

					// 영역이 맵 상에 있는지 확인
					if((x >= 0) && (x < N) && (y >= 0) && (y < M))
					{
						// 순회하는 영역이 0인 경우 아래 로직 수행
						if(ice[x][y] == 0)
						{
							// zero_cnt 증가
							zero_cnt++;
						}
					}
				}

				// zero_cnt가 빙산의 높이보다 높다면 아래 로직 수행
				if(zero_cnt > ice[i][j])
				{
					// 다음 빙산 맵에 0으로 대입
					next_ice[i][j] = 0;
				}
				// zero_cnt가 빙산의 높이보다 낮거나 같다면 아래 로직 수행
				else
				{
					// 다음 빙산 맵에 현재 빙산 맵 - zero_cnt 대입
					next_ice[i][j] = ice[i][j] - zero_cnt;
				}

				// 현재 좌표 방문 처리
				visited[i][j] = true;
			}
		}
	}

	// 1년 증가
	year++;

	// 다음 빙산 맵의 데이터를 현재 빙산 맵으로 복사
	memcpy(ice, next_ice, sizeof(ice));
}

// 빙산이 모두 녹았는지 확인하는 함수
bool all_melt(void)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// 아직 녹지않은 빙산이 있다면 아래 로직 수행
			if(ice[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	// 현재 빙산 맵과 다음 빙산 맵 초기화
	memset(ice, 0, sizeof(ice));
	memset(next_ice, 0, sizeof(next_ice));

	scanf("%d %d",&N, &M);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%d", &ice[i][j]);
		}
	}

	while(1)
	{
		// 1년 뒤의 빙산 맵 구하기
		ice_melting();

		// 빙산들이 두 덩이로 나뉘어져 있다면 반복문 탈출
		if(ice_check())
		{
			break;
		}

		// 빙산들이 모두 녹았다면 반복문 탈출
		if(all_melt())
		{
			break;
		}
	}

	// 빙산이 두 덩이로 나눠졌는지의 유무에 따라 결과 출력
	if(success)
	{
		cout << year << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}