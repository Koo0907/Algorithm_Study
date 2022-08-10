#include<iostream>
#include<vector>

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N = 0;
int max_val = 0;
char map[50][50];

// 행과 열 각각을 순회하며 인자로 받은 문자가 연속으로 최대 몇개가 있는지 확인하며 최대값 갱신하는 함수
void check_max(char find)
{
	int temp_max_val = 0;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// 각 행을 순회
			if(map[i][j] == find)
			{
				temp_max_val++;
			}
			else
			{
				// 인자와 다른 문자가 나온다면 현재까지 count한 temp_max_val과 현재까지의 최대값인 max_val 비교 및 갱신
				max_val = max(max_val, temp_max_val);
				temp_max_val = 0;
			}
		}
		// 한 행에 모든 값이 인자와 같은 문자인 경우를 대비하여 한 행의 순회가 끝나면 최대값 비교 및 갱신
		max_val = max(max_val, temp_max_val);
		temp_max_val = 0;
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// 각 열을 순회
			if(map[j][i] == find)
			{
				temp_max_val++;
			}
			else
			{
				// 인자와 다른 문자가 나온다면 현재까지 count한 temp_max_val과 현재까지의 최대값인 max_val 비교 및 갱신
				max_val = max(max_val, temp_max_val);
				temp_max_val = 0;
			}
		}
		// 한 행에 모든 값이 인자와 같은 문자인 경우를 대비하여 한 행의 순회가 끝나면 최대값 비교 및 갱신
		max_val = max(max_val, temp_max_val);
		temp_max_val = 0;
	}
}

// swap 함수
void map_swap(int x, int y, int next_x, int next_y)
{
	char temp;

	temp = map[x][y];
	map[x][y] = map[next_x][next_y];
	map[next_x][next_y] = temp;
}

void change_color(int x, int y)
{
	for(int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		// 다음 위치가 맵 내부라면 아래 로직 수행
		if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
		{
			// 현재 위치의 문자와 다음 위치의 문자가 같다면 swap하지않고 다음 위치 탐색
			if(map[x][y] == map[next_x][next_y])
			{
				continue;
			}

			// 현재 위치의 문자와 순회한 다음 위치의 문자 swap
			map_swap(x, y, next_x, next_y);

			// 각각의 문자에 대해서 최대값 탐색
			check_max('C');
			check_max('P');
			check_max('Z');
			check_max('Y');

			// swap시킨 map 원복
			map_swap(x, y, next_x, next_y);

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

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// 모든 위치들을 완전탐색
			change_color(i, j);
		}
	}

	cout << max_val << endl;
}