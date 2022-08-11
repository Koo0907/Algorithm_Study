#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수들 초기화
int M = 0;
int N = 0;
int K = 0;
int cnt = 0;
int map[100][100];
vector<int> area;

void dfs(int x, int y)
{
	// 방문 처리
	map[x][y] = 1;

	// 넓이 cnt 증가
	cnt++;

	for(int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if((next_x >= 0) && (next_x < M) && (next_y >= 0) && (next_y < N))
		{
			// 아직 방문하지 않았다면 아래 로직 수행
			if(map[next_x][next_y] == 0)
			{
				// dfs 함수 수행
				dfs(next_x, next_y);
			}
		}
	}

}

int main()
{
	cin >> M >> N >> K;

	for(int i = 0; i < K; i++)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;

		// 문제 상에서의 좌표 값 입력
		cin >> x1 >> y1 >> x2 >> y2;

		// 2차원 배열에서의 좌표값으로 환산
		int mx1 = M - y1 - 1;
		int my1 = x1;
		int mx2 = M - y2;
		int my2 = x2 - 1;

		// 환산한 좌표값들을 이용해서 미리 방문 처리(넓이를 구하지 않도록)
		for(int j = mx2; j <= mx1; j++)
		{
			for(int k = my1; k <= my2; k++)
			{
				map[j][k] = 1;
			}
		}
	}

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// 아직 방문하지 않았다면 아래 로직 수행
			if(map[i][j] == 0)
			{
				// dfs 함수 호출
				dfs(i, j);

				// 계산된 넓이 값을 벡터에 추가
				area.push_back(cnt);

				// 넓이 값 초기화
				cnt = 0;
			}
		}
	}

	// 오름차순으로 정렬
	sort(area.begin(), area.end());

	cout << area.size() << endl;

	for(int i = 0; i < area.size(); i++)
	{
		cout << area[i] << " ";
	}
}