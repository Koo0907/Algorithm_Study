#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
#define MAX 101

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int a = 0;
int b = 0;

// 최단거리 배열
int dis[MAX][MAX];

// 비교 결과 입력 벡터
vector<int> v;

// 최단거리 배열 초기화
void map_clear(void)
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			dis[i][j] = INF;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	// 최단거리 2차원 배열 초기화
	map_clear();

	for(int i = 0; i < M; i++)
	{
		scanf("%d %d",&a, &b);

		// a가 b보다 무겁다는 의미
		dis[a][b] = 1;
	}

	// 플로이드 와셜 알고리즘 수행
	for(int k = 1; k <= N; k++)
	{
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	for(int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for(int j = 1; j <= N; j++)
		{
			// 행과 열을 뒤집어봐도 값이 INF(비교한적이 없다는 의미)라면 cnt 증가
			if((dis[i][j] == INF) && (dis[j][i] == INF))
			{
				cnt++;
			}
		}

		// 행과 열이 같은 경우는 제외하기 위해 cnt - 1 삽입
		v.push_back(cnt - 1);
	}

	// 출력
	for(vector<int>::iterator itr = v.begin(); itr < v.end(); ++itr)
	{
		cout << *itr << endl;
	}
}