#include<iostream>
#include<cstring>

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수들 초기화
int R = 0;
int C = 0;
int max_val = 0;
char map[20][20];
bool check[26];	// 알파벳 방문 여부 확인

void dfs(int x, int y, int path)
{
	// 현재 깊이(말이 이동한 칸 수)와 최대값을 비교 및 갱신
	max_val = max(max_val, path);

	for(int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if((next_x >= 0) && (next_x < R) && (next_y >= 0) && (next_y < C))
		{
			// 다음 영역의 알파벳을 아직 방문하지 않았다면 아래 로직 수행
			if(check[map[next_x][next_y] - 'A'] == false)
			{
				// 다음 영역의 알파벳 방문 처리
				check[map[next_x][next_y] - 'A'] = true;

				// 깊이를 증가시켜 dfs 함수 호출
				dfs(next_x, next_y, path + 1);

				// 방문처리했던 알파벳 원복
				check[map[next_x][next_y] - 'A'] = false;
			}
		}
	}
}

int main()
{
	cin >> R >> C;

	for(int i = 0; i < R; i++)
	{
		cin.ignore();	// 입력 버퍼 제거
		for(int j = 0; j < C; j++)
		{
			scanf("%c",&map[i][j]);
		}
	}

	// 초기 위치 영역의 알파벳 방문 처리
	check[map[0][0] - 'A'] = true;

	// 초기 위치 부터 dfs 함수 호출
	dfs(0, 0, 1);

	cout << max_val << endl;
}