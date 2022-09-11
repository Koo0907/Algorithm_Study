#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9   // 무한을 의미하는 값으로 10억을 설정
#define MAX 201   // 집하장의 최대수

using namespace std;

// 사용할 변수 초기화
int n = 0;
int m = 0;
int u = 0;
int v = 0;
int w = 0;

// 집하장 간의 최단거리 테이블
int dis[MAX][MAX];

// 집하장 간의 최단거리를 이동할 때 가장 먼저 거치는 집하장을 나타내는 배열
int res[MAX][MAX];

// 최단거리 테이블 초기화 함수
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
    cin >> n >> m;

    // 최단거리 테이블 초기화
    map_clear();

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;

        // 최단거리 테이블에 바로 값 갱신
        dis[u][v] = w;
        dis[v][u] = w;

        // 주어진 경로에서 가장 먼저 거치는 집하장 갱신
        res[u][v] = v;
        res[v][u] = u;
    }
    
    // 플로이드 워셜 알고리즘 수행
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                // k 집하장을 거쳐가는 경로가 더 짧은 거리라면 아래 로직 수행
                if(dis[i][j] > dis[i][k] + dis[k][j])
                {
                    // 최단거리 테이블 갱신
                    dis[i][j] = dis[i][k] + dis[k][j];

                    // 거쳐가는 집하장도 j가 아닌 k로 갱신
                    res[i][j] = res[i][k];
                }
            }
        }
    }

    // 거쳐가는 집하장 배열 출력
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            // 값이 0인 경우는 '-' 출력
            if(res[i][j] == 0)
            {
                printf("- ");
            }
            else
            {
                printf("%d ",res[i][j]);
            }
        }
        printf("\n");
    }
}