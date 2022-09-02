#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 1e9
#define MAX 101

using namespace std;

// 사용할 변수 초기화
int n = 0;
int m = 0;
int r = 0;
int t = 0;
int a = 0;
int b = 0;
int l = 0;
int ans = 0;

// 지역의 아이템 벡터
vector<int> v;

// 최단거리 배열
int dis[MAX][MAX];

// 최단거리 배열 초기화
void map_clear(void)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			// 행과 열이 다른 영역만 INF로 초기화
			if(i != j)
			{
				dis[i][j] = INF;
			}
		}
	}
}

int main()
{
	scanf("%d %d %d",&n, &m, &r);

	for(int i = 0; i < n; i++)
	{
		scanf("%d",&t);
		v.push_back(t);
	}

	// 최단거리 배열 초기화
	map_clear();

	for(int i = 0; i < r; i++)
	{
		scanf("%d %d %d",&a, &b, &l);
		// 양뱡향임을 주의
		dis[a][b] = l;
		dis[b][a] = l;
	}

	// 플로이드 워셜 알고리즘 수행
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		// item은 얻은 아이템의 합
		// now_path는 지금까지 지나온 거리
		int item = 0;
		int now_path = 0;

		// 낙하된 위치까지 포함하여 순회
		for(int j = 1; j <= n; j++)
		{
			// now_path와 연결되어 있는 위치의 경로의 합이 m보다 작다면 아래 로직 수행
			if((dis[i][j] != INF) && (now_path + dis[i][j] <= m))
			{
				// 얻은 아이템의 합 갱신
				item += v[j - 1];
			}
		}

		// 얻은 아이템의 합 중에서의 최대값 갱신
		ans = max(ans, item);
	}

	cout << ans << endl;
}