#include<iostream>
#include<cstring>

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수들 초기화
int N = 0;
int normal_cnt = 0;	// 적록색약이 아닌 사람이 보는 경우
int abnormal_cnt = 0;	// 적록색약인 사람이 보는 경우
char map[100][100];	// 적록색약이 아닌 사람이 보는 맵
char ano_map[100][100];	// 적록색약인 사람이 보는 맵

// 적록색약이 아닌 사람이 보는 경우
void normal_dfs(int x, int y, char color)
{
	// 방문 표시
	map[x][y] = 'X';

	for(int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
		{
			// 현재 순회중인 구역의 색과 같다면 dfs 호출
			if(map[next_x][next_y] == color)
			{
				normal_dfs(next_x, next_y, color);
			}
		}
	}
}

// 적록색약인 사람이 보는 경우
void abnormal_dfs(int x, int y, char color)
{
	// 방문 표시
	ano_map[x][y] = 'X';

	for(int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
		{
			// 현재 순회중인 구역의 색을 판단
			if(color == 'B')
			{
				// 현재 순회중인 구역의 색이 Blue라면 다음 구역의 색도 Blue인 경우에만 dfs 호출
				if(ano_map[next_x][next_y] == color)
				{
					abnormal_dfs(next_x, next_y, color);
				}
			}
			else
			{
				// 현재 순회중인 구역의 색이 Red나 Green이라면 다음 구역의 색도 Red나 Green인 경우에만 dfs 호출
				if((ano_map[next_x][next_y] == 'R') || (ano_map[next_x][next_y] == 'G'))
				{
					abnormal_dfs(next_x, next_y, ano_map[next_x][next_y]);
				}
			}
		}
	}
}

int main()
{
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin.ignore();	// 입력 버퍼 제거
		for(int j = 0; j < N; j++)
		{
			scanf("%c", &map[i][j]);
		}
	}

	memcpy(ano_map, map, sizeof(map));

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(map[i][j] != 'X')
			{
				// 적록색약이 아닌 사람이 보는 경우
				normal_dfs(i, j, map[i][j]);

				// 구역 탐색이 한차례 끝나면 cnt 증가
				normal_cnt++;
			}

			if(ano_map[i][j] != 'X')
			{
				// 적록색약인 사람이 보는 경우
				abnormal_dfs(i, j, ano_map[i][j]);

				// 구역 탐색이 한차례 끝나면 cnt 증가
				abnormal_cnt++;
			}
		}
	}

	cout << normal_cnt << " " << abnormal_cnt;
}