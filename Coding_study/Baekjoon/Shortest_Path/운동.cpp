#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
#define MAX 401

using namespace std;

// 사용할 변수 초기화
int V = 0;
int E = 0;
int a = 0;
int b = 0;
int c = 0;
int ans = INF;

vector<pair<int, int>> vec[MAX];

// 최단거리 배열
int dis[MAX][MAX];

// 최단거리 배열 초기화
void map_clear(void)
{
	for(int i = 1; i <= V; i++)
	{
		for(int j = 1; j <= V; j++)
		{
			// 행과 열이 같은 경우에는 0으로 초기화
			if(i == j)
			{
				dis[i][j] = 0;
			}
			// 그 이이에는 INF로 초기화
			else
			{
				dis[i][j] = INF;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &V, &E);

	// 최단거리 2차원 배열 초기화
	map_clear();

	for(int i = 0; i < E; i++)
	{
		scanf("%d %d %d",&a, &b, &c);
		// 일방통행임을 주의
		dis[a][b] = c;
	}

	// 플로이드 와셜 알고리즘 수행
	for(int k = 1; k <= V; k++)
	{
		for(int i = 1; i <= V; i++)
		{
			for(int j = 1; j <= V; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	for(int i = 1; i <= V; i++)
	{
		for(int j = 1; j <= V; j++)
		{
			// 행과 열이 다른 좌표가 서로 값을 뒤집어도 경로가 있다면 i -> j -> i로 돌아오는 길이 있다는 뜻이므로 최소값 갱신 로직 수행
			if((i != j) && (dis[i][j] != INF) && (dis[j][i] != INF))
			{
				// 경로의 길이 합이 지금까지 구한 최소값보다 작다면 갱신
				if(dis[i][j] + dis[j][i] < ans)
				{
					ans = dis[i][j] + dis[j][i];
				}
			}
		}
	}

	// 경로가 있다면 최소값 출력
	if(ans != INF)
	{
		cout << ans << endl;
	}
	// 경로가 없다면 -1 출력
	else
	{
		cout << -1 << endl;
	}
}