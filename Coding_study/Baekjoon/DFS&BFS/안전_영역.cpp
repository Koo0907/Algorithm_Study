#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수들 초기화
int N = 0;
int max_high = 0;
int max_val = 0;
int area = 0;
int map[100][100];
int original_map[100][100];
queue<pair<int, int>> path;
vector<int> area_vec;

void bfs(int x, int y)
{
	// 현재 좌표 방문 표시
	map[x][y] = 0;

	// 현재 좌표 queue에 추가
	path.push({x,y});

	while(!path.empty())
	{
		// 현재 queue에 들어있는 좌표 추출하고 삭제
		x = path.front().first;
		y = path.front().second;
		path.pop();

		// 방향벡터 사용해서 다음 좌표 갱신
		for(int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// 다음 좌표들이 map 안에 있으면 아래 로직 수행
			if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
			{
				// 다음 좌표들을 아직 방문하지 않았다면 아래 로직 수행
				if(map[next_x][next_y] != 0)
				{
					// 다음 좌표 방문 표시
					map[next_x][next_y] = 0;

					// queue에 다음 좌표 추가
					path.push({next_x, next_y});
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
		for(int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);

			// map 정보 입력받으면서 가장 높은 높이의 값을 구해둠
			if(map[i][j] > max_high)
			{
				max_high = map[i][j];
			}
		}
	}

	// 원복시킬 목적의 map을 추가하여 복사
	memcpy(original_map, map, sizeof(map));

	// 0부터 가장 높은 높이까지 강수량을 조정하여 순회
	for(int tc = 0; tc <= max_high; tc++)
	{
		// 물에 잠기는 지역을 확인하기 전, 원래의 map으로 원복
		memcpy(map, original_map, sizeof(original_map));

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				// 설정한 강수량보다 낮은 높이의 영역은 물에 잠기므로 값을 0으로 수정
				if(map[i][j] <= tc)
				{
					map[i][j] = 0;
				}
			}
		}

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				// 영역의 값이 0이 아닌 경우에만 bfs 함수 호출
				if(map[i][j] != 0)
				{
					bfs(i, j);
					area++;	// 한 안전 영역의 순회가 끝나면 안전 영역 수 cnt 증가
				}
			}
		}

		// 안전 영역 수를 담는 vector에 값 추가
		area_vec.push_back(area);

		// 안전 영역 수 초기화
		area = 0;
	}
	
	// 안전 영역 수를 담은 vector에서 최대값 추출
	area = *max_element(area_vec.begin(), area_vec.end());

	cout << area << endl;
}